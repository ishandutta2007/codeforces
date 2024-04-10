#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
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
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int MAXN = 100000;

int a[MAXN], b[MAXN];
int pa[MAXN], pb[MAXN];
int u[MAXN];
vector<pii> ans, ansb;

void perf(int i, int j) {
    a[i] ^= a[j];
    ans.pb(mp(i, j));
}

void perfb(int i, int j) {
    b[i] ^= b[j];
    ansb.pb(mp(i, j));
}

void swapb(int i, int j) {
    if (i == j) return;
    perfb(i, j);
    perfb(j, i);
    perfb(i, j);
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    forn(i, N) {
        cin >> a[i];
        pa[i] = a[i];
    }
    forn(i, N) {
        cin >> b[i];
        pb[i] = b[i];
    }
    vi p(30);
    ford(k, 30) {
        int x = -1;
        forn(i, N) {
            if (((a[i] >> k) & 1) && !u[i]) {  
                x = i;
                break;
            }
        }
        p[k] = x;
        if (x == -1) continue;
        u[x] = 1;
        forn(i, N) {
            if (x != i && ((a[i] >> k) & 1)) {
                perf(i, x);
            }
        }
    }

    bool ok = true;
    forn(i, N) {
        if (u[i]) continue;
        ford(j, 30) {
            if (((a[i] ^ b[i]) >> j) & 1) {
                if (p[j] == -1) ok = false;
                else perf(i, p[j]);
            }
        }
    }

    forn(k, 30) {
        if (p[k] == -1) continue;
        int x = 0;
        ford(i, 30) {
            if ((b[p[k]] >> i) & 1) {
                if (p[i] == -1) {
                    ok = false;
                    break;
                }
                b[p[k]] ^= a[p[i]];
                x ^= (1 << i);
            }
        }
        if (!ok) break;
        assert(b[p[k]] == 0);
        b[p[k]] = x;
    }

    if (ok) {
        forn(i, 30) {
            if (p[i] == -1) continue;
            a[p[i]] = 1 << i;
        }
        ford(k, 30) {
            int x = -1;
            ford(i, k + 1) {
                if (p[i] == -1) continue;
                if ((b[p[i]] >> k) & 1) {
                    x = p[i];
                    break;
                }
            }
            if (x == -1 && p[k] == -1) continue;
            if (x == -1) {
                continue;
            }
            if (p[k] == -1) {
                ok = false;
                break;
            }
            swapb(x, p[k]);
            forn(i, k) {
                if (p[i] == -1) continue;
                if ((b[p[i]] >> k) & 1) {
                    perfb(p[i], p[k]);
                }
            }
        }
        forn(i, 30) {
            if (p[i] == -1) continue;
            if (b[p[i]] == 0) {
                perfb(p[i], p[i]);
                b[p[i]] = 1 << i;
            }
            for (int k = i + 1; k < 30; ++k) {
                if (p[k] == -1) continue;
                if ((b[p[k]] >> i) & 1) perfb(p[k], p[i]);
            }
        }
        forn(i, 30) assert(p[i] == -1 || b[p[i]] == (1 << i));
    }


    reverse(all(ansb));
    forn(i, ansb.size()) ans.pb(ansb[i]);

    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }

    cout << ans.size() << '\n';
    forn(i, ans.size()) {
        cout << ans[i].fi + 1 << ' ' << ans[i].se + 1 << '\n';
        pa[ans[i].fi] ^= pa[ans[i].se];
    }
    forn(i, N) assert(pa[i] == pb[i]);


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}