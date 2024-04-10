#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 10000;

string s;
ll a[N];
char c[N];
pair<ll, ll> l[N], r[N];

pair<ll, ll> add(ll a, char c, pair<ll, ll> p) {
    if (c == '+') {
        p.fs += p.sc;
        p.sc = a;
    } else {
        p.sc *= a;
    }
    return p;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    cin >> s;
    int cnt = 1;
    for (int i = 0, cur = 0; i < (int) s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a[cur] *= 10;
            a[cur] += s[i] - '0';
        } else {
            c[cur] = s[i];
            cur++;
            cnt++;
        }
    }

    l[0] = mp(0, 0);
    for (int i = 0; i < cnt; i++) {
        if (i == 0) {
            l[i + 1] = add(a[i], '+', l[0]);
        } else {
            l[i + 1] = add(a[i], c[i - 1], l[i]);
        }
    }
    r[0] = mp(0, 0);
    for (int i = cnt - 1, j = 1; i >= 0; i--, j++) {
        if (i == cnt - 1) {
            r[j] = add(a[i], '+', r[0]);
        } else {
            r[j] = add(a[i], c[i], r[j - 1]);
        }
    }

    ll ans = l[cnt].fs + l[cnt].sc;

    for (int i = 0; i < cnt; i++) {
        pair<ll, ll> p = mp(0, a[i]);
        for (int j = i + 1; j < cnt; j++) {
            p = add(a[j], c[j - 1], p);
            ll pp = p.fs + p.sc;
            pair<ll, ll> p1, p2;
            if (i > 0) {
                p1 = add(pp, c[i - 1], l[i]);
            } else {
                p1 = mp(0, pp);
            }
            p2 = mp(0, 0);
            if (j < cnt - 1) {
                p2 = r[cnt - 1 - j];
            }
            if (c[j] == '*') ans = max(ans, p1.fs + p1.sc * p2.sc + p2.fs);
            else ans = max(ans, p1.fs + p2.fs + p1.sc + p2.sc);
        }
    }

    cout << ans << endl;

    return 0;
}