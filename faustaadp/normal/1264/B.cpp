#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll a[101010], x[101010], y[101010], n, ya;
void res()
{
	y[1] = a[1];
	y[2] = a[2];
	y[3] = a[3];
	y[4] = a[4];
	for(ll i = 1; i <= n; i++)
		x[i] = -1;
}
void cek(ll pos, ll tipe, ll idx)
{
	if(idx > n || y[pos] == 0)
		return ; 
	// if(ya)
	// {
		// cout << pos << " " << tipe << " " << idx << "\n";
	// }
	x[idx] = pos - 1;
	y[pos]--;
	if(tipe == 1)
	{
		if(y[pos - 1])
			cek(pos - 1, tipe, idx + 1);
		else
			cek(pos + 1, tipe, idx + 1);
	}
	else
	if(tipe == 2)
	{
		if(y[pos + 1])
			cek(pos + 1, tipe, idx + 1);
		else
			cek(pos - 1, tipe, idx + 1);
	}
	else
	if(tipe == 3)
	{
		if(pos == 2)
		{
			if(y[pos - 1])
				cek(pos - 1, tipe, idx + 1);
			else
				cek(pos + 1, tipe, idx + 1);
		}
		else
		{
			if(y[pos + 1])
				cek(pos + 1, tipe, idx + 1);
			else
				cek(pos - 1, tipe, idx + 1);
		}
	}
	else
	{
		if(pos == 1)
		{
			if(y[pos - 1])
				cek(pos - 1, tipe, idx + 1);
			else
				cek(pos + 1, tipe, idx + 1);
		}
		else
		{
			if(y[pos + 1])
				cek(pos + 1, tipe, idx + 1);
			else
				cek(pos - 1, tipe, idx + 1);
		}
	}
}
void cetak()
{
	cout << "YES\n";
	for(ll i = 1; i <= n; i++)
		cout << x[i] << " ";
	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> a[1];
	cin >> a[2];
	cin >> a[3];
	cin >> a[4];
	n = a[1] + a[2] + a[3] + a[4];	
	for(ll i = 4; i >= 1; i--)
	{
		for(ll j = 1; j <= 4; j++)
		{
			if(i == 2)
				ya = 1;
			else
				ya = 0;
			res();
			cek(i, j, 1);
			if(x[n] != -1)
			{
				cetak();
				return 0;
			}
		}
	}
	cout << "NO\n";
}