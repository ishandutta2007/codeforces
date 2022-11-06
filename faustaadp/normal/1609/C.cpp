#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 1e6 + 5;
const int mo = 1e9 + 7;
const ll inf = 1e18 + 1;
ll p[NN], n, a[NN],L[NN], R[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    p[1] = 1;
    for(ll i = 2; i <= 1000; i++)
    	if(!p[i])
    		for(ll j = i * i; j <= 1000000; j += i)
    			p[j] = 1;
    ll t;
    cin >> t;
    while(t--)
    {
    	ll n, e, has = 0;
    	cin >> n >> e;
    	for(ll i = 1; i <= n; i++)
    		L[i] = 0;
    	for(ll i = 1; i <= n; i++)
    		R[i] = 0;
    	for(ll i = 1; i <= n; i++)
    		cin >> a[i];
    	for(ll i = 1; i <= e; i++)
    	{
    		vector<ll> z;
    		ll kir = 0;
    		for(ll j = i; j <= n; j += e)
    		{
    			// cout << j << " " << kir << "\n";
    			z.pb(j);
    			if(a[j] == 1)
    				kir++;
    			else
    			{
    				if(!p[a[j]])
    					L[j] = kir;
    				kir = 0;
    			}
    		}
    		reverse(z.begin(), z.end());
    		ll kan = 0;
    		for(auto j : z)
    		{
    			if(a[j] == 1)
    				kan++;
    			else
    			{
    				if(!p[a[j]])
    					R[j] = kan;
    				kan = 0;
    			}
    		}
    	}
    	for(ll i = 1; i <= n; i++)
    	{
    		has += (L[i] + 1) * (R[i] + 1) - 1;
    		// cout << i << " " << L[i] << " " << R[i] << "\n";
    	}
    	cout << has << "\n";
    }
}