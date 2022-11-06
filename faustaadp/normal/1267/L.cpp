#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> lp;
typedef pair<int, int> ip;
ll n, m, k, mul, jum[1010];
string s, z[1010];
int main() {
	cin >> n >> m >> k;
	cin >> s;
	ll sl = s.length();
	sort(s.begin(),s.end());
	ll x = 0;
	ll y = 1;
	for(ll i = 0; i < sl; i++)
	{
		x++;
		if(x > k)
			x = y;
		if(i == 0 || s[i] != s[i - 1])
			y = x;
		jum[x]++;
		z[x] += s[i];
		// cout << i << " " << x << " "
		if(jum[k] == m)
		{
			mul = i + 1;
			break;
		}
	}
	for(ll i = 1; i <= n; i++)
	{
		while(jum[i] < m)
		{
			jum[i]++;
			z[i] += s[mul];
			mul++;
		}
	}
	for(ll i = 1; i <= n; i++)
		cout << z[i] << "\n";
	return 0;
}