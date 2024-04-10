#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

ll n, k, l, m, r, i, j, x, y, ans, a[3][300001];
string s;
ll d[3000001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        for (int i = 0; i < n; i++) if (s[i]>'2') a[1][i+1]=1; else a[1][i+1]=0;
        cin >> s;
        for (int i = 0; i < n; i++) if (s[i]>'2') a[2][i+1]=1; else a[2][i+1]=0;
        ll p1=1, p2=0;
        for (int i = 1; i <= n; i++)
        {
            if (a[1][i] && a[2][i]) swap(p1,p2); else
            if (a[1][i]==1 && a[2][i]==0) p1=0; else
            if (a[2][i]==1 && a[1][i]==0) p2=0;
        }
        if (p2) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}
/*
6 15
E 5
V 9
M 3
V 2
M 5
V 6
*/