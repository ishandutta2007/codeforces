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

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
    int ans = a + b;
    if (ans >= MOD) {
        ans -= MOD;
    }
    return ans;
}

int mult(int a, int b) {
    return (ll) a * b % MOD;
}

int power(int a, ll p) {
    int ans = 1;
    while (p) {
        if (p & 1) {
            ans = mult(ans, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return ans;
}

int inv(int a) {
    assert(a != 0);
    return power(a, MOD - 2);
}

const int maxn = 5e5;

int cnt[maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int cur;
        scanf("%d", &cur);
        cnt[cur]++;
    }
    int ans = 1;
    int topower = 1;
    for (int i = 2; i < maxn; i++) {
        if (cnt[i] != 0) {
            ans = power(ans, cnt[i] + 1);
            ans = mult(ans, power(power(i, (ll) cnt[i] * (ll) (cnt[i] + 1) / 2), topower));
            topower = (ll) topower * (cnt[i] + 1) % (MOD - 1);
        }
    }
    printf("%d\n", ans);
    return 0;
}