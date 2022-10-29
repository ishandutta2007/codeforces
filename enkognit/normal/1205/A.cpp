#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

const ll MOD = 1000000007;

ll n, m, k, q, p, ans, l, r, i, j, x, y, a[1000001];
pll b[200001];
//vector <ll> c[300001];
bool tt[1000001];

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i%2)
        {
            a[i]=i*2-1;
            a[n+i]=i*2;
        }else
        {
            a[i]=i*2;
            a[n+i]=i*2-1;
        }
    }
    ll l=0, mn=1e18, mx=0;
    for (int i = 1; i <= n; i++) l+=a[i];
    for (int i = 1; i <= n*2; i++)
    {
        mn=min(mn,l);
        mx=max(mx,l);
        l-=a[i];
        ll o=n+i;
        if (o>n*2) o-=n*2;
        l+=a[o];
    }
    if (mx-mn>1)
    {
        cout << "NO\n";
        exit(0);
    }
    cout << "YES\n";
    for (int i = 1; i <= n*2; i++) cout << a[i] << " ";
    return 0;
}