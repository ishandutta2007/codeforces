#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 5e5 + 5;
const ll mo = 1e9 + 7;
ll t, n, a[NN], x[NN], du[NN]; 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	ll has = 0;
    	du[0] = 1;
    	cin >> n;
    	for(ll i = 1; i < 60; i++)
    		du[i] = (du[i - 1] * 2) % mo; 
    	for(ll i = 0; i < 60; i++)
    		x[i] = 0;
    	for(ll i = 1; i <= n; i++)
    	{
    		cin >> a[i];
    		for(ll j = 0; j < 60; j++)
    			if(a[i] & (1LL << j))
    				x[j]++;
    	}
    	for(ll i = 1; i <= n; i++)
    	{
    		ll h1 = 0, h2 = 0;
    		for(ll j = 0; j < 60; j++)
    			if(a[i] & (1LL << j))
    			{
    				h1 = (h1 + x[j] * du[j]) % mo;
    				h2 = (h2 + n * du[j]) % mo;
    			}
    			else
    			{
    				h2 = (h2 + x[j] * du[j]) % mo;
    			}
    		has = (has + h1 * h2) % mo;
    	}
    	cout << has << "\n";
    }
}