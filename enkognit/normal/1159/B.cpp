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

ll n, m, W, l, r, ans, k, a[300001];
vector <pll> b;
bool t[1000001];

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b.pb(mp(a[i],i));
    }
    ll l=1, r=n, k=1e18;
    sort(b.begin(),b.end());
    for (int i = 0; i < n; i++)
    {
        k=min(k,b[i].fi/max(max(b[i].se-l,1ll),max(r-b[i].se,1ll)));
        t[b[i].se]=1;
        while (t[l])l++;
        while (t[r])r--;
    }
    cout << k;
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