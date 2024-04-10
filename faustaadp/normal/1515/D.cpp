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
ll t, n, L, R, x[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n >> L >> R;
    	ll sum = 0, has = 0;
    	for(ll i = 1; i <= n; i++)
    		x[i] = 0;
    	for(ll i = 1; i <= L; i++)
    	{
    		ll ta;
    		cin >> ta;
    		x[ta]++;
    		sum++;
    	}
    	for(ll i = 1; i <= R; i++)
    	{
    		ll ta;
    		cin >> ta;
    		x[ta]--;
    		sum--;
    	}
    	ll hz = 0;
    	for(ll i = 1; i <= n; i++)
    	{
    		if(sum > 0 && x[i] > 0)
    		{
    			while(x[i] >= 2 && sum > 0)
    			{
    				sum -= 2;
    				x[i] -= 2;
    				has++;
    			}
    		}
    		if(sum < 0 && x[i] < 0)
    		{
    			while(x[i] <= -2 && sum < 0)
    			{
    				sum += 2;
    				x[i] += 2;
    				has++;
    			}
    		}
    		// cout << i << " " << x[i] << "\n";
    		hz += abs(x[i]);
    	}
    	has += hz / 2;
    	has += abs(sum) / 2;
    	cout << has << "\n";
    }
}