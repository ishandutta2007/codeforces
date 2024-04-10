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
    scanf("%d", &n);
    vector<int> a(n), p(n);
    vector<vector<int> > ar(n);
    for (int i = 0; i < n; i++){
        scanf("%d%d", &p[i], &a[i]);
        p[i]--;
        if (p[i] >= 0)
            ar[p[i]].push_back(i);
    }

    long long inf = LLONG_MIN / 3;


    long long ans[n][2];

    for (int x = n - 1; x >= 0; x--){
        long long dp[2];
        dp[0] = 0, dp[1] = inf;

        for (auto q : ar[x]) {
            long long tmp[2];
            tmp[0] = tmp[1] = inf;
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    tmp[j ^ k] = max(tmp[j ^ k], dp[j] + ans[q][k]);
                }
            }
            dp[0] = tmp[0];
            dp[1] = tmp[1];
        }

        ans[x][1] = max(dp[0] + a[x], dp[1]);
        ans[x][0] = dp[0];
    }

    cout << max(ans[0][0], ans[0][1]) << "\n";
#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}