#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define y1 Enkognit
#define all(v) v.begin(),v.end()

using namespace std;

const ll MOD = 998244353;

ll n, T, kl = 0, m, ans, p, w, b[2000001];
ll a[1000001];
vector<ll> c[100001];
vector<ll> v;
bool tt[1000001];
int tl[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.pb(mp(a[i],i));
    }
    sort(all(v));
    reverse(all(v));
    ll ans = 1, k = 0;
    vector<pll> z;
    for (int i = 0; i < m; i++)
    {
        z.pb(mp(v[i].second, v[i].fi));
        k += v[i].first;
    }

    sort(all(z));
    for (int i = 0; i < z.size() - 1; i++)
    {
        ans *= (z[i+1].first-z[i].fi);
        ans %= MOD;
    }
    cout << k << " " << ans << "\n";
    return 0;
}
/*
6
add 1
sum 1 1
add 3
add 1
sum 2 3
sum 1 2
*/