#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll n, i, a[NN], d[NN];
ll b[550][550];
ll depe(ll pos)
{
	if(pos > n)
		return 0;
	if(d[pos] == -1)
	{
		ll ret = 1e18;
		for(ll i = pos; i <= n; i++)
			if(b[pos][i])
				ret = min(ret, depe(i + 1) + 1);
		d[pos] = ret;
	}
	return d[pos];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(d, -1, sizeof(d));
    cin >> n;
    for(ll i = 1; i <= n; i++)
    	cin >> a[i];
    for(ll i = 1; i <= n; i++)
    {
    	vector<ll> st;
    	ll sz = 0;
    	for(ll j = i; j <= n; j++)
    	{
    		st.pb(a[j]);sz++;
			while((sz > 1) &&(st[sz - 1] == st[sz - 2]))
			{
				ll tem = st[sz - 1];
				st.pop_back();sz--;
				st.pop_back();sz--;
				st.pb(tem + 1);sz++;
			}
			// for(ll k = 0; k < sz; k++)
			// 	cout << st[k] << " ";
			// cout << "_\n";
			// cout << i << " " << j << " " << sz << "__\n";
    		if(sz == 1)
    		{
    			// cout << i << " " << j << "\n";
    			b[i][j] = 1;
    		}
    	}
    	// break;
    }
    cout << depe(1) << "\n";
}