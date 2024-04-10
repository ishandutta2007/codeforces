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
ll n, d[NN];
pll A[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    ll has = 0;
    for(ll i = 1; i <= n; i++)
    {
    	ll ta, tb;
    	cin >> ta >> tb;
    	A[i] = mp(ta, tb);
    	has += tb;
    }
    sort(A + 1, A + 1 + n);
    ll now = A[1].fi;
    for(ll i = 1; i <= n; i++)
    {
    	has += max(0LL, A[i].fi - now);
    	now = max(A[i].fi + A[i].se, now);
    }
    cout << has << "\n";
}