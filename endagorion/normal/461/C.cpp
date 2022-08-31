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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int MAXN = 200000;
int fenw[MAXN];

int N;

int fenwsum(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i) {
        ans += fenw[i];
    }
    return ans;
}

void fenwadd(int i, int x) {
    for (; i <= N; i |= i + 1) {
        fenw[i] += x;
    }
}

int fenwget(int i) {
    return fenwsum(i) - fenwsum(i - 1);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);
    int Q;
    cin >> N >> Q;
    forn(i, N) fenwadd(i, 1);
    int b = 0, d = 1, l = N;
    forn(q, Q) {
        int t;
        cin >> t;
//        cerr << b << ' ' << d << ' ' << l << '\n';
        if (t == 1) {
            int p;
            cin >> p;
            if (2 * p > l) {
                b = b + d * (l - 1);
                d = -d;
                p = l - p;
            }
            forn(i, p) {
                int x = fenwget(b + i * d);
                fenwadd(b + (2 * p - i - 1) * d, x);
            }
            b += p * d;
            l -= p;
        } else {
            int l, r;
            cin >> l >> r;
            if (d == 1) cout << fenwsum(b + r - 1) - fenwsum(b + l - 1) << '\n';
            else cout << fenwsum(b - l) - fenwsum(b - r) << '\n';
        }
/*        forn(i, l) cout << fenwget(b + i * d) << ' ';
        cout << '\n';*/
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}