#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
ll t, n, a, b, da, db, ma, jauh, jarb;
vector<ll> v[NN];
void dfs(ll pos, ll par, ll jar)
{
	if(ma < jar)
	{
		ma = jar;
		jauh = pos;
	}
	for(ll i = 0; i < v[pos].size(); i++)
		if(v[pos][i] != par)
			dfs(v[pos][i], pos, jar + 1);
}
void dfs2(ll pos, ll par, ll jar)
{
	if(pos == b)
		jarb = jar;
	for(ll i = 0; i < v[pos].size(); i++)
		if(v[pos][i] != par)
			dfs2(v[pos][i], pos, jar + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n >> a >> b >> da >> db;
    	for(ll i = 1; i <= n; i++)
    		v[i].clear();
    	for(ll i = 1; i < n; i++)
    	{
    		ll ta, tb;
    		cin >> ta >> tb;
    		v[ta].pb(tb);
    		v[tb].pb(ta);
    	}
    	ma = -1;
    	jauh = 0;
    	dfs(1, 1, 0);
    	dfs(jauh, jauh, 0);
    	dfs2(a, a, 0);
    	ll menang = 0;
    	// cout << ma << " " << jarb << "\n";
    	if(da * 2 >= db)menang = 1;
    	else if(jarb <= da) menang = 1;
    	else 
    	{
    		if((da * 2) < ma)menang = 0;
    		else menang = 1;
    	}
    	if(menang)cout << "Alice\n";
    	else cout << "Bob\n";
    }
}