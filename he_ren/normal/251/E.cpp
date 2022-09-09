#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

vector<int> g[MAXN];
int deg[MAXN];

int siz[MAXN];
bool has3[MAXN];
void dfs_tree(int u)
{
	siz[u] = 1;
	has3[u] = deg[u] == 3;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		g[v].erase(find(g[v].begin(), g[v].end(), u));
		dfs_tree(v);
		siz[u] += siz[v];
		has3[u] |= has3[v];
	}
}

int f[MAXN];
int get_res(int,int);
int get_res(int u)
{
	if(~f[u]) return f[u];
	if(siz[u] & 1) return f[u] = 0;
	int &res = f[u] = 0;
	if(deg[u] == 3)
	{
		int v1 = g[u][0], v2 = g[u][1];
		while(deg[v1] == 2 && deg[v2] == 2) v1 = g[v1][0], v2 = g[v2][0];
		if(deg[v1] < deg[v2]) swap(v1, v2);
		if(deg[v1] == 3) return res = deg[v2] == 1? get_res(v1): 0;
		
		res = get_res(v1);
		if(deg[g[v1][0]] == 1) add_mod(res, 1);
		else if(deg[g[v1][0]] == 2) add_mod(res, get_res(g[g[v1][0]][0]));
		return res;
	}
	
	if(!has3[u]) return res = siz[u] >> 1;
	
	int to = u, len = 1;
	while(deg[to] == 2) to = g[to][0], ++len;
	int v1 = g[to][0], v2 = g[to][1];
	
	if((len-1)%2 == 0) res = get_res(to);
	for(int T=1; T<=2; ++T, swap(v1,v2))
	{
		if(!has3[v1])
		{
			if(siz[v1] > 1 && siz[v1] <= len && (len - siz[v1]) % 2 == 0)
				add_mod(res, get_res(v2));
			if(siz[v1] <= len - 2 && (len - 2 - siz[v1]) % 2 == 0)
				add_mod(res, get_res(v2));
		}
		if(deg[v1] == 3)
		{
			int w1 = g[v1][0], w2 = g[v1][1];
			for(int T2=1; T2<=2; ++T2, swap(w1,w2)) if(!has3[w1])
				if(siz[w1] + 1 <= len && (len - siz[w1] - 1) % 2 == 0)
					add_mod(res, get_res(v2, w2));
		}
	}
	return res;
}

int get_res(int u1,int u2)
{
	if(!u1 || !u2) return get_res(u1 | u2);
	if((siz[u1] + siz[u2]) & 1) return 0;
	while(deg[u1] == 2 && deg[u2] == 2)
		u1 = g[u1][0], u2 = g[u2][0];
	if(deg[u1] > 2 || deg[u2] > 2) return 0;
	if(deg[u1] == 1 && deg[u2] == 1) return 1;
	return get_res(deg[u1] == 2? g[u1][0]: g[u2][0]);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	n <<= 1;
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); ++deg[u];
		g[v].push_back(u); ++deg[v];
	}
	if(n == 2) return printf("2"), 0;
	
	int cnt3 = 0;
	for(int i=1; i<=n; ++i)
	{
		if(deg[i] > 3) return printf("0"), 0;
		if(deg[i] == 3) ++cnt3;
	}
	if(cnt3 == 0)
	{
		n >>= 1;
		printf("%lld",(2ll * n * (n-1) + 4) %mod);
		return 0;
	}
	
	int rt;
	for(int i=1; i<=n; ++i)
		if(deg[i] == 3){ rt = i; break;}
	dfs_tree(rt);
	
	memset(f,-1,sizeof(f));
	
	int ans = 0;
	sort(g[rt].begin(), g[rt].end());
	do
	{
		vector<int> vec = g[g[rt][2]];
		if(!vec.size())
		{
			ans = (ans + (ll)get_res(g[rt][0]) * get_res(g[rt][1])) %mod;
			continue;
		}
		
		vec.resize(2);
		for(int T=1; T<=2; ++T, swap(vec[0], vec[1]))
			ans = (ans + (ll)get_res(g[rt][0], vec[0]) * get_res(g[rt][1], vec[1])) %mod;
	}while(next_permutation(g[rt].begin(), g[rt].end()));
	
	printf("%d",(ans * 2) %mod);
	return 0;
}