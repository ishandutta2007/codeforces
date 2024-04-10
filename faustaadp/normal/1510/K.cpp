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
ll n, a[NN], x[NN];
void hai(ll jen)
{
	if(jen == 0)
	{
		for(ll i = 1; i <= n; i++)
			swap(a[i], a[i + n]);
	}
	else
	{
		for(ll i = 1; i <= n; i++)
			swap(a[i * 2 - 1], a[i * 2]);
	}
}
ll sama()
{
	for(ll i = 1; i <= n * 2; i++)
		if(a[i] != i)
			return 0;
	return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n * 2; i++)
    {
    	cin >> x[i];
    	a[i] = x[i];
    }
   	ll has = 1e18;
   	if(sama())
   		has = 0;
   	for(ll i = 1; i <= 10 * n; i++)
   	{
   		hai(i % 2);
   		if(sama())
   		{
   			has = min(has, i);
   			break;
   		}
   	}
    for(ll i = 1; i <= n * 2; i++)
    	a[i] = x[i];
   	for(ll i = 1; i <= 10 * n; i++)
   	{
   		hai(1 - (i % 2));
   		if(sama())
   		{
   			has = min(has, i);
   			break;
   		}
   	}
   	if(has == 1e18)
   		has = -1;
   	cout << has << "\n";
}