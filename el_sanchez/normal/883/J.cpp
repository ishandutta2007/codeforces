//#pragma GCC optimize("O3")
//#pragma GCC target("sse4.1")
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = ((int)(n) - 1); i >= 0; --i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()

const ll inf = (ll)2e18;
struct segtree
{
    vll val;
    vll tosub;
    int tsz;

    void recalc (int v)
    {
        val[v] = min(val[2 * v], val[2 * v + 1]);
    }

    void apply (int v, ll what)
    {
        tosub[v] += what;
        val[v] -= what;
    }

    void push (int v)
    {
        if (tosub[v])
        {
            for (int son = 2 * v; son <= 2 * v + 1; son++)
                apply(son, tosub[v]);
            tosub[v] = 0;
        }
    }

    segtree (const vll &a)
    {
        tsz = 1;
        while (tsz < sz(a))
            tsz *= 2;
        val.assign(2 * tsz, 0LL);
        tosub.assign(2 * tsz, 0LL);
        forn (i, sz(a))
            val[i + tsz] = a[i];
        ford (i, tsz)
            recalc(i);
    }

    void go_sub (int v, int L, int R, int l, int r, ll x)
    {
        if (r <= L || R <= l)
            return;
        if (l <= L && R <= r)
            return void(apply(v, x));

        int M = (L + R) / 2;
        push(v);
        go_sub(2 * v, L, M, l, r, x);
        go_sub(2 * v + 1, M, R, l, r, x);
        recalc(v);
    }

    void sub (int l, int r, ll what)
    {
        return go_sub(1, 0, tsz, l, r, what);
    }

    ll go (int v, int L, int R, int l, int r)
    {
        if (r <= L || R <= l)
            return inf;
        if (l <= L && R <= r)
            return val[v];

        int M = (L + R) / 2;
        push(v);
        return min(go(2 * v, L, M, l, r), go(2 * v + 1, M, R, l, r));
    }

    ll getmin (int l, int r)
    {
        return go(1, 0, tsz, l, r);
    }
};

void solve (int n)
{
    int m;
    cin >> m;

    vi a(n);
    forn (i, n)
        cin >> a[i];

    vi renew(m), demol(m);
    forn (i, m)
        cin >> renew[i];
    forn (i, m)
        cin >> demol[i];

    vi act;
    ford (i, n) if (act.empty() || a[i] > a[act.back()])
        act.pb(i);
    reverse(all(act));

    vll money(sz(act));
    int ptr = 0;
    forn (i, n)
    {
        if (act[ptr] < i)
        {
            ptr++;
            money[ptr] = money[ptr - 1];
        }
        assert(ptr < sz(act) && i <= act[ptr]);
        money[ptr] += a[i];
    }

    vii order(m);
    forn (i, m)
        order[i] = mp(renew[i], i);
    sort(all(order));

    {
        auto old_demol = demol;
        forn (i, m)
        {
            renew[i] = order[i].fst;
            demol[i] = old_demol[order[i].snd];
        }
    }

    int left = 0;
    vi when_last(m, -1);
    ford (i, sz(act))
    {
        int right = upper_bound(all(renew), a[act[i]]) - renew.begin();
        for (int j = left; j < right; j++)
            when_last[j] = i;
        left = right;
    }

    segtree data(money);
    vi order_demol(m);
    iota(all(order_demol), 0);
    sort(all(order_demol), [&] (int x, int y) {return demol[x] < demol[y] || (demol[x] == demol[y] && when_last[x] > when_last[y]);});

    int ans = 0;
    for (int v : order_demol)
    {
        int right = when_last[v];
        ll good = data.getmin(right, sz(act));
        if (right == -1 || good < demol[v])
            continue;
        data.sub(right, sz(act), demol[v]);
        ans++;
    }
    cout << ans << endl;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
        solve(n);
}