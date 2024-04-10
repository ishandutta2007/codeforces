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
ll t, n, x, a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n >> x;
    	ll sum = 0, idx = -1;
    	for(ll i = 1; i <= n; i++)
    	{
    		cin >> a[i];
    		sum += a[i];
    		if(sum == x)
    			idx = i;
    	}
    	if(idx == n)
    		cout << "NO\n";
    	else
    	{
    		swap(a[idx], a[idx + 1]);
    		cout << "YES\n";
    		for(ll i = 1; i <= n; i++)
    			cout << a[i] << " ";
    		cout << "\n";
    	}
    }
}