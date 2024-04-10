#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 40 + 5;
const int ALL = (1<<20) + 5;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

vector<int> g[MAXN];

vector<int> nodes;
int clr[MAXN];
bool isbin;
void dfs_clr(int u)
{
	nodes.push_back(u);
	for(int v: g[u])
	{
		if(clr[v] == -1)
		{
			clr[v] = clr[u] ^ 1;
			dfs_clr(v);
		}
		else if(clr[v] != (clr[u] ^ 1))
			isbin = 0;
	}
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	vector<ll> dp(8);
	dp[0] = 1;
	auto combine = [&] (const vector<ll> &A,const vector<ll> &B)
	{
		assert(A.size() == 8);
		assert(B.size() == 8);
		vector<ll> res(8);
		for(int i=0; i<8; ++i)
			for(int j=0; j<8; ++j)
				res[i|j] += A[i] * B[j];
		return res;
	};
	
	memset(clr, -1, sizeof(clr));
	for(int rt=1; rt<=n; ++rt) if(clr[rt] == -1)
	{
		nodes.clear(); isbin = 1;
		clr[rt] = 0;
		dfs_clr(rt);
		
		vector<ll> curdp(8);
		if(nodes.size() == 1)
		{
			curdp[0] = 2;
			dp = combine(dp, curdp);
			continue;
		}
		
		int d = (int)nodes.size();
		static int id[MAXN];
		memset(id, -1, sizeof(id));
		for(int i=1; i<=d; ++i)
			id[nodes[i-1]] = i;
		
		static ll gmask[MAXN];
		memset(gmask, 0, sizeof(gmask));
		for(int u: nodes)
			for(int v: g[u]) if(id[v] != -1)
				gmask[id[u]] |= 1ll << (id[v] - 1);
		
		auto halfsearch = [&] (int l,int r,function<void(ll,ll)> func)
		{
			int len = r-l+1, all = (1<<len) - 1;
			for(int mask=0; mask<=all; ++mask)
			{
				ll fob = 0;
				for(int i=0; i<len; ++i)
					if(bdig(mask,i)) fob |= gmask[i+l];
				if(((ll)mask << (l-1)) & fob) continue;
				func((ll)mask << (l-1), fob);
			}
		};
		
		int half = d / 2, all = (1<<half) - 1;
		
		static int bak[ALL];
		memset(bak, 0, (all+1)<<2);
		vector< pair<int,ll> > vec;
		halfsearch(half+1, d, [&] (ll, ll fob){
			++bak[~fob & all];
		});
		for(int i=1; i<=all; i<<=1)
			for(int mask=0; mask<=all; ++mask)
				if(mask & i) bak[mask ^ i] += bak[mask];
		
		ll cnt = 0;
		halfsearch(1, half, [&] (ll mask, ll){
			cnt += bak[mask & all];
		});
		
		curdp[1] = curdp[4] = 1;
		curdp[2] = isbin * 2;
		curdp[1+2] = curdp[4+2] = cnt - isbin * 2 - 1;
		curdp[1+2+4] = 1ll << d;
		for(int i=0; i<7; ++i)
			curdp[7] -= curdp[i];
		dp = combine(dp, curdp);
	}
	
	printf("%lld",dp[7]);
	return 0;
}