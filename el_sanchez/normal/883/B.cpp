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

void dfs (int x, const vvi &g, vc &used, vi &order)
{
    used[x] = 1;
    for (int dest : g[x]) if (!used[dest])
        dfs(dest, g, used, order);
    order.pb(x);
}

void solve (int n)
{
    int m, k;
    cin >> m >> k;

    vi rk(n);
    vc isset(n);
    forn (i, n)
    {
        cin >> rk[i];
        isset[i] = (rk[i] == 0 ? 0 : 1);
    }

    vvi g(n), grev(n);
    forn (i, m)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[v].pb(u);
        grev[u].pb(v);
    }

    vi order;
    {
        vc used(n);
        forn (i, n) if (!used[i])
            dfs(i, g, used, order);
        reverse(all(order));

        vi in_order(n);
        forn (i, n)
            in_order[order[i]] = i;

        forn (i, n) for (int to : g[i]) if (in_order[i] > in_order[to])
        {
            cout << -1 << endl;
            return;
        }

        for (int v : order)
        {
            if (rk[v] == 0)
                rk[v] = 1;
            if (rk[v] > k)
            {
                cout << -1 << endl;
                return;
            }
            for (int to : g[v])
            {
                if (isset[to] && rk[to] < rk[v] + 1)
                {
                    cout << -1 << endl;
                    return;
                }
                else if (!isset[to])
                    rk[to] = max(rk[to], rk[v] + 1);
            }
        }
    }

    set<pii> fixed, unfix;
    vi out(n);
    forn (i, n)
        out[i] = sz(g[i]);

    vi oldrk = rk;

    auto add_ver = [&] (int x)
    {
        if (out[x] == 0)
            (isset[x] ? fixed : unfix).insert(mp(oldrk[x], x));
    };
    auto del_ver = [&] (int x)
    {
        (isset[x] ? fixed : unfix).erase(mp(oldrk[x], x));
        for (int from : grev[x])
        {
            out[from]--;
            add_ver(from);
        }
    };

    forn (i, n)
        add_ver(i);

//    copy(all(rk), ostream_iterator<int>(cerr, " "));
//    cerr << endl;

    ford (currank, k + 1) if (currank)
    {
        int iters = 0;

        forn (it, 2)
        {
            auto &cur = (it == 0 ? fixed : unfix);

            while (!cur.empty() && cur.rbegin() -> fst > currank)
                del_ver(cur.rbegin() -> snd);
            while (!cur.empty() && cur.rbegin() -> fst == currank)
            {
                iters++;
                del_ver(cur.rbegin() -> snd);
            }

            if (it == 1 && iters == 0)
            {
                if (!cur.empty())
                {
                    assert(cur.rbegin() -> fst < currank);
                    rk[cur.rbegin() -> snd] = currank;
                    del_ver(cur.rbegin() -> snd);
                }
                else
                {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }

    vc has(k + 1);
    for (int v : rk)
        has[v] = 1;
    if (count(all(has), 1) != k)
    {
        cout << -1 << endl;
        return;
    }
    forn (v, n) for (int to : g[v]) if (rk[v] >= rk[to])
    {
        cout << -1 << endl;
        return;
    }

    forn (i, n)
        cout << rk[i] << " \n"[i + 1 == n];
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