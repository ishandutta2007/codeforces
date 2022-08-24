#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

vi ans;
int lazy = 0;
multiset<int> m;

void change(int i, int delta) {
    if (m.find(ans[i]) != m.end()) m.erase(m.find(ans[i]));
    ans[i] += delta;
    m.insert(ans[i]);
}

int except(int x) {
    if (ans[x] == *m.rbegin()) return *++m.rbegin();
    else return *m.rbegin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    ans.resize(n + 1, -1e9);
    ans[0] = 0;
    m = {0};
    int y = 0;
    forn(i, n) {
        int x;
        cin >> x;
        if (x != y) {
            int xy = max(ans[x], except(x) + 1);
            ++lazy; --xy;
            if (xy > ans[y]) change(y, xy - ans[y]);
        } else {
            int xx = max(ans[x], except(x) + 1);
//            cerr << x << ' ' << xx << '\n';
            if (xx > ans[x]) change(x, xx - ans[x]);
        }
        y = x;
    }

    cout << *m.rbegin() + lazy << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}