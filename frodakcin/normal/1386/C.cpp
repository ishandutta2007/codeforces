#include <cstdio>
#include <cassert>
#include <algorithm>

const int MN = 2e5+10;
const int INF = 1e6;

struct DSU
{
	public:
		int p[MN], r[MN], c[MN], *t[MN*40], v[MN*40], R, tmp;
		void set(int *n, int nv)
		{
			if(*n==nv) return;
			t[R]=n, v[R]=*n;
			*n=nv, ++R;
		}
		int find(int n)
		{
			if(!p[n]) return tmp=0, n;
			set(p+n, find(p[n]));
			set(c+n, tmp^=c[n]);
			return p[n];
		}
		bool ok(int a, int b)
		{
			return find(a)!=find(b) || c[a]!=c[b];
		}
		bool merge(int a, int b)
		{
			int val=0;
			a=find(a), val^=tmp, b=find(b), val^=tmp;
			if(a==b) return 0;
			if(r[a]<r[b]) std::swap(a,b);
			if(r[a]==r[b]) set(r+a, r[a]+1);
			set(p+b, a);
			set(c+b, 1^val);
			return 1;
		}
		void rollback(int _R)
		{
			for(;R>_R;)
				--R, *t[R]=v[R];
		}
} dsu;

int N, M, Q, u[MN], v[MN], ans[MN], ml=-1;

void dqdp(int i, int j, int x, int y)//[i, j) [x, y)
{
	int R = dsu.R, z=y;
	if(j-i==1)
	{
		for(;z>x && dsu.ok(u[z-1], v[z-1]);--z)
			dsu.merge(u[z-1], v[z-1]);
		//assert(z == 0 || !dsu.ok(u[z-1], v[z-1]));
		ans[i]=z;
		dsu.rollback(R);
		return;
	}
	int m=i+(j-i>>1);
	//1) push left, push right
	//2) rollback right, recursive right
	//3) rollback left, push right, recursive left
	//4) rollback right, exit
	for(int k=i;k<m;++k)
		dsu.merge(u[k], v[k]);
	int R2 = dsu.R;
	for(;z>x && dsu.ok(u[z-1], v[z-1]);--z)
		dsu.merge(u[z-1], v[z-1]);
	dsu.rollback(R2);
	dqdp(m, j, z, y);
	dsu.rollback(R);
	for(int k=y-1;k>=z;--k)
		dsu.merge(u[k], v[k]);
	dqdp(i, m, x, z);
	dsu.rollback(R);
}

int main()
{
	scanf("%d%d%d", &N, &M, &Q);
	for(int i=0;i<M;++i)
	{
		scanf("%d%d", u+i, v+i);
		if(!~ml)
		{
			if(dsu.ok(u[i], v[i]))
				dsu.merge(u[i], v[i]);
			else
				ml=i+1;
		}
	}
	//printf("%d\n", ml);
	if(!~ml)
	{
		for(int i=0;i<Q;++i) printf("NO\n");
		return 0;
	}
	ans[ml]=INF;
	dsu.rollback(0);
	dqdp(0, ml, 0, M);
	//for(int i=0;i<ml;++i) printf("%d\n", ans[i]);
	for(int i=0,l,r;i<Q;++i)
	{
		scanf("%d%d", &l, &r), --l, r;
		if(l >= ml || r < ans[l])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}