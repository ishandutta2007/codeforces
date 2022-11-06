#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll t, n, a[NN], x[NN], m, k;
void upd(ll aa)
{
	ll mx = 0;
	for(ll i = 1; i <= n; i++)
		mx = max(mx, a[i]);
	if(mx == 0)
		return ;
	for(ll i = 1; i <= n; i++)
		if(mx == a[i])
		{
			if(a[i] >= aa)
				a[i] -= aa;
			return ;
		}
}
ll cek()
{
	ll mx = 0;
	for(ll i = 1; i <= n; i++)
		mx = max(mx, a[i]);
	return (mx == 0);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n >> k;
    	x[0] = 1;
    	ll K = 1e16;
    	for(ll i = 1; i <= 100000; i++)
    	{
    		x[i] = x[i - 1] * k;
 			if(x[i] > K)
 			{
 				m = i - 1;
 				break;
 			}   		
    	}
    	for(ll i = 1; i <= n; i++)
    		cin >> a[i];
    	for(ll i = m; i >= 0; i--)
    		upd(x[i]);
    	if(cek())
    		cout << "YES\n";
    	else
    		cout << "NO\n";
    }
}