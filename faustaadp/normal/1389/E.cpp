#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n, k, l1, l2, r1, r2;
ll fpb(ll a, ll b)
{
    if(b == 0)
        return a;
    else
        return fpb(b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        ll m, d, w;
        cin >> m >> d >> w;
        ll sel = w / fpb(d - 1, w);
        ll ban = min(m, d);
        ll x = ban % sel;
        ll y = min(ban, sel) - x;
        ll xt = ban / sel + ((ban % sel) != 0);
        ll yt = ban / sel;
        // cout << x << " " << xt << "x\n";
        // cout << y << " " << yt << "y\n";
        ll has = x * (xt * (xt - 1LL)) / 2LL + y * (yt * (yt - 1)) / 2LL;
        cout << has << "\n";
    }
}