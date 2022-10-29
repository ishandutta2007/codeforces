#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define el endl
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double

using namespace std;

ld PI=3.14159265359;

ll n, m, l, r, k, h, i, j, T;
ll a[500001];
ll t[2002];
ll dp[200001][3];

int main()
{
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> a[i];k+=a[i];}
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        cout << k-a[x] << "\n";
    }
    return 0;
}