#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

struct rect {
    int a, b, c, d;
    rect(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
    rect() : a(0), b(0), c(0), d(0) {}
    rect operator+(const rect &other) const {
        rect res;
        res.a = max(a, other.a);
        res.c = min(c, other.c);
        res.b = max(b, other.b);
        res.d = min(d, other.d);
        return res;
    }
    bool ok() {
        return a <= c && b <= d;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <rect> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i].a >> r[i].b >> r[i].c >> r[i].d;
    }
    vector <rect> pref(n), suf(n);
    pref[0] = r[0];
    suf[n - 1] = r[n - 1];
    for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] + r[i];
    for (int i = n - 2; i >= 0; --i) suf[i] = suf[i + 1] + r[i];
    for (int i = 0; i < n; ++i) {
        if (!i) {
            if (suf[i + 1].ok()) {
                cout << suf[1].a << ' ' << suf[1].b << '\n';
                return 0;
            }
        }
        else if (i == n - 1) {
            if (pref[i - 1].ok()) {
                cout << pref[i - 1].a << ' ' << pref[i - 1].b << '\n';
                return 0;
            }
        }
        else {
            rect cur = pref[i - 1] + suf[i + 1];
            if (cur.ok()) {
                cout << cur.a << ' ' << cur.b << '\n';
                return 0;
            }
        }
    }
}