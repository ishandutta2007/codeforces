#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll n, m, i, x[NN], mo = 998244353;
ll N, M, hz = 0, z[NN];
ll cik()
{
	ll bts = -1, dup = 0;
	for(ll i = 1; i <= N; i++)
		for(ll j = i + 1; j <= N; j++)
			if(z[i] == z[j])
				dup++;
	for(ll i = 1; i < N; i++)
		if(z[i] < z[i + 1])
		{
			//
		}
		else
		{
			bts = i;
			break;
		}
	if(bts != -1)
	{
		for(ll i = bts; i < N; i++)
			if(z[i] <= z[i + 1])
				return 0;
	}
	return (dup == 1);
}
void cak(ll pos)
{
	if(pos > N)
	{
		if(cik())
		{
			// for(ll i = 1; i <= N; i++)
			// 	cout << z[i] << " ";
			// cout << "\n";
			hz++;
		}
		return ;
	}
	for(ll i = 1; i <= M; i++)
	{
		z[pos] = i;
		cak(pos + 1);
	}
}
ll cek(ll aa, ll bb)
{
	N = aa;
	M = bb;
	hz = 0;
	cak(1);
	return hz;
}
ll powo(ll aa, ll bb)
{
	if(bb == 0)
		return 1;
	else
	{
		ll tem = powo(aa, bb / 2);
		tem = (tem * tem) % mo;
		if(bb % 2 == 1)
			tem = (tem * aa) % mo;
		return tem;
	}
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // cek(3, 4);
    cin >> n >> m;
    if(n <= 2)
    {
    	cout << 0 << "\n";
    	return 0;
    }
    x[n - 1] = (n - 2);
    for(ll i = 1; i <= (n - 3); i++)
    	x[n - 1] = (x[n - 1] * 2LL) % mo;
    ll bag = 0;
    for(ll i = n; i <= m; i++)
    {
    	x[i] = (x[i - 1] * i) % mo;
    	bag++;
    	x[i] = (x[i] * powo(bag, mo - 2)) % mo;
    }
    cout << x[m] << "\n";
    // cout << x[n] << "\n";
    // for(ll i = 1; i <= 8; i++)
    // 	for(ll j = 1; j <= 7; j++)
    // 		cout << i << " " << j << " " << cek(i, j) << "\n";
}