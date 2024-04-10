#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const ll N = 100100;
const ll MX = 1e16;
const ll MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll a[N];
ll b[N];
ll c[N];
ll t[4 * N];
pair < pair < ll, ll >, ll > p[N];

ll get(int x, int l, int r, int tl, int tr)
{
    if(tl > tr)
        return 0;
    if(l == tl && r == tr)
        return t[x];
    int m = (l + r) / 2;
    return max(get(x * 2, l, m, tl, min(m, tr)), get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr));
}

void upd(int x, int l, int r, int g, ll y)
{
    if(l == r){
        t[x] = y;
        return;
    }
    int m = (l + r) / 2;
    if(g <= m)
        upd(x * 2, l, m, g, y);
    else
        upd(x * 2 + 1, m + 1, r, g, y);
    t[x] = max(t[x * 2], t[x * 2 + 1]);
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
        p[i] = {{b[i], a[i]}, i};
    }
    sort(p + 1, p + n + 1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int h = p[i].se,
            l = 1,
            r = i;
        while(l < r){
            int m = (l + r) / 2;
            if(p[m].fi.fi > a[h])
                r = m;
            else
                l = m + 1;
        }
        ll x = get(1, 1, n, l, i) + c[h];
        ans = max(ans, x);
        upd(1, 1, n, i, x);
    }
    cout << ans << endl;
}


bool mtest = false; int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //fin("friendcross.in");
    //fout("friendcross.out");
    ios_base::sync_with_stdio(0);
    int TE = 1;
    if(mtest)
        cin >> TE;
    while(TE--)
        solve();
}