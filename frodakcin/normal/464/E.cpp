#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

const int MN = 1e5+10, MV = 17, MX = 8e6;//bump up bounds
const int L=3, base[]={2,3,5}, mod[]={(int)1e9+7, (int)1e9+9, 998244353};
using ll = long long;

int pw[L][MV+1], X, N, M, S, T, par[MN], p[MN], r[MN];
bool vis[MN];
int find(int n) {return p[n]?p[n]=find(p[n]):n;}
bool merge(int a, int b)
{
	a=find(a),b=find(b);
	if(a==b)return 0;
	if(r[a]<r[b]) std::swap(a,b);
	r[a]+=r[a]==r[b],r[b]=-1,p[b]=a;
	return 1;
}
std::vector<int> f;
struct hash
{
public:
	int v[L];
	hash(int a=0)
	{
		for(int i=0;i<L;++i) v[i]=a;
	}
	bool operator == (const hash& o) const
	{
		for(int i=0;i<L;++i) if(v[i]!=o.v[i]) return 0;
		return 1;
	}
	bool operator != (const hash&o) const
	{
		for(int i=0;i<L;++i) if(v[i]!=o.v[i]) return 1;
		return 0;
	}
	int& operator [] (int n) {return v[n];}
	int operator [] (int n) const {return v[n];}
	friend hash merge(const hash& a, const hash& b, int l)
	{
		hash f;
		for(int i=0;i<L;++i)
			f.v[i] = (int)((a.v[i]+(ll)b.v[i]*pw[i][l])%mod[i]);
		return f;
	}
};
struct stn//SegTreeNode
{
public:
	stn *c[2];
	hash v;
	void upd(int t)
	{
		v=merge(c[0]->v, c[1]->v, t-1);
	}
} v[2][MV+1], pool[MX];
bool cmp(stn *a, stn *b, int t)//a<b
{
	if(a->v==b->v) return 0;
	if(t)
	{
		if(a->c[1]->v != b->c[1]->v)
			return cmp(a->c[1], b->c[1], t-1);
		return cmp(a->c[0], b->c[0], t-1);
	}
	assert(a->v == v[0][0].v ^ b->v == v[0][0].v);
	assert(a->v == v[1][0].v ^ b->v == v[1][0].v);
	return a->v == v[0][0].v;//a==0 => b==1, and vice versa
}
stn *nn()
{
	if(X>=MX)
	{
		printf("BAD!\n");
		exit(0);
	}
	assert(X<MX);
	return pool+X++;
}
stn *nn(stn *n)
{
	stn *f=nn();
	*f=*n;
	return f;
}
stn *upd(stn *n, int t, int ql, int qr, bool q)
{
	if(ql <= 0 && 1<<t <= qr)
		return v[q]+t;
	else
	{
		n=nn(n);
		if(ql<1<<t-1) n->c[0]=upd(n->c[0], t-1, ql, qr, q);
		if(1<<t-1<qr) n->c[1]=upd(n->c[1], t-1, ql-(1<<t-1), qr-(1<<t-1), q);
		n->upd(t);
		return n;
	}
}
int qry(stn *n, int t, int ql)//leftmost zero in range [ql, INF)
{
	//printf("%d: ", n->v[0]);
	if(n->v == v[1][t].v) return -1;
	//printf("GOOD\n");
	if(t)
	{
		int f=-1;
		if(ql<1<<t-1) f=qry(n->c[0], t-1, ql);
		if(!~f)
		{
			f=qry(n->c[1], t-1, ql-(1<<t-1));
			if(~f)
				f+=(1<<t-1);
		}
		return f;
	}
	return 0;
}
struct qn//pq node
{
	int n;
	stn *v;
	bool operator > (const qn& o) const
	{
		return cmp(o.v, v, MV);//a>b is equivalent to b<a
	}
};

struct edge
{
public:
	int n,w;
};
std::vector<edge> a[MN];
std::priority_queue<qn, std::vector<qn>, std::greater<qn> > q;
stn* d[MN];
int main()
{
	for(int i=0;i<L;++i)
	{
		pw[i][0]=base[i];
		for(int j=0;j<MV;++j)
			pw[i][j+1]=(int)((ll)pw[i][j]*pw[i][j]%mod[i]);
	}
	v[0][0] = {nullptr, nullptr, hash(0)};
	v[1][0] = {nullptr, nullptr, hash(1)};
	for(int i=0;i<MV;++i)
		for(int j=0;j<2;++j)
		{
			v[j][i+1].c[0]=v[j][i+1].c[1]=v[j]+i;
			v[j][i+1].upd(i+1);
		}
	scanf("%d%d", &N, &M);
	for(int x,y,z,i=0;i<M;++i)
		scanf("%d%d%d", &x, &y, &z), a[x].push_back({y,z}), a[y].push_back({x,z}), merge(x,y);
	scanf("%d%d", &S, &T);
	if(find(S) != find(T)) return printf("-1\n"), 0;
	for(int i=1;i<=N;++i) d[i]=v[1]+MV;
	d[S]=v[0]+MV;
	q.push({S, d[S]});
	for(;!q.empty();)
	{
		int n=q.top().n; q.pop();
		if(vis[n]) continue;
		vis[n]=1;
		//printf("%d %d\n", n, d[n]->v[0]);
		for(auto x:a[n])
		{
			if(vis[x.n]) continue;
			int w=x.w, z=qry(d[n], MV, w);
			//printf("%d %d %d\n", d[n]->v[0], w, z);
			assert(z>=w);
			stn *nd=upd(d[n], MV, z, z+1, 1);
			if(w<z) nd=upd(nd, MV, w, z, 0);
			if(cmp(nd, d[x.n], MV))
				d[x.n]=nd, q.push({x.n, d[x.n]}), par[x.n]=n;
		}
	}
	printf("%d\n", d[T]->v[0]);//hash 0 conveniently corresponds to binary mod 1e9+7
	for(int n=T;n!=S;n=par[n]) f.push_back(n);
	f.push_back(S);
	printf("%d\n", f.size());
	std::reverse(f.begin(), f.end());
	for(int i=0;i<f.size();++i) printf("%d%c", f[i], " \n"[i+1==f.size()]);
	return 0;
}