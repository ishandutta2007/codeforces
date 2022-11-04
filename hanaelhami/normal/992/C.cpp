#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int mod = 1e9 + 7;

int pw(int a , int b)
{
	if(!b)
		return 1;

	int x = pw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
}

int bpw(ll a , ll b)
{
	a %= mod;
	b %= (mod - 1);

	return pw(a , b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n , k;
	cin >> n >> k;

	if(n == 0)
		return cout << 0 << endl , 0;

	n %= mod;
	int tmp = bpw(2 , k);

	int res = 1LL * n * tmp % mod;
	res = 2LL * res * tmp % mod;

	int ker = 1LL * tmp * (tmp - 1 + mod) % mod;
	res = (res - ker + mod) % mod;
	res = 1LL * res * bpw(tmp , mod - 2) % mod;

	cout << res << endl;

}