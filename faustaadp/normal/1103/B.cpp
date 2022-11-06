#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
string s;
ll tanya(ll x, ll y)
{
	cout << "? " << x << " " <<y << endl;
	string jaw;
	cin >> jaw;
	return (jaw == "x");
}
int main()
{
	// ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin >> s)
	{
		if(s == "end")
			return 0;
		ll ans;
		if(tanya(0, 1))
			ans = 1;
		else
		{
			ll x = 1;
			ll y = 2;
			while(1)
			{
				if(tanya(x, y))
					break;
				x *= 2;
				y *= 2;	
			}
			ll kiri = x + 1;
			ll kanan = y;
			ll lompat = x / 2;
			while(kiri < kanan)
			{
				ll tengah = (kiri + kanan) / 2;
				if(tanya(tengah, tengah + lompat))
				{
					kiri = tengah + 1;
				}
				else
				{
					kanan = tengah;
				}
			}
			ans = kiri;
		}
		cout << "! " << ans << endl;
	}
}