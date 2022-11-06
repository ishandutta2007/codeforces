#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n;
char a[330][330];
ll z[4];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		z[0] = 0;
		z[1] = 0;
		z[2] = 0;
		for(ll i = 0; i < n; i++)
			for(ll j = 0; j < n; j++)
			{
				cin >> a[i][j];
				if(a[i][j] == 'X')
					z[(i + j) % 3]++;
			}
		// cout << z[0] << " " << z[1] << " " << z[2] << "\n";
		ll mo = 0;
		if(z[0] <= min(z[1], z[2])) mo = 0;
		if(z[1] <= min(z[0], z[2])) mo = 1;
		if(z[2] <= min(z[0], z[1])) mo = 2;
		for(ll i = 0; i < n; i++)
		{
			for(ll j = 0; j < n; j++)
			{
				if((a[i][j] == 'X') && ((i + j) % 3 == mo))
					a[i][j] = 'O';
				cout << a[i][j];
			}
			cout << "\n";
		}
	}
}