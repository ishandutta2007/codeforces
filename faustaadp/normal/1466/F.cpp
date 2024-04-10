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
ll t, n, m, p[NN];
ll car(ll pos)
{
	if(pos == p[pos])
		return pos;
	else
		return p[pos] = car(p[pos]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // cin >> t;
    t = 1;
    while(t--)
    {
    	ll h1 = 1, h2 = 0;
    	vector<ll> isi;
    	cin >> n >> m;
    	for(ll i = 1; i <= m + 1; i++)
    		p[i] = i;
    	for(ll i = 1; i <= n; i++)
    	{
    		ll ban;
    		cin >> ban;
    		ll ta, tb = m + 1;
    		cin >> ta;
    		if(ban == 2)
    			cin >> tb;
    		if(car(ta) != car(tb))
    		{
    			p[car(ta)] = car(tb);
    			isi.pb(i);
    			h1 = (h1 * 2LL) % mo;
    			h2++;
    		}
    	}
    	cout << h1 << " " << h2 << "\n";
    	for(ll i = 0; i < h2; i++)
    		cout << isi[i] << " ";
    	cout << "\n";
    }
}