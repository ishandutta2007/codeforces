#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 100228;


int n[3];
int a[3][MAXN];


struct Line {
    long long k, b;
    Line(long long _k, long long _b) {
        k = _k;
        b = _b;
    }
    Line(){}
    ll value(long long x) {
        return k * x + b;
    }
};


struct ConvexHull {
    vector<Line> st;
    ConvexHull(){}
    bool better(Line a, Line b, Line c) {
        if (c.k == b.k) {
            return c.b > b.b;
        }
        return (__int128)(c.b - a.b) * (a.k - b.k) <= (__int128)(b.b - a.b) * (a.k - c.k);
    }
    void addLine(Line l) {
        while (!st.empty() && st.back().k == l.k) {
            if (st.back().b > l.b) {
                return;
            }
            st.pop_back();
        }
        while (sz(st) >= 2 && better(st[sz(st) - 2], st[sz(st) - 1], l)) {
            st.pop_back();
        }
        st.push_back(l);
    }
    ll getMax(long long x) {
        if (st.empty()) {
            return -8e18;
        }
        if (sz(st) == 1) {
            return st[0].value(x);
        }
        int l = 0;
        int r = sz(st) - 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if ((st[mid + 1].b - st[mid].b) >= (__int128)x * (st[mid].k - st[mid + 1].k)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ll res = -8e18;
        for (int i = l; i <= r; i++) {
            chkmax(res, st[i].value(x));
        }
        return res;
    }
};

void solve() {
    for (int t = 0; t < 3; t++) {
        cin >> n[t];
    }
    for (int t = 0; t < 3; t++) {
        for (int i = 0; i < n[t]; i++) {
            cin >> a[t][i];
        }
        sort(a[t], a[t] + n[t]);
    }
    unsigned long long ans = 16e18;
    for (int t = 0; t < 3; t++) {
        int t1[2];
        t1[0] = (t + 1) % 3;
        t1[1] = (t + 2) % 3; 
        int uk[2] = {0, 0};
        int uk1[2] = {0, 0};
        ConvexHull kek[2];
        for (int i = 0; i < n[t]; i++) {
          //  cout << a[t][i] << ' ';
            for (int j = 0; j < 2; j++) {
                while (uk[j] < n[t1[j]] && a[t1[j]][uk[j]] <= a[t][i]) {
                    ll val = a[t1[j]][uk[j]];
                    while (uk1[j] < n[t1[j ^ 1]] && a[t1[j ^ 1]][uk1[j]] <= val) {
                        ll val1 = a[t1[j ^ 1]][uk1[j]];
                        ll sum = (val - val1) * (val - val1);
                        ll keks = val * val + val1 * val1 + sum;
                       // cout << j << ' ' << 2LL * (val + val1) << ' ' << val << ' ' << val1 << endl;
                        kek[j].addLine(Line(2LL * (val + val1), -keks));
                        uk1[j]++;
                    }
                    if (uk1[j] > 0 && a[t1[j ^ 1]][uk1[j] - 1] <= val) {
                        ll val1 = a[t1[j ^ 1]][uk1[j] - 1];
                        ll sum = (val - val1) * (val - val1);
                        ll keks = val * val + val1 * val1 + sum;
                       // cout << j << ' ' << 2LL * (val + val1) << ' ' << val << ' ' << val1 << endl;
                        kek[j].addLine(Line(2LL * (val + val1), -keks));
                    }
                    uk[j]++;
                }
            }
            for (int j = 0; j < 2; j++) {
                unsigned long long add = (ll)a[t][i] * a[t][i];
                add *= 2;
                unsigned long long f = -kek[j].getMax(a[t][i]);
                f += add;
                chkmin(ans, f);
            }
        }
       // cout << endl;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}