#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define y1 Enkognit
#define fi first
#define se second
#define pll pair<ll, ll>

using namespace std;

ll n, m, k, l, r, i, j, ans[1000001], dp[100001];
ll w[10001];
vector <pll> v;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x,1));
        v.pb(mp(y+1,-1));
    }
    sort(v.begin(),v.end());
    ll p=0, l=0;
    for (int i = 0; i < v.size(); i++)
    {
        ans[p]+=v[i].fi-l;
        p+=v[i].se;
        l=v[i].fi;
        //cout << l << " " << p << "\n";
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";

    return 0;
}