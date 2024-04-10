#include <cstdio>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MV = 1e5+10;
const int MM = 1e5+10;
const int MG = 450;
const int INF = 0x3f3f3f3f;

struct DSU
{
	int p[MM], t[MM];
	char r[MM];
	void init(int M)
	{
		memset(p, -1, M*sizeof*p);
		memset(r, 0, M*sizeof*r);
		std::iota(t, t+M, 0);
	}
	int find(int v) {return ~p[v]?p[v]=find(p[v]):v;}
	bool merge(int a, int b)
	{
		a=find(a), b=find(b);
		if(a==b) return 0;
		t[a]=t[b];
		if(r[a]<r[b]) std::swap(a,b);
		r[a]+=r[a]==r[b];
		p[a]=b;
	}
} dsu;

int M, v[MM], maxv[MM], dp[MM][2], ub[MV];
bool ok[MM];

int solve()
{
	scanf("%d", &M);
	for(int i=0;i<M;++i)
	{
		scanf("%d", v+i);
		assert(v[i]>0); // data fixed?
	}
	for(int i=0,j=0;i<MV;++i)
	{
		while(j<M && v[j]==i) ++j;
		ub[i]=j;
	}
	memset(maxv, 0x3f, sizeof maxv); // inf
	std::fill(ok, ok+M, 1);
	int f=0;
	bool c=0;
	for(int i=0;f==i;++i, c^=1)
	{
		dsu.init(M+1);
		for(int j=M-1;j>=0;--j)
		{
			if(ok[j] &= (maxv[j] > 0))
					ckmax(f, i+1);
			dp[j][c]=v[j]*2-maxv[j];
			ckmax(dp[j][c], 0);
			ckmin(dp[j][c], v[j]-1);
			if(i)
			{
				ckmax(dp[j][c], dp[j][!c]);
				int x=ub[dp[j][!c]], y=ub[dp[j][c]];
				//update maxv[i][(x,y)]
				for(int g=dsu.find(x),t;(t=dsu.t[g])<y;)
				{
					maxv[t]=v[j];
					dsu.merge(g, t+1);
					g=dsu.find(g);
				}
			}
		}
		memset(maxv, 0, sizeof maxv);
	}
	//printf("GRUNDY: %d\n", f);
	return f;
}

int main()
{
	int N, f=0;
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		f ^= solve();
	if(f)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}