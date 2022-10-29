#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb puhs_back
#define pll pair<ll,ll>
#define se second
#define fi first

using namespace std;

ll n, m, k, l, r, i, j, a[1000001], b[1000001];
bool tt[1000001];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) b[i]=0, tt[i]=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i]!=a[i-1]) b[i]=a[i], tt[a[i]]=1;;
    }
    ll l=1;
    for (int i = 1; i <= n; i++)
        if (b[i]==0)
    {
        while (tt[l]) l++;
        if (l>a[i]) {cout << "-1\n";return;}
        b[i]=l;
        tt[l]=1;
    }
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}