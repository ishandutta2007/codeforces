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

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

struct point {
    ll r, s;
    bool can;
    point (ll s = 0, ll r = 0) : s(s), r(r) {}
};

int n;

vector<point> p, p2;

bool comp(point a, point b) {
    return a.s * b.r < a.r * b.s;
}

void print(point p) {
    cout << 1000.0 / p.s << ' ' << 1000.0 / p.r << endl;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    p.resize(n);
    p2.resize(n);
    ll mx_s = 0, mx_r = 0;
    for (int i = 0; i < n; i++) {
        scanf(LLD" "LLD, &p[i].s, &p[i].r);
        p2[i].s = p[i].s;
        p2[i].r = p[i].r;
        if (p[i].s > mx_s) {
            mx_s = p[i].s;
        }
        if (p[i].r > mx_r) {
            mx_r = p[i].r;
        }
    }
    p.pb(point(mx_s, 1));
    p.pb(point(1, mx_r));
    sort(all(p), comp);
//    for (int i = 0; i < p.size(); i++) {
//        print(p[i]);
//    }
    vector<point> conv;
    for (int i = 0; i < p.size(); i++) {
        point p3 = p[i];
        while (conv.size() >= 2) {
            point p1 = conv[conv.size() - 2], p2 = conv.back();
            if (p1.r * p3.s * (p2.r - p3.r) * (p1.s - p2.s) >=
                    p3.r * p1.s * (p2.s - p3.s) * (p1.r - p2.r)) {
                conv.pop_back();
                continue;
            } else {
                break;
            }
        }
        conv.pb(p[i]);
    }
//    for (int i = 0; i < conv.size(); i++) {
//        print(conv[i]);
//    }
//    cout << endl;
    vector<point> conv2;
    for (int j = 0; j < (int) conv.size(); j++) {
        if (j == 0 || conv[j - 1].s < mx_s) {
            if (j == conv.size() - 1 || conv[j + 1].r < mx_r) {
                conv2.pb(conv[j]);
            }
        }
    }
//        cout << "ge" << endl;
    sort(all(conv2), comp);
    if (conv2.size() == 0) {
        conv2.pb(p2[0]);
    }
    for (int i = 0; i < n; i++) {
//        cout << "ge" << endl;
        int j = (int) (lower_bound(all(conv2), p2[i], comp) - conv2.begin());
//        cout << "ge" << endl;
        bool flag = false;
//        cout << "ge" << endl;
        if (j == 0 && conv2[j].r == p2[i].r && conv2[j].s == p2[i].s) {
            flag = true;
        } else if (j > 0) {
//        cout << "ge" << conv2.size() << endl;
//        cout << "ge" << j << endl;
            point p3 = p2[i];
//        cout << "ge" << j << endl;
            point pp2 = conv2[j - 1];
//        cout << "ge" << j << endl;
            point p1 = conv2[j];
//        cout << "ge" << endl;
            if (p1.r * p3.s * (pp2.r - p3.r) * (p1.s - pp2.s) ==
                    p3.r * p1.s * (pp2.s - p3.s) * (p1.r - pp2.r)) {
                flag = true;
            }
//        cout << "ge" << endl;
        }
        if (flag) {
            printf("%d ", i + 1);
        }
    }
    return 0;
}