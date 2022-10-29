#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pu push
#define ld long double
#define pld pair<ld,ld>
#define y1 Enkognit
//#define {cout.flush()} {fflush(stdout)}

using namespace std;

const ll MOD=1e9;

ll n, m, sum, ans=1e18, k, l, ls, r, i, j, p1, p2, dp[200001], a[200001], pre[200001];
pll v[200001];

int main()
{
    //freopen("cipher.in","r",stdin);
    //freopen("cipher.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("lexicon.in","r",stdin);
    //freopen("lexicon.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].fi >> v[i].se;
    }

    for (int i = 1; i <= n; i++) pre[i]=pre[i-1]+a[i-1];

    for (int i = 1; i <= n; i++) dp[i]=1e18;

    for (int i = 0; i < k; i++)
    {
        dp[i+1]=min(dp[i+1],dp[i]+a[i]);
        for (int j = 0; j < m; j++)
            if (v[j].fi<=k-i)
            {
                dp[i+v[j].fi]=min(dp[i+v[j].fi], dp[i]+pre[i+v[j].fi]-pre[i+v[j].se]);
            }
    }
    ll ans=1e18;
    cout << dp[k];
    return 0;
}