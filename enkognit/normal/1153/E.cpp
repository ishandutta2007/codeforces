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

ll n, m, sum, ans, k, l, ls, r, i, j, dp[300005];
string s, d[1001];
bool t1, t2;

ll ask(ll x,ll y,ll l,ll r)
{
    ll z;
    cout << "? " << x << " " << y << " " << l << " " << r << "\n";
    cin >> z;
    return (z%2);
}

int main()
{
    //freopen("cipher.in","r",stdin);
    //freopen("cipher.out","w",stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("lexicon.in","r",stdin);
    //freopen("lexicon.out","w",stdout);
    cin >> n;
    ll x1=-1e18, y1=-1e18, x2=1e18, y2=1e18;
    t1=0, t2=0;
    for (ll i = 1; i <= n; i++)
    {
        if (ask(i, 1, i, n)) x1=max(x1,i), x2=min(x2,i), t1=1;
    }

    for (ll i = 1; i <= n; i++)
    {
        if (ask(1, i, n, i)) y1=max(y1,i), y2=min(y2,i), t2=1;
    }
    //cout << "-----\n";
    if (!t1)
    {
        ll l = 1, r = n + 1, ans = -1;
        while (l<r)
        {
            ll w = (l + r) / 2;
            if (ask(w, y1, n, y1)) l=w+1, ans=max(ans,w); else r=w;
        }
        x1=ans, x2=x1;
    }

    if (!t2)
    {
        ll l = 1, r = n + 1, ans = -1;
        while (l<r)
        {
            ll w = (l + r) / 2;
            if (ask(x1, w, x1, n)) l=w+1, ans=max(ans,w); else r=w;
        }
        y1=ans, y2=y1;
    }
    if (!ask(x1,y1,x1,y1)) swap(y1,y2);
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    return 0;
}