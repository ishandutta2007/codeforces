#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
ll n, a[NN], aw[NN], tmp[NN], sum = 0;
// ll ganti()
// {
//     ll ret = 0;
//     for(ll i = 1; i < n; i++)
//         if(a[i] + 2 <= a[i + 1])
//         {
//             ret = 1;
//             tmp[i]++;
//             tmp[i + 1]--;
//         }
//     for(ll i = 1; i <= n; i++)
//     {
//         a[i] += tmp[i];
//         tmp[i] = 0;
//     }
//     return ret;
// }
ll cek(ll pos)
{
    if(n % 2 == 1)
        return (pos * 2LL + n - 2LL) * ((n - 1LL) / 2LL) + pos;
    else
        return (pos + n / 2LL - 1LL) * (n - 1LL) + pos;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    srand(time(NULL));
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        // a[i] = a[i - 1] + rand() % 10;
        // cout << a[i] << " ";
        // aw[i] = a[i];
    }
    // cout << "\n";
    // while(ganti());

    for(ll i = 1; i <= n; i++)
        sum += a[i];

    ll kir;
    ll L = 0, R = 1e12, dob;

    while(L <= R)
    {
        ll C = (L + R) / 2;
        if(cek(C) <= sum)
        {
            kir = C;
            dob = sum - cek(C) + C;
            L = C + 1;
        }
        else
            R = C - 1;
    }
    // cout << kir << " " << dob << "\n";
    for(ll i = kir; i <= kir + n - 2; i++)
    {
        cout << i << " ";
        if(i == dob)
            cout << i << " ";
    }
    if(dob > (kir + n - 2))
        cout << dob << " ";
    cout << "\n";
    // for(ll i = 1; i <= n; i++)
    //     cout << a[i] << " ";
    // cout << "\n";

}