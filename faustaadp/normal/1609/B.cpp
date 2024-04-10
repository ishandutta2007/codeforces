#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 2e5 + 5;
const int mo = 1e9 + 7;
const ll inf = 1e18 + 1;
ll n, has, q;
char a[NN];
void upd(ll idx, ll tam)
{
	if((idx >= 1) && (idx + 2 <= n))
		has += tam * (a[idx] == 'a' && a[idx + 1] == 'b' && a[idx + 2] == 'c');
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(ll i = 1; i <= n; i++)
    	cin >> a[i];
    for(ll i = 1; i <= n; i++)
    	upd(i, 1);
    while(q--)
    {
    	ll idx;
    	char ct;
    	cin >> idx >> ct;
    	for(ll j = idx - 2; j <= idx + 2; j++)
    		upd(j, -1);
    	a[idx] = ct;
    	for(ll j = idx - 2; j <= idx + 2; j++)
    		upd(j, 1);
    	cout << has << "\n";
    }
}