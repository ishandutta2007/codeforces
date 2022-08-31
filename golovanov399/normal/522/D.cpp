#include "bits/stdc++.h"

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

#define next next12345
#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const long double PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int c;
    a = 0;
    while (!isdigit(c = getchar()) && c != '-') {}
    char neg = 0;
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        a = 10 * a + c - '0';
        c = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

const int N = 500000;

vector <long long> st[N + N];

long long msk = (1ll << 20) - 1;

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "a"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt();
    int m = nxt();

    int a[n];
    int b[n];
    for (int i = 0; i < n; ++i) {
        a[i] = b[i] = nxt();
    }
    sort(b, b + n);
    int sz = unique(b, b + n) - b;
    long long next[sz];
    memset(next, 0x3f, sizeof(next));
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(b, b + sz, a[i]) - b;
    }

    for (int i = n - 1; i >= 0; --i) {
        if (next[a[i]] < n) st[i + n].push_back((next[a[i]] << 20) | (next[a[i]] - i));
        next[a[i]] = i;
    }

    for (int i = n - 1; i > 0; --i) {
        merge(all(st[i + i]), all(st[i + i + 1]), back_inserter(st[i]));
        long long cur = LLONG_MAX;
        for (int j = 0; j < (int)st[i].size(); ++j) {
            cur = min(cur, st[i][j] & msk);
            st[i][j] &= (~msk);
            st[i][j] |= cur;
        }
    }

    while (m--) {
        int l = nxt() - 1;
        int r = nxt() - 1;
        long long res = LLONG_MAX;
        long long d = ((long long)r + 1) << 20;
        for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if (l & 1) {
                int pos = lower_bound(all(st[l]), d) - st[l].begin();
                if (pos != 0) {
                    res = min(res, st[l][pos - 1] & msk);
                }
            }
            if (!(r & 1)) {
                int pos = lower_bound(all(st[r]), d) - st[r].begin();
                if (pos != 0) {
                    res = min(res, st[r][pos - 1] & msk);
                }
            }
        }
        if (res == LLONG_MAX) {
            res = -1;
        }
        cout << res << "\n";
    }


#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}