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

void solve (int n)
{
    const int let = 26;
    string reveal;
    cin >> reveal;
    assert(sz(reveal) == n);
    vvi poses(let);

    int know = 0;
    forn (i, n) if (reveal[i] != '*')
    {
        know |= (1 << (reveal[i] - 'a'));
        poses[reveal[i] - 'a'].pb(i);
    }

    int m;
    cin >> m;
    vector<string> words(m);
    vi has(m);
    vector<vvi> posin(m, vvi(let));

    forn (i, m)
    {
        cin >> words[i];
        assert(sz(words[i]) == n);
        forn (j, sz(words[i]))
        {
            char ch = words[i][j];
            has[i] |= (1 << (ch - 'a'));
            posin[i][ch - 'a'].pb(j);
        }
    }

    int sure = (1 << let) - 1;
    bool fnd = false;
    forn (i, m)
    {
        bool ok = true;
        forn (j, let)
        {
            if (!poses[j].empty())
                ok &= (poses[j] == posin[i][j]);
        }

        if (ok)
        {
            fnd = true;
            sure &= has[i];
        }
    }

    assert(fnd);
    sure &= (~know);
    cout << __builtin_popcount(sure) << endl;
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