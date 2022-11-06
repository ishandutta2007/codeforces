#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t, n, i, a[404040], x[404004];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		ll te = 1;
		x[1] = -1;
		x[2] = -1;
		x[3] = -1;
		ll ban = 0;
		for(ll i = 1; i <= n; i++)
			cin >> a[i];
		for(ll i = 1; (i * 2) <= n; i++)
		{
			ban++;
			if(a[i] != a[i + 1] && te == 1)
			{
				x[te] = ban;
				te++;
				ban = 0;
			}
			else
			if((a[i] != a[i + 1]) && (ban > x[1]))
			{
				x[te] = ban;
				if(te == 2)
				{
					te++;
					ban = 0;
				}
			}
		}
		if((x[3] == -1) || ((x[1] + x[2] + x[3]) * 2 > n))
		{
			x[1] = 0;
			x[2] = 0;
			x[3] = 0;
		}
		cout << x[1] << " " << x[2] << " " << x[3] << "\n";
	}
}