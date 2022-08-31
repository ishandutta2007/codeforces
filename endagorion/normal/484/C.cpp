#include <iostream>
#include <vector>
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

int LOG = 0;
pii up[21][1000000];

pii get_up(int i, int n) {
    int l = 0;
    ford(k, LOG + 1) {
        if ((1 << k) > n) continue;
        if (up[k][i].fi == -1) return mp(-1, up[k][i].second + l);
        n -= (1 << k);
        l += 1 << k;
        i = up[k][i].fi;
    }
    return mp(i, l);
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    string s;
    cin >> s;
    int N = s.size();
    while ((1 << LOG) < N) ++LOG;
    int T;
    cin >> T;
    forn(t, T) {
        int K, D;
        cin >> K >> D;
        int q = -1;
        for (int k = 0; k < D; ++k) {
            for (int i = k; i < K; i += D) {
                up[0][i] = mp(q++, 1);
            }
        }
        for1(k, LOG) forn(i, K) {
            if (up[k - 1][i].fi == -1) up[k][i] = up[k - 1][i];
            else {
                up[k][i] = up[k - 1][up[k - 1][i].fi];
                up[k][i].se += up[k - 1][i].se;
            }
        }
        string ss(N, '.');
        forn(i, K) {
            pii r = get_up(i, N - K + 1);
            if (r.fi == -1) ss[r.se - 1] = s[i];
            else ss[N - K + 1 + r.fi] = s[i];
        }
        for (int i = K; i < N; ++i) {
            pii r = get_up(K - 1, N - i);
            if (r.fi == -1) ss[i - K + r.se] = s[i];
            else ss[N - K + 1 + r.fi] = s[i];
        }
        s = ss;
//        cout << s << '\n';
        printf("%s\n", s.c_str());
    }
                
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}