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

const int maxl = 510000;
const int HC = 3;
i64 P[HC] = {1000000000 + 7, 123454349, 234567899};
i64 p10[HC][maxl + 1];

struct THash {
    int len;
    i64 h[HC];

    THash(i64 x = 0) : len(x ? 1 : 0)
    {
        forn(z, HC) h[z] = x % P[z];
    }

    THash operator+(const THash &r) const {
        THash res;
        res.len = len + r.len;
        forn(z, HC) res.h[z] = (h[z] * p10[z][r.len] + r.h[z]) % P[z];
        return res;
    }

    THash operator-(const THash &r) const {
        THash res;
        res.len = len - r.len;
        forn(z, HC) {
            res.h[z] = (h[z] - r.h[z] * p10[z][len - r.len]) % P[z];
            if (res.h[z] < 0) res.h[z] += P[z];
        }
        return res;
    }

    bool operator==(const THash &r) const {
        if (len != r.len) return false;
        forn(z, HC) if (h[z] != r.h[z]) return false;
        return true;
    }
};

vector<THash> phash(const string &s) {
    int n = s.size();
    vector<THash> ph(n + 1);
    forn(i, n) ph[i + 1] = ph[i] + THash(s[i] - '0');
    return ph;
}

bool match(const THash &p1, const THash &p2, const THash &p3) {
    forn(z, HC) {
//        cerr << (p1.h[z] + p2.h[z] - p3.h[z]) % P[z] << '\n';
        if ((p1.h[z] + p2.h[z] - p3.h[z]) % P[z]) return false;
    }
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

    forn(z, HC) {
        p10[z][0] = 1;
        forn(i, maxl) p10[z][i + 1] = p10[z][i] * 10 % P[z]; 
    }

    string s, x;
    cin >> s >> x;
    int n = s.size(), m = x.size();

    auto ps = phash(s), px = phash(x);

    int bl = -1, bm = -1, br = -1;
    auto try_match = [&](int l, int m, int r) {
        if (l < 0 || r > n) return;
        if (l >= m || m >= r) return;
//        cerr << l << ' ' << m << ' ' << r << '\n';
        if (match(ps[m] - ps[l], ps[r] - ps[m], px.back())) {
            bl = l, bm = m, br = r;
        }
    };

    forn(i, n - 2 * (m - 1) + 1) {
//        cerr << i << '\n';
        try_match(i, i + m - 1, i + 2 * (m - 1));
    }

//    cerr << "here\n";
    forn(i, n) {
        int L = 0, R = min(n - i, m) + 1;
        while (R - L > 1) {
            int M = (L + R) / 2;
            (px[M] == ps[i + M] - ps[i] ? L : R) = M;
        }
//        cerr << i << ' ' << L << '\n';
        forn(z, 2) {
            int len = m - L - z;
            if (len < 0) continue;
            try_match(i - len, i, i + m);
            try_match(i, i + m, i + m + len);
        }
    }
    assert(bl != -1);
    cout << bl + 1 << ' ' << bm << '\n';
    cout << bm + 1 << ' ' << br << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}