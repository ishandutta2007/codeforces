#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
const ld eps = 1e-9;
ll t, n;
ll SQ(ll x)
{
	ll Z = sqrt(x);
	if((Z * Z) != x)
		return 0;
	return Z;
}
ll hai(ll x)
{
	if(x % 2 == 0)
	{
		if(SQ(x / 2))return 1;
	}
	if(SQ(x))
	{
		if(SQ(x) % 2 == 0)return 1;
	}
	return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n;
    	if(hai(n))cout << "YES\n";
    	else cout << "NO\n";
    }
}