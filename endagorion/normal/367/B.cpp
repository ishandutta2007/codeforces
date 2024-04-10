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

typedef unsigned long long ull;

const int maxn = 300000;

int a[maxn], b[maxn];

struct THash {
    ull s1, s2, s3, s4, s12;

    THash()
        : s1(0)
        , s2(0)
        , s3(0)
        , s4(0)
        , s12(0)
    {
    }

    void add(ull a) {
        s1 += a;
        s2 += a * a;
        s3 += a * a * a;
        s4 += a * a * a * a;
        s12 += (ull)(sqrt(1.0 * a));
    }

    void rem(ull a) {
        s1 -= a;
        s2 -= a * a;
        s3 -= a * a * a;
        s4 -= a * a * a * a;
        s12 -= (ull)(sqrt(1.0 * a));
    }

    bool operator==(const THash &h) const {
        return s1 == h.s1 && s2 == h.s2 && s3 == h.s3 && s4 == h.s4 && s12 == h.s12;
    }
};

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M, P;
    scanf("%d%d%d", &N, &M, &P);
    forn(i, N) {
        scanf("%d", &a[i]);
    }
    THash hb;
    forn(i, M) {
        scanf("%d", &b[i]);
        hb.add(b[i]);
    }
    set<int> ans;
    forn(i, P) {
        if (i + 1LL * (M - 1) * P >= N) {
            continue;
        }
        THash h;
        forn(j, M) {
            h.add(a[i + j * P]);
        }
        if (h == hb) {
            ans.insert(i);
        }
        int k = i + M * P;
        while (k < N) {
            h.rem(a[k - M * P]);
            h.add(a[k]);
            if (h == hb) {
                ans.insert(k - (M - 1) * P);
            }
            k += P;
        }
    }
    cout << ans.size() << '\n';
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        cout << *it + 1 << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}