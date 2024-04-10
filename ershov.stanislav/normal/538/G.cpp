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

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 100;
const ll lINF = 4e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

struct magic{
    ll t, x, y, d;
    magic(ll t = 0, ll x = 0, ll y = 0, ll d = 0) : t(t), x(x), y(y), d(d) {}

    bool operator<(magic b) {
        return t < b.t;
    }
    magic operator-(magic b) {
        return magic(t - b.t, x - b.x, y - b.y, d - b.d);
    }
};

int n, l;
vector<magic> v;

ll divll(ll a, ll b) {
    ll ans = a / b;
    if (ans * b > a) {
        ans--;
    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &l);

    v.resize(n);
    v.eb(0, 0, 0, 0);
    v.eb(l, 0, 0, 1);

    for (int i = 0; i < n; i++) {
        ll t;
        scanf(LLD LLD LLD, &t, &v[i].x, &v[i].y);
        v[i].t = t % l;
        v[i].d = -(t / l);
    }

    sort(v.begin(), v.end());

//    for (auto i : v) {
//        cout << i.t << ' ' << i.x << ' ' << i.y << ' ' << i.d << endl;
//    }

    ll min_plus = -lINF, min_minus = -lINF, max_plus = lINF, max_minus = lINF;
    int res_parity = 3;

    for (int i = 1; i <= n + 1; i++) {
        magic cur = v[i] - v[i - 1];

        int parity = ( (cur.x + cur.y + cur.t) % 2 + 2) % 2;

        if (cur.d == 0) {
            if (parity || abs(cur.x) + abs(cur.y) > cur.t) {
                res_parity = 0;
                break;
            }
        } else {
            if (cur.d < 0) {
                cur = magic() - cur;
                cur.t = -cur.t;
            }

            ll mn_plus = -cur.t - cur.x - cur.y;
            ll mx_plus = +cur.t - cur.x - cur.y;
            ll mn_minus = -cur.t - cur.x + cur.y;
            ll mx_minus = +cur.t - cur.x + cur.y;

            min_plus = max(min_plus, divll(mn_plus + cur.d - 1, cur.d));
            min_minus = max(min_minus, divll(mn_minus + cur.d - 1, cur.d));
            max_plus = min(max_plus, divll(mx_plus, cur.d));
            max_minus = min(max_minus, divll(mx_minus, cur.d));
            if ((cur.d % 2 + 2) % 2 != 0) {
                res_parity &= (1 << parity);
            } else if (parity != 0) {
                res_parity = 0;
                break;
            }
        }
    }

    bool flag = false;

    ll x, y;

    if (res_parity & 1) {
        ll sum = divll((min_plus + max_plus), 2ll);
        if ((sum % 2 + 2) % 2) {
            sum++;
        }
        ll diff = divll((min_minus + max_minus), 2ll);
        if ((diff % 2 + 2) % 2) {
            diff++;
        }

        if (sum >= min_plus && sum <= max_plus && diff >= min_minus && diff <= max_minus) {
            x = (sum + diff) / 2;
            y = (sum - diff) / 2;
            flag = true;
        }
    }
    if (res_parity & 2) {
        ll sum = divll((min_plus + max_plus), 2ll);
        if ((sum % 2 + 2) % 2 == 0) {
            sum++;
        }
        ll diff = divll((min_minus + max_minus), 2ll);
        if ((diff % 2 + 2) % 2 == 0) {
            diff++;
        }

        if (sum >= min_plus && sum <= max_plus && diff >= min_minus && diff <= max_minus) {
            x = (sum + diff) / 2;
            y = (sum - diff) / 2;
            flag = true;
        }
    }

    if (flag) {
        string ans;
        for (int i = 1; i <= n + 1; i++) {
            magic cur = v[i] - v[i - 1];
            cur.x += x * cur.d;
            cur.y += y * cur.d;

            if (cur.x > 0) {
                for (int i = 0; i < abs(cur.x); i++, cur.t--) {
                    ans.pb('R');
                }
            }
            if (cur.x < 0) {
                for (int i = 0; i < abs(cur.x); i++, cur.t--) {
                    ans.pb('L');
                }
            }
            if (cur.y > 0) {
                for (int i = 0; i < abs(cur.y); i++, cur.t--) {
                    ans.pb('U');
                }
            }
            if (cur.y < 0) {
                for (int i = 0; i < abs(cur.y); i++, cur.t--) {
                    ans.pb('D');
                }
            }
            for (; cur.t > 0; cur.t -= 2) {
                ans.pb('L');
                ans.pb('R');
            }
        }
        printf("%s\n", ans.c_str());
    } else {
        cout << "NO" << endl;
    }

    return 0;
}