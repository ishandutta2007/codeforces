#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

ll n, m, T, k, l, r, i, j, sum, kol=0, ans, a[1000001];
vector <pll> v;
vector <pll> c[100001];
bool tt[5000001];
string s[1001],
       f;

void solve()
{
    cin >> n >> m >> k;
    for (int i = 'a'; i <= 'z'; i++)
        f+=i;
    for (int i = 'A'; i <= 'Z'; i++)
        f+=i;
    for (int i = '0'; i <= '9'; i++)
        f+=i;
    ll o=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
            if (s[i][j]=='R')
                o++;
    }
    for (int i = 0; i < k; i++)
        a[i]=o/k;
    o%=k;
    for (int i = 0; i < k; i++)
        a[i]+=(o>0), o--;
    ll p=0;
    for (int i = 1; i <=n; i++)
    {
        if (i%2)
        {
            for (int j = 0; j < m; j++)
            {
                if (p==k) p--;
                if (s[i][j]=='R')
                    a[p]--;
                s[i][j]=f[p];
                if (a[p]==0)
                    p++;
            }
        }
        else
        {
            for (int j = m-1; j > -1; j--)
            {
                if (p==k) p--;
                if (s[i][j]=='R')
                    a[p]--;
                s[i][j]=f[p];
                if (a[p]==0)
                    p++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << s[i] << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}