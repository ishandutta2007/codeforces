#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 2e5 + 5;
ll t, n, a[NN], D[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n;
    	ll sum = 0;
    	for(ll i = 1; i <= n; i++)
    	{
    		cin >> a[i];
    		D[i] = 0;
    		sum += a[i];
    	}
    	for(ll i = 1; i < n; i++)
    	{
    		ll ta, tb;
    		cin >> ta >> tb;
    		D[ta]++;
    		D[tb]++;
    	}
    	vector<ll> isi;
    	priority_queue<pair<ll, ll> > pq;
    	for(ll i = 1; i <= n; i++)
    		if(D[i] > 1)
	    		pq.push(mp(a[i], i));
    	cout << sum << " ";
    	for(ll i = 0; i < n - 2; i++)
    	{
    		ll idx = pq.top().se;
    		sum += pq.top().fi;
    		pq.pop();
    		cout << sum << " ";
    		D[idx]--;
    		if(D[idx] > 1)
    			pq.push(mp(a[idx], idx));
    	}
    	cout << "\n";
    }
}