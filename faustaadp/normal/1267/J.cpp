#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> lp;
typedef pair<int, int> ip;
ll t, n, x[2020202], has, a[2020202];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(ll i = 1; i <= n; i++)
		{
			cin >> a[i];
			x[i] = 0;
		}
		x[n + 1] = 0;
		sort(a+1, a+1+n);
		ll jum = 0, pjg = 0;
		vector<ll> isi;
		for(ll i = 1; i <= n; i++)
		{
			if(i == 0 || a[i] != a[i - 1])
			{
				pjg++;
				jum = 0;
			}
			jum++;
			if(i == n || a[i] != a[i + 1])
			{
				isi.pb(jum);
			}
		}
		ll hz = 0;
		for(ll i = 0; i < pjg; i++)
		{
			for(ll j = 1; j <= isi[i] + 1; j++)
			{
				ll tm = isi[i] / j;
				if((isi[i] % j) > 0)
					tm++;
				if((((j - 1) * tm) <=  isi[i]) && (isi[i] <= (j * tm)))
					x[j]++;
			}
		}
		for(ll i = 1; i <= n + 1; i++)
			if(x[i] == pjg)
				hz = i;
		has = 0;
		for(ll i = 0; i < pjg; i++)
		{
			ll tm = isi[i] / hz;
			if((isi[i] % hz) > 0)
				tm++;
			has += tm;
		}
		cout << has << "\n";

	}
	return 0;
}