#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 1e5 + 20;
const int maxb = 63;

ll get(ll val , ll n)
{
	ll ans = 0;
	for(int i = maxb - 1; i >= 0; i--)
		if(!bit(val , i) && ans + (1LL << i) <= n)
			ans += (1LL << i);
	return ans;
}

int main()
{
	ll n , k;
	cin >> n >> k;
	ll ans = 0;
	if(k >= 100)
	{
		for(int i = 0; (1LL << i) <= n; i++)
			ans += (1LL << i);
		cout << ans;
		return 0;
	}
	for(int i = 0; i < k; i++)
		ans = ans ^ get(ans , n);
	cout << ans << endl;
}