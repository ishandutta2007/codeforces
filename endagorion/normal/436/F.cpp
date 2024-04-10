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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int maxn = 100500;
const int bsize = 500;
const int maxb = maxn / bsize;
i64 y[maxn];
i64 add[maxb];
vector<int> conv[maxb];

void rebuild(int b) {
    conv[b].clear();
    conv[b].pb(b * bsize);
    for (int x = b * bsize + 1; x < (b + 1) * bsize; ++x) {
        while (conv[b].size() > 1) {
            int px = conv[b].back(), ppx = conv[b][conv[b].size() - 2];
            if ((px - ppx) * (y[x] - y[px]) - (x - px) * (y[px] - y[ppx]) >= 0) {
                conv[b].pop_back();
            } else {
                break;
            }
        }
        conv[b].pb(x);
    }
}

pair<i64, int> findMax(int b) {
    assert(conv[b].size() > 1);
    {
        int x = conv[b][0], xx = conv[b][1];
        if (y[x] + add[b] * x > y[xx] + add[b] * xx) return mp(y[x] + add[b] * x, x);
    }
    int l = 0, r = conv[b].size() - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int x = conv[b][m], xx = conv[b][m + 1];
        if (y[x] + add[b] * x < y[xx] + add[b] * xx) l = m;
        else r = m;
    }
    int bx = conv[b][l + 1];
    return mp(y[bx] + add[b] * bx, bx);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);
    int N, W;
    cin >> N >> W;
    vector<pii> a(N);
    forn(i, N) cin >> a[i].second >> a[i].first;
    sort(all(a));
    int B = a.back().first;
    forn(i, maxb) rebuild(i);
    int i = 0;
    cout << "0 0\n";
    for (int c = 1; c <= B + 1; ++c) {
        while (i < a.size() && a[i].first < c) {
            int x = a[i].second;
            forn(b, maxb) {
                if ((b + 1) * bsize <= x) ++add[b];
                else if (b * bsize <= x) {
                    for (int j = b * bsize; j <= x; ++j) {
                        y[j] += j;
                    }
                    rebuild(b);
                }
            }
            ++i;
        }
        pair<i64, int> res = mp(-1LL, -1);
        forn(j, maxb) {
            res = max(res, findMax(j));
        }
        res.first += 1LL * (N - i) * c * W;
        cout << res.first << ' ' << res.second <<'\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}