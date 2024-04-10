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

const int N = 400;

vector <int> g[N];

int dp[N];

int solve(int x) {
    int & res = dp[x];
    if (res != -1) {
        return res;
    }
    res = 1;
    for (int v : g[x]) {
        res = max(res, 1 + solve(v));
    }
    return res;
}

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
    memset(dp, 255, sizeof(dp));

    int k = nxt();

    map <string, int> id;

    id["polycarp"] = 0;

    int sz = 1;

    for (int i = 0; i < k; ++i) {
        string a, b, c;
        cin >> a >> b >> c;
        for (char & d : a) {
            d = tolower(d);
        }
        for (char & d : c) {
            d = tolower(d);
        }
        int A = id.count(a) ? id[a] : (id[a] = sz++);
        int B = id.count(c) ? id[c] : (id[c] = sz++);
        //cout << A << " " << B << "\n";
        g[B].push_back(A);
    }

    cout << solve(0) << endl;

#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}