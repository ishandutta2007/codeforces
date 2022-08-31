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


long long mod = 1000000007;

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long A[1000000], B[1000000];

long long C[1000000], D[1000000];

long long P[1000000], Q[1000000];

long long mod1 = 1000000007;

long long mod2 = 1000000009;

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
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;


    long long q = 31;

    long long v1 = 1;
    long long v2 = 1;

    P[n] = 1, Q[n] = 1;

    for (int i = n - 1; i >= 0; --i) {
        A[i] = (A[i + 1] + v1 * (s[i] - 'a' + 1)) % mod1;
        B[i] = (B[i + 1] + v2 * (s[i] - 'a' + 1)) % mod2;
        C[i] = (C[i + 1] + v1 * (t[i] - 'a' + 1)) % mod1;
        D[i] = (D[i + 1] + v2 * (t[i] - 'a' + 1)) % mod2;
        P[i] = (q * P[i + 1]) % mod1;
        Q[i] = (q * Q[i + 1]) % mod2;
        v1 = (v1 * q) % mod1;
        v2 = (v2 * q) % mod2;
    }

    vector <long long> U, V;

    long long aa = 0, bb = 0, cc = 0, dd = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= 26; ++j) {
            long long XX = ((aa * q + j) % mod1 * P[i] + A[i]) % mod1;
            long long YY = ((bb * q + j) % mod2 * Q[i] + B[i]) % mod2;
            U.push_back((XX << 30) | YY);

            XX = ((cc * q + j) % mod1 * P[i] + C[i]) % mod1;
            YY = ((dd * q + j) % mod2 * Q[i] + D[i]) % mod2;
            V.push_back((XX << 30) | YY);
        }
        if (i == n) break;
        aa = (aa * q + s[i] - 'a' + 1) % mod1;
        bb = (bb * q + s[i] - 'a' + 1) % mod2;

        cc = (cc * q + t[i] - 'a' + 1) % mod1;
        dd = (dd * q + t[i] - 'a' + 1) % mod2;
    }

    sort(all(U));
    sort(all(V));
    U.erase(unique(all(U)), U.end());
    V.erase(unique(all(V)), V.end());

    vector <long long> buf;

    set_intersection(all(U), all(V), back_inserter(buf));


    cout << buf.size() << "\n";
#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}