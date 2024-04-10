#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll n;
vector<ll> isi[202020];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n;
    for(ll j = 1; j <= n; j++)
    {
    	ll ta;
    	cin >> ta;
    	ll K = sqrt(ta);
    	vector<ll> v;
    	for(ll i = 1; i <= K; i++)
    	{
    		if(ta % i == 0)
    		{
    			v.pb(i);
    			if(i != (ta / i))
 		   			v.pb(ta / i);
    		}
    	}
    	ll sz = v.size();
    	sort(v.begin(), v.end());
    	for(ll i = 1; i < sz; i++)
    	{
    		if(ta % v[i] == 0)
    		{		
    			ll hz = 1;
	    		while(ta % v[i] == 0)
	    		{
	    			hz *= v[i];
	    			ta /= v[i];
	    		}
	    		isi[v[i]].pb(hz);
	    		// cout 
	    		// cout << j << " " << v[i] << " " <<hz << "\n";
    		}
    	}
    }
    ll has = 1;
    for(ll i = 1; i <= 200000; i++)
    {
    	if(!isi[i].empty())
    	{
    		sort(isi[i].begin(), isi[i].end());
    		reverse(isi[i].begin(), isi[i].end());
    		if(isi[i].size() >= (n - 1))
    		{
    			// cout << i << " " << isi[i][n-2] << "\n";
    			has *= isi[i][n - 2];
    		}
    	}
    }
    cout << has << "\n";
}