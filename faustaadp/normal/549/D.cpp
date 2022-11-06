#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll maxN = 105;
ll n, m, x[maxN][maxN], a[maxN][maxN], has;
void upd(ll X, ll Y, ll tam)
{
	for(ll i = 1; i <= X; i++)
		for(ll j = 1; j <= Y; j++)
			a[i][j] += tam;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++)
		for(ll j = 1; j <= m; j++)
		{
			char ct;
			cin >> ct;
			if(ct == 'B')
				x[i][j] = -1;
			else
				x[i][j] = 1;
		}
	while(1)
	{
		ll sudah = 0;
		for(ll i = n; i >= 1; i--)
		{
			if(sudah)break;
			for(ll j = m; j >= 1; j--)
				if(x[i][j] != a[i][j])
				{
					// cout << i << " " << j << "\n";
					upd(i, j, x[i][j] - a[i][j]);
					sudah = 1;
					break;
				}
		}
		if(!sudah)
		{
			cout << has << "\n";
			return 0;
		}
		has++;
	}
}