#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n, k, x[NN], y[NN];
ll jarak(ll aa, ll bb)
{
	return abs(x[aa] - x[bb]) + abs(y[aa] - y[bb]);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(ll i = 1; i <= n; i++)
			cin >> x[i] >> y[i];
		ll jaw = -1;
		for(ll i = 1; i <= n; i++)
		{
			ll bisa = 1;
			for(ll j = 1; j <= n; j++)
				if(jarak(i, j) > k)
					bisa = 0;
			if(bisa)
			{
				jaw = 1;
				break;
			}
		}
		cout << jaw << "\n";
	}
}