#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

mt19937_64 rnd(time(NULL));

ll n, m, k, i, j, mx=0, T=0, a[1000001];
string s[1001], t[1001];
vector <ll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)cin >> s[i];
    for (int i = 1; i <= m;i++)cin >> t[i];
    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        ll o=x%n, p=x%m;
        if (o==0) o=n;
        if (p==0) p=m;
        cout << s[o]+t[p] << "\n";
    }
    return 0;
}
/*
4
101
10001
1
10
1101
*/