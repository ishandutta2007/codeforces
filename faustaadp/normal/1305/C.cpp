#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll n, m, i, a[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
    	cin >> a[i];
    if(n > m)
    	cout << 0 << "\n";
    else
    {
    	ll has = 1;
    	for(ll i = 1; i <= n; i++)
    		for(ll j = i + 1; j <= n; j++)
    			has = (has * abs(a[i] - a[j])) % m;
    	cout << has << "\n";
    }
}