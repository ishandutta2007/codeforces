#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
const ld eps = 1e-9;
ll t, n, k;
vector<ll> v[NN], isi;
ll mx[NN], nxx[NN], sisa;
void dfs(ll pos, ll par, ll dpt)
{
	mx[pos] = dpt;
	nxx[pos] = pos;
	for(auto nx : v[pos])
	{
		if(nx == par)continue;
		dfs(nx, pos, dpt + 1);
		mx[pos] = max(mx[pos], mx[nx]);
		if(mx[pos] == mx[nx])
			nxx[pos] = nx;
	}
	// cout << pos << " " << mx[pos] << "\n";
}
void dfs2(ll pos, ll par, ll gab)
{
	// cout << pos << " " << par << " " << sisa << "@\n";
	if(pos != par)
		sisa--;
	ll ada = 0;
	for(auto nx : v[pos])
	{
		if(nx == par)continue;
		if(nx == gab)continue;
		if(sisa == 0)break;
		ada = 1;
		isi.pb(nx);
		dfs2(nx, pos, gab);
		isi.pb(pos);
	}
	// if(!ada)return 
	// cout << pos << " " << mx[pos] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n >> k;
    	for(ll i = 1; i <= n; i++)
    		v[i].clear();
    	for(ll i = 2; i <= n; i++)
    	{
    		ll ta;
    		cin >> ta;
    		v[ta].pb(i);
    	}
    	dfs(1, 1, 0);
    	isi.clear();
    	k--;
    	ll h1 = 0;
    	// cout << mx[1] << "_\n";
    	if(k <= mx[1])
    	{
    		h1 = k;
    		ll pos = 1;
    		for(ll i = 1; i <= k + 1; i++)
    		{
    			isi.pb(pos);
    			pos = nxx[pos];
    		}
    	}
    	else
    	{
    		h1 = k * 2 - mx[1];
    		sisa = k - mx[1];
    		// cout
    		ll pos = 1;
    		for(ll i = 1; i <= mx[1] + 1; i++)
    		{
    			isi.pb(pos);
    			dfs2(pos, pos, nxx[pos]);
    			pos = nxx[pos];
    		}
    		// cout << sisa << "_\n";
    	}
    	cout << isi.size() - 1 << "\n";
    	for(ll i = 0; i < isi.size(); i++)
    	{
    		if(i > 0)
    			cout << " ";
    		cout << isi[i];
    	}
    	cout << "\n";
    }
}