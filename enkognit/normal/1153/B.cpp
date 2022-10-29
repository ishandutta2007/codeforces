#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pu push
#define ld long double
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pld pair<ll,double>
#define y1 Enkognit

using namespace std;

ll n, m, i, j, k, p, l, h, r, a[200001], b[200001], hh[101][101], ans[101][101];
vector <ll> v, c[200001];
bool ta[1001], tb[1001];

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            if (x)
            {
               ans[i][j]=min(a[j],b[i]);
            }
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cout << ans[i][j] << " ";
        cout << "\n";
    }return 0;
}
/* */