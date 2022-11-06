#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
const ld eps = 1e-9;
ll n;
ll powo(ll A, ll B)
{
    if(B == 0)
        return 1;
    else
    {
        ll ret = powo(A, B / 2);
        ret = (ret * ret) % mo;
        if(B % 2 == 1)
            ret = (ret * A) % mo;
        return ret;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n;
    ll has = 6LL * powo(4LL, (1LL << n) - 2LL) % mo;
    cout << has << "\n";
}