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
vector<pll> isi[2];
void jawab(ll x, pll z)
{
	cout << x << " " << z.fi << " " << z.se << endl;
}
int main()
{
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
    	for(ll j = 1; j <= n; j++)
    		isi[(i + j) % 2].pb(mp(i, j));
    for(ll i = 1; i <= n * n; i++)
    {
    	ll ta;
    	cin >> ta;
    	if(ta == 1)
    	{
    		if(!isi[0].empty())
    		{
    			jawab(2, isi[0].back());
    			isi[0].pop_back();
    		}
    		else
    		{
    			jawab(3, isi[1].back());
    			isi[1].pop_back();
    		}
    	}
    	else
    	if(ta == 2)
    	{
    		if(!isi[1].empty())
    		{
    			jawab(1, isi[1].back());
    			isi[1].pop_back();
    		}
    		else
    		{
    			jawab(3, isi[0].back());
    			isi[0].pop_back();
    		}
    	}
    	else
    	{
    		if(!isi[0].empty())
    		{
    			jawab(2, isi[0].back());
    			isi[0].pop_back();
    		}
    		else
    		{
    			jawab(1, isi[1].back());
    			isi[1].pop_back();
    		}
    	}
    }
}