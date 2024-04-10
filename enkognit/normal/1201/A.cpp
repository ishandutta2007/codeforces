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

using namespace std;

const ll MOD = 998244353;

ll n, m, k, q, p, ans, l, r, i, j, x, y;
ll a[1001][7];
bool t[1000001];
string s;
vector <ll> v;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            a[j+1][s[j]-'A'+1]++;
    }
    ll ans=0;
    for (int i = 1; i <= m; i++) sort(a[i]+1,a[i]+6);
    for (int i = 1; i <= m; i++)
    {
        ll x;
        cin >> x;
        ans+=x*a[i][5];
        //cout << a[i][5] << "\n";
    }
    cout << ans;
    return 0;
}


/*

| 1 5 13 29 | 2 7 17 37 | 18 39 22 47 |


*/