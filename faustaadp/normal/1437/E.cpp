#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 5e5 + 5;
ll t, n, a[NN], d[NN], x[NN], k, y[NN];
ll comp(ll L, ll R)
{
	if(L > R)
		return 0;
	set<pair<ll, ll> > st;
    st.insert(mp(1e18, -1));
    ll hz = 0;
    ll ban = 0;
	for(ll i = L; i <= R; i++)
	{
		if(a[L - 1] <= a[i] && a[i] <= a[R + 1])
		{	
            if(ban == 0 || y[ban] <= a[i])
                y[++ban] = a[i];
            else
            {
                ll Le = 1, Ri = ban, H;
                while(Le <= Ri)
                {
                    ll C = (Le + Ri) / 2;
                    if(y[C] > a[i])
                    {
                        H = C;
                        Ri = C - 1;
                    }
                    else
                        Le = C + 1;
                }
                y[H] = a[i];
            }
		}
	}
	// cout << L << " " << R << " " << hz << "_\n";
	hz = R - L - ban + 1;
	return hz;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // cin >> t;
    t = 1;
    while(t--)
    {
    	cin >> n >> k;
    	for(ll i = 1; i <= n; i++)
    	{
    		d[i] = 0;
    		cin >> a[i];
    		a[i] -= i;
    	}
    	
    	a[0] = -1e18;
    	a[n + 1] = 1e18;
    	x[0] = 0;
    	x[k + 1] = n + 1;
    	for(ll i = 1; i <= k; i++)
    		cin >> x[i];
    	ll has = 0;
    	for(ll i = 0; i <= k; i++)
    	{
    		// cout << x[i] << " " << x[i + 1] << "-\n";
    		if(a[x[i]] > a[x[i + 1]])
    		{
    			has = -1;
    			break;
    		}
    		else
    			has += comp(x[i] + 1, x[i + 1] - 1);
    	}
    	cout << has << "\n";
    }
}