
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

const int N = 2e5 + 100;

int n;
int a[N];
ll ans[N];
int g[N];

int gcd(int a, int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        g[i] = gcd(i, n);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    vector<int> dels;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            dels.pb(i);
            if (n != i * i) {
                dels.pb(n / i);
            }
        }
    }
    sort(all(dels));
    for (auto cur : dels) {
        vector<int> mx(cur, 0);
        for (int j = 0; j < cur; j++) {
            for (int i = j; i < n; i += cur) {
                mx[j] = max(mx[j], a[i]);
            }
        }
        vector<int> v;
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == mx[i % cur]) {
                r++;
            } else {
                if (r > 0) {
                    v.pb(r);
                    r = 0;
                }
            }
        }
        if (r > 0) {
            if (sz(v) >= 1 && a[0] == mx[0]) {
                v[0] += r;
            } else {
                v.pb(r);
            }
        }
//        for (auto i : v) {
//            cout << i << ' ';
//        }
//        cout << endl;
        if (v[0] != n) {
            for (auto i : v) {
                for (int j = cur; j <= i; j += cur) {
                    if (g[j] == cur) {
                        ans[j] += i - j + 1;
                    }
                }
            }
        } else {
            for (int j = cur; j <= v[0]; j += cur) {
                if (g[j] == cur) {
                    ans[j] += v[0];
                }
            }
        }
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += ans[i];
    }
    printf(LLD "\n", res);
    return 0;
}