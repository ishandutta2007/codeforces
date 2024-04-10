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
ll n, m, p[NN], sz[NN];
ll car(ll pos)
{
	if(pos == p[pos])
		return pos;
	return p[pos] = car(p[pos]);
}//
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
    {
    	p[i] = i;
    	sz[i] = 1;
    }
    ll mx = 1;
    for(ll i = 1; i <= m; i++)
    {
    	vector<ll> isi;
    	ll ta, tb;
    	cin >> ta >> tb;
    	if(car(ta) != car(tb))
    	{
    		sz[car(tb)] += sz[car(ta)];
    		p[car(ta)] = car(tb);
    	}
    	else
    		mx++;
    	ll hz = 0;
    	for(ll i = 1; i <= n; i++)
    		if(i == car(i))
    			isi.pb(sz[car(i)]);
    		// hz = max(hz, sz[car(i)]);
    	sort(isi.begin(), isi.end());
    	reverse(isi.begin(), isi.end());
    	for(ll i = 0; i < min(mx, (ll)isi.size()); i++)
    		hz += isi[i];
    	cout << hz - 1 << "\n";
    }
}