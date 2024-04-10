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
ll t, n, m, x, jum[NN], a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n >> m >> x;
    	priority_queue<pll> pq;
    	for(ll i = 1; i <= m; i++)
    	{
    		pq.push(mp(0, i));
    		jum[i] = 0;
    	}
    	cout << "YES\n";
    	for(ll i = 1; i <= n; i++)
    	{
    		cin >> a[i];
    		ll idx = pq.top().se;
    		pq.pop();
    		cout << idx << " ";
    		jum[idx] += a[i];
    		// jaw[i] = idx;
    		pq.push(mp(-jum[idx], idx));
    	}
    	cout << "\n";
    }
}