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

const int maxn = 5e5 + 100;

struct point {
    ll x, y;
    point (ll x = 0, ll y = 0) : x(x), y(y) {}
};

ll operator^(const point & a, const point & b) {
    return a.x * b.y - a.y * b.x;
}
ll operator*(const point & a, const point & b) {
    return a.x * b.x + a.y * b.y;
}

ll slen(const point & a) {
    return a.x * a.x + a.y * a.y;
}

bool operator<(const point & a, const point & b) {
    return (a.x != b.x) ? (a.x < b.x) : a.y < b.y;
}

bool mycomp(const point & a, const point & b) {
    if ((a ^ b) != 0) {
        return (a ^ b) > 0;
    } else {
        if (a * b < 0) {
            return true;
        } else {
            return slen(a) < slen(b);
        }
    }
}

vector<point> l, r, all;
vector<point> v;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    srand(time(0));
    int n, c, d;
    scanf("%d%d%d", &n, &c, &d);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= c;
        b -= d;
        point cur(a, b);
        v.pb(cur);
        if (cur * point(1, (int) 2e9 + 100) < 0) {
            l.pb(cur);
        } else {
            r.pb(cur);
        }
    }
    sort(all(l), mycomp);
    sort(all(r), mycomp);
    for (int i = 0; i < sz(l); i++) {
        all.pb(l[i]);
    }
    for (int i = 0; i < sz(r); i++) {
        all.pb(r[i]);
    }

    for (int i = 0; i < n; i++) {
        all.pb(all[i]);
    }
    ll ans = 0;
    for (int i = 0, j = 1; i < n; i++) {
        j = max(j, i + 1);
        while (j < i + n && mycomp(all[i], all[j])) {
            j++;
        }
//        cout << i << ' ' << j << ' ' << k << endl;
        ans += (j - i - 1) * 1ll * (j - i - 2) / 2;
    }
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++) {
        point cur = all[i];
        int g = gcd(abs(cur.x), abs(cur.y));
        cur.x /= g;
        cur.y /= g;
        cnt[mp((int) cur.x, (int) cur.y)]++;
    }
    for (auto i : cnt) {
        ans -= i.sc * 1ll * cnt[mp(-i.fs.fs, -i.fs.sc)] * 1l * (cnt[mp(-i.fs.fs, -i.fs.sc)] - 1) / 2;
    }
    ans = n * 1ll * (n - 1) / 2 * 1ll * (n - 2) / 3 - ans;
    cout << ans << endl;
    return 0;
}