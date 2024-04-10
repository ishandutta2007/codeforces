#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int MAXN = 200000;
int la[MAXN], ra[MAXN];
char lb[MAXN], rb[MAXN];

string vowel;

bool isvowel(char c) {
    return vowel[c - 'a'] == 'V';
}

const int MAXV = 400;
vi e[MAXV], re[MAXV];
int comp[MAXV], vis[MAXV];

void addEdge(int v, int u) {
    e[v].pb(u);
    e[u ^ 1].pb(v ^ 1);
    re[u].pb(v);
    re[v ^ 1].pb(u ^ 1);
}

void delEdge(int v, int u) {
    e[v].pop_back();
    e[u ^ 1].pop_back();
    re[u].pop_back();
    re[v ^ 1].pop_back();
}

void dfs_ord(int v, vi &ord) {
    if (vis[v]) return;
    vis[v] = 1;
    for (int u: e[v]) dfs_ord(u, ord);
    ord.pb(v);
}

bool dfs_re(int v, int c) {
    if (vis[v]) return true;
    vis[v] = 1;
    comp[v] = c;
    if (vis[v ^ 1] && comp[v] == comp[v ^ 1]) return false;
    for (int u: re[v]) if (!dfs_re(u, c)) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> vowel;
    int alpha = vowel.size();
    int N, M;
    cin >> N >> M;
    forn(i, M) {
        cin >> la[i] >> lb[i] >> ra[i] >> rb[i];
        --la[i]; --ra[i];
        addEdge(2 * la[i] + (lb[i] == 'V'), 2 * ra[i] + (rb[i] == 'V'));
        addEdge(2 * ra[i] + (rb[i] != 'V'), 2 * la[i] + (lb[i] != 'V'));
    }
    string s;
    cin >> s;
    int i = N - 1;
    --s[i];
    for (; i >= 0; --i) {
        bool trv = false, trc = false;
        bool won = false;
        for (++s[i]; s[i] < 'a' + alpha; ++s[i]) {
            if (isvowel(s[i]) && trv || !isvowel(s[i]) && trc) continue;
            //forn(j, 2 * N) e[j].clear(), re[j].clear();
            forn(j, i + 1) addEdge(2 * j + !isvowel(s[j]), 2 * j + isvowel(s[j]));
            forn(j, 2 * N) vis[j] = 0;
            vi ord;
            forn(j, 2 * N) dfs_ord(j, ord);
            reverse(all(ord));
            forn(j, 2 * N) vis[j] = 0;
            int cc = 0;
            bool ok = true;
            for (int x: ord) if (!vis[x]) {
                if (!dfs_re(x, cc++)) {
                    ok = false;
                    break;
                }
            }
            forn(j, i + 1) delEdge(2 * j + !isvowel(s[j]), 2 * j + isvowel(s[j]));
            if (ok) {
                won = true;
                break;
            } else {
                (isvowel(s[i]) ? trv : trc) = true;
            }
        }
        if (won) break;
    }
    cerr << i << '\n';
    if (i < 0) {
        cout << "-1\n";
    } else {
        for (++i; i < N; ++i) {
            bool trv = false, trc = false;
            bool won = false;
            for (s[i] = 'a'; s[i] < 'a' + alpha; ++s[i]) {
                if (isvowel(s[i]) && trv || !isvowel(s[i]) && trc) continue;
    //            forn(j, 2 * N) e[j].clear(), re[j].clear();
                forn(j, i + 1) addEdge(2 * j + !isvowel(s[j]), 2 * j + isvowel(s[j]));
                forn(j, 2 * N) vis[j] = 0;
                vi ord;
                forn(j, 2 * N) dfs_ord(j, ord);
                reverse(all(ord));
                forn(j, 2 * N) vis[j] = 0;
                int cc = 0;
                bool ok = true;
                for (int x: ord) if (!vis[x]) {
                    if (!dfs_re(x, cc++)) {
                        ok = false;
                        break;
                    }
                }
                forn(j, i + 1) delEdge(2 * j + !isvowel(s[j]), 2 * j + isvowel(s[j]));
                if (ok) {
                    won = true;
                    break;
                } else {
                    (isvowel(s[i]) ? trv : trc) = true;
                }
            }
//            assert(won);
            if (!won) {
                cout << "-1\n";
                return 0;
            }
        }
        cout << s << '\n';
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}