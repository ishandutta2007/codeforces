#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t, n, k, a[101010], x[101010], p[101010], s[101010];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
    	ll ada = 0;
    	cin >> n >> k;
    	for(ll i = 1; i <= n; i++)
    	{
    		cin >> a[i];
    		if(a[i] == k)
    			ada = 1;
    		if(a[i] >= k)
    			x[i] = 1;
    		else
    			x[i] = -1;
    	}
    	ll ya = 0;
    	if(n == 1 && a[1] == k)
    		ya = 1;
    	priority_queue<pair<ll, ll > > pq1, pq2;
    	for(ll i = 1; i <= n; i++)
    	{
    		p[i] = p[i - 1] + x[i];
    		pq1.push(mp(p[i], i));
    	}
    	for(ll i = 1; i < n; i++)
    	{
    		while(pq1.top().se <= i)
    			pq1.pop();
    		ll tmp = p[pq1.top().se] - p[i];
    		// cout << i << " " << pq1.top().se << " " << tmp << "\n";
    		if(tmp >= 0 && a[i] >= k)
    			ya = 1;
    	}
    	s[n + 1] = 0;
    	for(ll i = n; i >= 1; i--)
    	{
    		s[i] = s[i + 1] + x[i];
    		pq2.push(mp(s[i], i));
    	}
    	for(ll i = n; i > 1; i--)
    	{
    		while(pq2.top().se >= i)
    			pq2.pop();
    		ll tmp = p[i - 1] - p[pq2.top().se - 1];
    		if(tmp >= 0 && a[i] >= k)
    			ya = 1;
    	}
    	if(!ada)
    		ya = 0;
    	if(ya)
    		cout << "yes\n";
    	else
    		cout << "no\n";
    }
}