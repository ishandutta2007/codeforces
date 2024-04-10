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
ll a[NN];
ll jaw = 0;
ll nn, kk;
// string bin(ll z)
// {
//     string ret;
//     for(ll i = 0; i < kk; i++)
//     {
//         if(z % 2)
//             ret = "1" + ret;
//         else
//             ret = "0" + ret;
//         z /= 2LL;
//     }
//     return ret;
// }
// void hai(ll pos)
// {
//     if(pos == nn + 1)
//     {
//         ll h1 = a[1], h2 = a[1];
//         for(ll i = 2; i <= nn; i++)
//         {
//             h1 &= a[i];
//             h2 ^= a[i];
//         }
//         // if(h1 >= h2)
//         // {
//         //     for(ll i = 1; i <= nn; i++)
//         //         cout << bin(a[i]) << " ";
//         //     cout << "\n";
//         // }
//         jaw += (h1 >= h2);
//         // jaw += (h1 < h2);
//     }
//     else
//     {
//         for(ll i = 0; i < (1 << kk); i++)
//         {
//             a[pos] = i;
//             hai(pos + 1);
//         }
//     }

// }
// ll solve(ll n, ll k)
// {
//     jaw = 0;
//     nn = n;
//     kk = k;
//     hai(1);
//     return jaw;
// }
ll powo(ll A, ll B)
{
    if(B == 0)
        return 1LL;
    else
    {
        ll ret = powo(A, B / 2);
        ret = (ret * ret) % mo;
        if(B % 2 == 1)
            ret = (ret * A) % mo;
        return ret;
    }
}
ll solve2(ll n, ll k)
{
    if(n % 2 == 1)
    {
        ll ret = (powo(4, n / 2) + 1) % mo;
        ret = powo(ret, k) % mo;
        return ret;
    }
    else
    {
        ll A = (powo(2LL, n - 1) - 1 + mo) % mo;
        ll ret = powo(A, k);
        for(ll i = 0; i < k; i++)
        {
            ll ZA = powo(A, i);
            ll ZB = powo(powo(2, k - 1 - i), n);
            ret = (ret + ((ZA * ZB) % mo)) % mo;
        }
        return ret;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // solve(4, 3);
    // for(ll i = 1; i <= 8; i++)
        // for(ll j = 1; j <= 4; j++)
            // cout << i << " " << j << " " << solve(i, j) << " " << solve2(i, j) << "\n";
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << solve2(n, k) << "\n";
    }
}