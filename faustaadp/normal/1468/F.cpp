#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n, X[NN], Y[NN];
map<pair<ll, ll>, ll> me;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	ll has = 0;
    	me.clear();
    	cin >> n;
    	for(ll i = 1; i <= n; i++)
    	{
    		ll ta, tb;
    		cin >> ta >> tb;
    		ll x, y;
    		cin >> x >> y;
    		ta -= x;
    		tb -= y;
    		ll f = __gcd(abs(ta), abs(tb));
    		ta /= f;
    		tb /= f;
    		X[i] = ta;
    		Y[i] = tb;
    		me[mp(X[i], Y[i])]++;
    		// cout << ta << " " << tb << "@\n";
    	}
    	for(ll i = 1; i <= n; i++)
    	{
    		// cout << -X[i] << " " << -Y[i] << " " << me[mp(-X[i], -Y[i])] << "_\n";
    		has += me[mp(-X[i], -Y[i])];
    	}
    	has /= 2;
    	cout << has << "\n";
    }
}