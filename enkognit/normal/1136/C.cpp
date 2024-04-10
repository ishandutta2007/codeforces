#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define pi 3.14159265358979323846

using namespace std;

ll n, m, j, o, l, k, r, x, y, ans=0, a[2001][2001], b[2001][2001];
vector <ll> v;

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
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
        }
    for (int u = 1; u <= max(m,n)*2; u++)
    {
         vector <ll> t={},g={};
         ll i=1,j=u;
         while (j>m) j--,i++;
         if (i>n) continue;
         while (i<=n && j>0) t.pb(a[i][j]),g.pb(b[i][j]),i++,j--;
         sort(t.begin(),t.end());
         sort(g.begin(),g.end());
         if (t!=g) {cout << "NO\n";exit(0);}
    }
    cout << "YES";
    return 0;
}