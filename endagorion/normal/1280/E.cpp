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

string s;
int pos = 0;

char getChar() {
    while (pos < s.size() && s[pos] == ' ') ++pos;
    assert(pos < s.size());
    return s[pos++];
}

const int maxn = 200000;
vi e[maxn];
int type[maxn];
int dp[maxn];
vi in_ans;
int V;

int parse() {
    int v = V++;
    e[v].clear();
    char c = getChar();
    type[v] = -1;
    if (c == '*') return v;
    e[v].pb(parse());
    c = getChar();
    type[v] = int(c == 'P');
    while (1) {
        e[v].pb(parse());
        c = getChar();
        if (c == ')') break;
    }
    return v;
}

void restore(int v, int x) {
    if (type[v] == -1) in_ans.pb(x);
    else if (type[v] == 0) {
        int bu = -1;
        for (int u: e[v]) if (bu == -1 || dp[u] < dp[bu]) bu = u;
        for (int u: e[v]) restore(u, x && (u == bu));
    } else for (int u: e[v]) restore(u, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    getline(cin, s);
    while (T--) {
        getline(cin, s);
        i64 r = 0;
        pos = 0;
        while (s[pos] != ' ') r = 10 * r + s[pos] - '0', ++pos;
        V = 0;
        parse();
        ford(i, V) {
            if (type[i] == -1) dp[i] = 1;
            else if (type[i] == 0) {
                dp[i] = 1e9;
                for (int j: e[i]) uin(dp[i], dp[j]);
            } else {
                dp[i] = 0;
                for (int j: e[i]) dp[i] += dp[j];
            }
        }

        in_ans.clear();
        restore(0, 1);
        cout << "REVOLTING";
        for (int x: in_ans) cout << ' ' << x * dp[0] * r;
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}