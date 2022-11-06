#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll has, n, p[1010101], ta;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(ll i = 1; i <= n ; i++)
		p[i] = p[i-1] ^ i;
	for(ll i = 1; i <= n ; i++)
	{
		if((n / i) % 2 == 0)
			has ^= p[n%i]; 
		else
			has ^= p[i-1] ^ p[n%i]; 

		cin >> ta;
		has ^= ta;
		// cout << i << " " << has << "\n";
	}
	cout << has << "\n";
}