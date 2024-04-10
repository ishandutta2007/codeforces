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
ll t, a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	ll n;
    	cin >> n;
    	ll z = 0;
    	for(ll i = 1; i <= n; i++)
    	{
    		cin >> a[i];
    		while(a[i] % 2 == 0)
    		{
    			z++;
    			a[i] /= 2LL;
    		}
    	}
    	sort(a + 1, a + 1 + n);
    	while(z--)
    		a[n] *= 2LL;
    	ll has = 0;
    	for(ll i = 1; i <= n; i++)
    		has += a[i];
    	cout << has << "\n";
    }
}