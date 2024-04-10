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

const int ALPHABET = 10;

struct state {
    array<int, ALPHABET> transition = {};
    int link = 0;
    int depth;
    
    bool isTerminal = false;
};

struct automaton {
    vector<state> states = { state() };
    int numStates = 1;
    
    void addString(const string& s) {
        int cur = 0;
        int D = 0;
        for (char c: s) {
            c -= '0';
            int& to = states[cur].transition[c];
            ++D;
            if (to) {
                cur = to;
            }
            else {
                cur = to = states.size();
                states.push_back(state());
                states[cur].depth = D;
            }
        }
        states[cur].isTerminal = true;
    }
    
    void build() {
        deque<int> q;
        q.push_back(0);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            states[v].isTerminal = states[v].isTerminal || states[states[v].link].isTerminal;
            
            for (int c = 0; c < ALPHABET; ++c) {
                if (int u = states[v].transition[c]) {
                    states[u].link = v ? states[states[v].link].transition[c] : 0;
                    q.push_back(u);
                }
                else {
                    states[v].transition[c] = states[states[v].link].transition[c];
                }
            }
        }
    }
};

automaton aut;

const int maxs = 100000;
i64 dp[2][2][2][maxs];

int lb;

const i64 P = 1000000000 + 7;

void add(i64 &x, i64 y) {
    x += y;
    if (x >= P) x -= P;
}

i64 solve(string s, bool eq) {
    int S = aut.states.size();
    forn(z, 2) forn(x, 2) forn(y, 2) forn(i, S) dp[z][x][y][i] = 0;
    dp[0][0][0][0] = 1;
    for (char c: s) {
        int sd = c - '0';
        forn(x, 2) forn(y, 2) forn(i, S) {
            if (!dp[0][x][y][i]) continue;
            forn(d, 10) {
                if (!x && d > sd) break;
                int nx = x | int(d < sd);
                int ni = aut.states[i].transition[d];
                int ny = y | int(aut.states[ni].depth == lb);
                add(dp[1][nx][ny][ni], dp[0][x][y][i]);
            }
        }

        forn(x, 2) forn(y, 2) forn(i, S) {
            dp[0][x][y][i] = dp[1][x][y][i];
            dp[1][x][y][i] = 0;
        }
    }

    i64 ans = 0;
    forn(i, S) {
        add(ans, dp[0][1][1][i]);
        if (eq) add(ans, dp[0][0][1][i]);
    }
//    cerr << s << ' ' << eq << ' ' << ans << '\n';
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    string s;
    string a, b;
    cin >> s >> a >> b;
    lb = a.size() / 2;
    forn(i, s.size() - lb + 1) aut.addString(string(s.begin() + i, s.begin() + i + lb));
    aut.build();

    i64 ans = solve(b, true) - solve(a, false);
    ans %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}