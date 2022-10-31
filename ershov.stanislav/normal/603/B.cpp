#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int MOD = (int) 1e9 + 7;

int mult(int a, int b, int m) {
    return (ll) a * b % m;
}

int power(int a, int p, int m) {
    int ans = 1;
    while (p) {
        if (p & 1) {
            ans = mult(ans, a, m);
        }
        p >>= 1;
        a = mult(a, a, m);
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int p, k;
    scanf("%d%d", &p, &k);
    int ans = 1;
    if (k == 0) {
        ans = mult(ans, power(p, p - 1, MOD), MOD);
    }
    if (k > 0) {
        int mn = -1;
        for (int cur = k, i = 1; ; i++) {
            if (cur == 1) {
                mn = i;
                break;
            }
            cur = mult(cur, k, p);
        }
        ans = mult(ans, power(p, (p - 1) / mn, MOD), MOD);
    }
    if (k == 1) {
        ans = mult(ans, p, MOD);
    }
    printf("%d\n", ans);
    return 0;
}