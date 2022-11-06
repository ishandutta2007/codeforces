#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 998244353;
ll f[NN];
ll a[NN];
ll n;
ll powo(ll A, ll B)
{
    if(B == 0)
        return 1;
    else
    {
        ll tmp = powo(A, B / 2);
        tmp = (tmp * tmp) % mo;
        if(B % 2 == 1)
            tmp = (tmp * A) % mo;
        return tmp;
    }
}
ll solve()
{
    if(a[n] == a[n - 1])
        return f[n];
    else
    if(a[n - 1] + 1 < a[n])
        return 0;
    ll jum = 0;
    for(ll i = 1; i < n; i++)
        if(a[i] + 1 == a[n])
            jum++;
    ll ret = (f[n] * jum) % mo;
    ret = (ret * powo(jum + 1, mo - 2)) % mo;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    f[0] = 1;
    for(ll i = 1; i <= 200000; i++)
        f[i] = (f[i - 1] * i) % mo;
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        cout << solve() << "\n";
    }
}