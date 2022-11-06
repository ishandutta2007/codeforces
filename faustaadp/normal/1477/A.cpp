#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 5e5 + 5;
ll t, n, k, a[NN];
ll fpb(ll aa, ll bb)
{
    if(bb == 0)
        return aa;
    else
        return fpb(bb, aa % bb);
}
// ll K = 50;
// vector<ll> isi;
// void masuk(ll aa)
// {
//     if(aa > 50 || aa < -50)
//         return ;
//     if(b[aa + K])
//         return ;
//     b[aa + K] = 1;
//     for(ll i = 0; i < isi.size(); i++)
//     {
//         masuk(aa * 2 - isi[i]);
//         masuk(isi[i] * 2 - aa);
//     }
//     isi.pb(aa);
// }
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        ll FPB = 0;
        sort(a + 1, a + 1 + n);
        for(ll i = 2; i <= n; i++)
            FPB = fpb(FPB, a[i] - a[i - 1]);
        ll sel = abs(a[1] - k);
        if(sel % FPB == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}