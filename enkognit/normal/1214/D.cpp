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

const ll MOD = 998244353;

ll n, k, l, m, r, i, j, x, y, ans;
vector <bool> v[1000003];
vector <short> t[1000003];
string s[1000001];


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= m+1; j++) v[i].pb(0),t[i].pb(0);
    for (int i = 1; i <= n; i++) {cin >> s[i];s[i]=' '+s[i];}
    v[1][0]=1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i][j]!='#') v[i][j]=max(v[i][j-1], v[i-1][j]);
    if (v[n][m]==0) {cout << 0;exit(0);}
    ll x=n, y=m;
    while (x>1 || y>1)
    {
        //cout << x << " " << y << "\n";
        t[x][y]++;
        if (y>1 && s[x][y-1]!='#' && v[x][y-1]==1) y--;else x--;
    }
    x=n, y=m;
    //cout << "\n";
    t[n][m]--;
    while (x>1 || y>1)
    {
        t[x][y]++;
        //cout << x << " " << y << "\n";
        if (t[x][y]==2) {cout << 1;exit(0);}
        if (x>1 && s[x-1][y]!='#' && v[x-1][y]==1) x--;else y--;
    }
    cout << 2;
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