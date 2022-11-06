#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
const ll mo = 1e9 + 7;
ll n, k, q, a[NN], d[5050][5050], d2[5050][5050], z[5050];
void pc()
{
	for(ll i = 1; i <= n; i++)
		d[i][0] = 1;
	for(ll i = 0; i < k; i++)
	{
		for(ll j = 1; j <= n; j++)
		{
			d[j + 1][i + 1] = (d[j + 1][i + 1] + d[j][i]) % mo;
			d[j - 1][i + 1] = (d[j - 1][i + 1] + d[j][i]) % mo;
		}
	}
    for(ll i = 1; i <= n; i++)
    {
        // cout << i << " " << d[i][k] << "__\n";
        d2[i][k] = d[i][k];
        d2[i][k] = 1;
    }
    for(ll i = k - 1; i >= 0; i--)
    {
        for(ll j = 1; j <= n; j++)
        {
            d2[j][i] = (d2[j + 1][i + 1] + d2[j - 1][i + 1]) % mo;
        }
    }
	for(ll i = 1; i <= n; i++)
    {
        for(ll j = 0; j <= k; j++)
        {
            // cout <<  i << " " << d[i][j] * d2[i][j] << "_\n";
            z[i] = (z[i] + d[i][j] * d2[i][j]) % mo;
        }
    }
	// for(ll i = 1; i <= n; i++)
		// cout << i << " " << z[i] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k >> q;
    for(ll i = 1; i <= n; i++)
    	cin >> a[i];
    pc();
    ll hz = 0;
    for(ll i = 1; i <= n; i++)
    	hz = (hz + a[i] * z[i]) % mo;
    while(q--)
    {
    	ll ta, tb;
    	cin >> ta >> tb;
    	hz = (hz - (z[ta] * a[ta]) % mo + mo) % mo;
    	a[ta] = tb;
    	hz = (hz + (z[ta] * a[ta]) % mo + mo) % mo;
    	cout << hz << "\n";
    }
}