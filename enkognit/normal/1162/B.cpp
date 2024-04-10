#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=1000000007;

ll n, m, l, r, x, h, y, ans, z, a[101][101], b[101][101];
string s, d;

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        cin >> b[i][j];
        if (a[i][j]>b[i][j]) swap(a[i][j],b[i][j]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= m; j++)
    if (a[i][j]<=a[i][j-1] || b[i][j]<=b[i][j-1]){cout << "Impossible\n";exit(0);}
    for (int j = 1; j <= m; j++)
        for (int i = 2; i <= n; i++)
    if (a[i][j]<=a[i-1][j] || b[i][j]<=b[i-1][j]){cout << "Impossible\n";exit(0);}
    cout << "Possible\n";
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4

*/