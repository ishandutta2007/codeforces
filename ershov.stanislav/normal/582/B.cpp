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

const int M = 110;

struct data {
    int a[M][M];
    data() {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                a[i][j] = 0;
            }
        }
    }
};

data operator*(const data & a, const data & b) {
    data ans;
    for (int i = 0; i < M; i++) {
        for (int j = i; j < M; j++) {
            for (int k = i; k <= j; k++) {
                ans.a[i][j] = max(a.a[i][k] + b.a[k][j], ans.a[i][j]);
            }
        }
    }
    return ans;
}

data power(data a, int p) {
    data ans;
    while (p) {
        if (p & 1) {
            ans = ans * a;
        }
        a = a * a;
        p >>= 1;
    }
    return ans;
}

int n, T;
int b[M];

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d", &n, &T);
    vector<int> un;
    for (int i = 0; i < n; i++) {
        scanf("%d", b + i);
        un.pb(b[i]);
    }
    sort(all(un));
    un.resize(distance(un.begin(), unique(all(un))));
    data r;
    for (int i = 0; i < sz(un); i++) {
        for (int i2 = i; i2 < sz(un); i2++) {
            multiset<int> ms;
            for (int j = 0; j < n; j++) {
                if (b[j] >= un[i] && b[j] <= un[i2]) {
                    auto t = ms.upper_bound(b[j]);
                    if (t != ms.end()) {
                        ms.erase(t);
                    }
                    ms.insert(b[j]);
                }
            }
            r.a[i][i2] = sz(ms);
        }
    }
    r = power(r, T);
    printf("%d\n", r.a[0][sz(un) - 1]);
    return 0;
}