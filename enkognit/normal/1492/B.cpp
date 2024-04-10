#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, k, a[1000001];
bool tt[1000001];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        tt[i]=0;
        cin >> a[i];
    }
    ll o=n;
    vector<ll> v;
    for (int j = n; j > 0; j--)
    {
        if (o==a[j])
        {
            v.pb(j);
            o--;
            while (tt[o]) o--;
        }else tt[a[j]]=1;
    }
    ll lst=n+1;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = v[i]; j < lst; j++)
        {
            cout << a[j] << " ";
        }
        lst=v[i];
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
5
......
MMMC
......
CCCM
.X..X.
MMM
XXXXXX
CMMCM
......
MM

*/