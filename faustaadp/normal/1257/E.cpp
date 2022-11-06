#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 2e5 + 5;
ll n, k[4], a[NN], d[NN][4];
ll depe(ll pos,ll bag)
{
    if(bag > 3)return 1e18;
    if(pos > n)return 0;
    ll ret = d[pos][bag];
    if(ret == -1)
        ret = min(depe(pos, bag + 1), depe(pos + 1, bag) + (a[pos] != bag));
    return d[pos][bag] = ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(ll i = 1; i <= 3; i++)
    {
        cin >> k[i];
        n += k[i];
    }
    for(ll i = 1; i <= 3; i++)
    {
        for(ll j = 1; j <= k[i]; j++)
        {
            ll ta;
            cin >> ta;
            a[ta] = i;
        }
    }
    memset(d, -1, sizeof(d));
    cout << depe(1,1) << "\n";
}