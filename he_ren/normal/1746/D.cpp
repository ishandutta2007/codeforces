#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int s[MAXN];
vector<int> g[MAXN];

map<int,ll> mem[MAXN];
ll dp(int u,int k)
{
	if(!g[u].size()) return (ll)k * s[u];
	if(mem[u].count(k)) return mem[u][k];
	
	int tot = (int)g[u].size();
	ll res = (ll)k * s[u];
	
	int l = k / tot;
	int r = (k + tot - 1) / tot;
	int need = k % tot;
	
	vector<ll> delta;
	for(int v: g[u])
	{
		ll x = dp(v, l), y = dp(v, r);
		if(x > y) swap(x, y);
		res += x;
		delta.emplace_back(y - x);
	}
	
	sort(delta.begin(), delta.end(), greater<ll>());
	for(int i=0; i<need; ++i)
		res += delta[i];
	return mem[u][k] = res;
}

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
	{
		g[i].clear();
		mem[i].clear();
	}
	for(int i=2; i<=n; ++i)
	{
		int j;
		scanf("%d",&j);
		g[j].emplace_back(i);
	}
	for(int i=1; i<=n; ++i)
		scanf("%d",&s[i]);
	
	printf("%lld\n",dp(1,d));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}