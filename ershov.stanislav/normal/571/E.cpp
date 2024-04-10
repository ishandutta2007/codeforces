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

const int N = 111;
int n;
int a[N], b[N];
map<int, ll> pa[N], pb[N];
const int MOD = 1e9 + 7;

void makenotcollinear(int i, int p1, int p2) {
    ll x1 = pa[0][p1], y1 = pa[0][p2];
    ll dx1 = pb[0][p1], dy1 = pb[0][p2];
    ll x2 = pa[i][p1], y2 = pa[i][p2];
    ll dx2 = pb[i][p1], dy2 = pb[i][p2];
    ll normx = -dy2, normy = dx2;
    ll want = (x2 - x1) * normx + (y2 - y1) * normy;
    ll step = dx1 * normx + dy1 * normy;
    assert(step != 0);
    ll mult = want / step;
    for (auto j : pb[i]) {
        pa[0][j.fs] += pb[0][j.fs] * mult;
    }
}

int power(int a, ll p) {
    int res = 1;
    for (; p; p >>= 1) {
        if (p & 1) {
            res = (res * 1ll * a) % MOD;
        }
        a = (a * 1ll * a) % MOD;
    }
    return res;
}

ll prod(ll a, ll b, ll curmod) {
    ll res = 0;
    bool flag = false;
    if (b < 0) {
        b = -b;
        flag = true;
    }
    for (; b; b >>= 1) {
        if (b & 1) {
            res = (res + a) % curmod;
        }
        a = a * 2 % curmod;
    }
    if (flag) {
        res = -res;
    }
    return res;
}

ll gcdExt(ll a, ll b, ll & M, ll & N) {
    if (b == 0) {
        M = 1;
        N = 0;
        return a;
    } else {
        ll k = a / b;
        ll res = gcdExt(b, a - k * b, M, N);
        swap(M, N);
        N -= k * M;
        return res;
    }
}

void solve() {
    bool ok = true;
    for (int i = 1; i < n && ok; i++) {
        vector<int> primes;
        for (auto j : pa[0]) {
            primes.pb(j.fs);
        }
        for (auto j : pa[i]) {
            primes.pb(j.fs);
        }
        for (auto j : pb[i]) {
            primes.pb(j.fs);
        }
        ll mult = -1;
        for (auto j : primes) {
            ll want = pa[0][j];
            ll have = pa[i][j];
            if (pb[i][j] == 0) {
                if (have != want) {
                    ok = false;
                    break;
                }
            } else {
                if (mult != -1) {
                    if (mult * pb[i][j] + have != want) {
                        ok = false;
                        break;
                    }
                } else {
                    mult = (want - have) / pb[i][j];
                    if (mult < 0 || mult * pb[i][j] + have != want) {
                        ok = false;
                        break;
                    }
                }
            }
        }
    }
    if (ok) {
        int ans = 1;
        for (auto i : pa[0]) {
            ans = ans * 1ll * power(i.fs, i.sc) % MOD;
        }
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
}

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", a + i, b + i);
        if (b[i] != 1) {
            swap(a[i], a[0]);
            swap(b[i], b[0]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 2; j * j <= a[i]; j++) {
            while (a[i] % j == 0) {
                a[i] /= j;
                pa[i][j]++;
            }
        }
        if (a[i] > 1) {
            pa[i][a[i]]++;
        }
        for (int j = 2; j * j <= b[i]; j++) {
            while (b[i] % j == 0) {
                b[i] /= j;
                pb[i][j]++;
            }
        }
        if (b[i] > 1) {
            pb[i][b[i]]++;
        }
    }
    int p1 = 2, p1cnt = 0;
    for (auto i : pb[0]) {
        if (i.sc != 0) {
            p1 = i.fs;
            p1cnt = i.sc;
        }
    }
    bool collinear = true;
    for (int i = 1; i < n; i++) {
        int cur = pb[i][p1];
        for (auto j : pb[i]) {
            if (pb[0][j.fs] * cur != j.sc * p1cnt) {
                makenotcollinear(i, p1, j.fs);
                collinear = false;
            }
        }
        for (auto j : pb[0]) {
            if (j.sc * cur != pb[i][j.fs] * p1cnt) {
                makenotcollinear(i, p1, j.fs);
                collinear = false;
            }
        }
    }
    if (!collinear) {
        solve();
    } else {
        ll a = pa[0][p1];
        ll b = pb[0][p1];
        if (b == 0) {
            solve();
        } else {
            a %= b;
            bool ok = true;
            for (int i = 1; i < n; i++) {
                ll c = pb[i][p1];
                if (c == 0) {
                    if (a != pa[i][p1] % b) {
                        ok = false;
                        break;
                    } else {
                        a = pa[i][p1];
                        continue;
                    }
                }
                ll M, N;
                ll g = gcdExt(b, c, M, N);
                ll d = pa[i][p1];
                if (a % g != d % g) {
                    ok = false;
                    break;
                }
                ll lcm = b / g * c;
                ll na = prod(M, b, lcm);
                na = prod(na, (d % c - a % c) / g, lcm);
                na += a;
                na %= lcm;
                if (na < 0) {
                    na += lcm;
                }
                a = na;
                b = lcm;
            }
            if (!ok) {
                printf("-1\n");
            } else {
                for (int i = 0; i < n; i++) {
                    while (pa[i][p1] > a) {
                        a += pb[i][p1];
                    }
                }
                ll add = (a - pa[0][p1]) / pb[0][p1];
                for (auto & i : pa[0]) {
                    i.sc += pb[0][i.fs] * add;
                }
                solve();
            }
        }
    }
    return 0;
}