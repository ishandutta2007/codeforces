#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll n, d[110][110][110][2], a[110];
ll depe(ll pos, ll gen,ll gan, ll las)
{
    if(gen < 0)
        return 1e18;
    if(gan < 0)
        return 1e18;
    if(pos == (n + 1))
        return 0;
    ll ret = d[pos][gen][gan][las];
    if(ret == -1)
    {
        ret = 1e18;
        if(a[pos] == -1)
            ret = min(depe(pos + 1, gen - 1, gan, 0) + (las == 1), depe(pos + 1, gen, gan - 1, 1) + (las == 0));
        else
        if(a[pos] == 0)
            ret = depe(pos + 1, gen - 1, gan, 0) + (las == 1);
        else
            ret = depe(pos + 1, gen, gan - 1, 1) + (las == 0);
        // cout << pos << " " << gen << " " << gan << " " << las << " " << ret << "\n";
    }
    return d[pos][gen][gan][las] = ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] == 0)
            a[i] = -1;
        else
            a[i] %= 2;
    }
    memset(d, -1, sizeof(d));
    ll has = min(depe(1,n / 2, n - (n / 2), 0), depe(1,n / 2, n - (n / 2), 1));
    cout << has << "\n";
}