#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

long double x, y;

long double add_sign(bool is_neg, long double res) {
    if (is_neg) {
        return -res;
    }
    return res;
}

long double intersect(long double x1, long double y1, long double x2, long double y2) {
    if (x2 == x1) return 0;
    bool is_neg = false;
    if (x1 > x2) {
        is_neg = true;
        swap(x1, x2);
        swap(y1, y2);
    }
    /// shrink [x1, x2] to [x, x + 1];
    if (x1 >= x + 1 || x2 <= x) {
        return 0;
    }
    if (x > x1) {
        y1 = y1 + (y2 - y1) / (x2 - x1) * (x - x1);
        x1 = x;
    }
    if (x + 1 < x2) {
        y2 = y1 + (y2 - y1) / (x2 - x1) * (x + 1 - x1);
        x2 = x + 1;
    }
    /// done
    if (x1 >= x2) {
        return 0;
    }
    if (y1 > y2) {
        swap(y1, y2);
    }
    long double l = y, r = min((long double)y + 1, y2);
    if (r <= l) {
        return 0;
    }
    if (r <= y1) {
        return add_sign(is_neg, (r - l) * (x2 - x1));
    }
    long double ans = 0;
    if (l <= y1) {
        ans += (y1 - l) * (x2 - x1);
        l = y1;
    }
    if (y1 < y2) {
        ans += (x2 - x1) * (r - l) / (y2 - y1) * (r - l) / 2;
        ans += (r - l) * (x2 - x1) * (y2 - r) / (y2 - y1);
    }
    return add_sign(is_neg, ans);
}

long double get_square(vector<pair<long double, long double>> a) {
    int sz = a.size();
    vector<array<long double, 2>> poly(sz);
    for (int i = 0; i < sz; ++i) {
        poly[i][0] = a[i].first;
        poly[i][1] = a[i].second;
    }
    long double area = 0;
    for (int i = 0; i < sz; ++i) {
        int j = (i + 1) % sz;
        area += intersect(poly[i][0], poly[i][1], poly[j][0], poly[j][1]);
    }
    area = abs(area);
    return area;
}

const long double eps = 1e-12;

signed main() {
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif

    #ifdef LOCAL
        cin >> x >> y;
    #endif

    int n, m;
    cin >> n >> m;
    cout << setprecision(15) << fixed;
    double X = -2, Y = -2;
    { // find x coordinate 2*2
        vector<pair<long double, long double>> pt;
        for (int i = 0; i < 100; ++i) {
            pt.emplace_back(i, 100);
            pt.emplace_back(i, 0);
            pt.emplace_back(i + 1.0 * (i + 1) / 100, 0);
            pt.emplace_back(i + 1.0 * (i + 1) / 100, 100);
        }
        pt.emplace_back(0, 101);
        pt.emplace_back(100, 101);

        // print ans
        long double res;
        #ifdef LOCAL
            res = get_square(pt);
        #else
            cout << "? " << pt.size() << endl;
            for (auto i : pt) {
                cout << i.first << ' ' << i.second << endl;
            }
            cin >> res;
        #endif

        for (int i = 1; i <= 100; ++i) {
            if (abs(res * 100 - i) < eps) {
                X = i - 2 + 1.0 * i / 100;
                break;
            } else if (res * 100 < i) {
                X = i - 2;
                break;
            }
        }
        // cerr << "! " << res << ':' << X << '\n';
        assert(X != -2);
    }
    { // find y coordinate 2*2
        vector<pair<long double, long double>> pt;
        for (int i = 0; i < 100; ++i) {
            pt.emplace_back(100, i);
            pt.emplace_back(0, i);
            pt.emplace_back(0, i + 1.0 * (i + 1) / 100);
            pt.emplace_back(100, i + 1.0 * (i + 1) / 100);
        }
        pt.emplace_back(101, 0);
        pt.emplace_back(101, 100);

        // print ans
        long double res;
        #ifdef LOCAL
            res = get_square(pt);
        #else
            cout << "? " << pt.size() << endl;
            for (auto i : pt) {
                cout << i.first << ' ' << i.second << endl;
            }
            cin >> res;
        #endif

        for (int i = 1; i <= 100; ++i) {
            if (abs(res * 100 - i) < eps) {
                Y = i - 2 + 1.0 * i / 100;
                break;
            } else if (res * 100 < i) {
                Y = i - 2;
                break;
            }
        }
        cerr << "! " << res << ':' << Y << '\n';
        assert(Y != -2);
    }
    cerr << "! " << X << ' ' << Y << '\n';
    pair<long double, long double> ans = {-1, -1};
    { // X coord ans
        vector<pair<long double, long double>> pt = {{X, Y}, {X + 1, Y}, {X + 1, Y + 2}, {X, Y + 2}};
        #ifdef LOCAL
            ans.first = get_square(pt);
        #else
            cout << "? " << 4 << endl;
            cout << X << ' ' << Y << endl;
            cout << X + 1 << ' ' << Y << endl;
            cout << X + 1 << ' ' << Y + 2 << endl;
            cout << X << ' ' << Y + 2 << endl;
            cin >> ans.first;
        #endif
        ans.first = X + 1 - ans.first;
    }
    { // X coord ans
        vector<pair<long double, long double>> pt = {{X, Y}, {X, Y + 1}, {X + 2, Y + 1}, {X + 2, Y}};
        #ifdef LOCAL
            ans.second = get_square(pt);
        #else
            cout << "? " << 4 << endl;
            cout << X << ' ' << Y << endl;
            cout << X << ' ' << Y + 1 << endl;
            cout << X + 2 << ' ' << Y + 1 << endl;
            cout << X + 2 << ' ' << Y << endl;
            cin >> ans.second;
        #endif
        ans.second = Y + 1 - ans.second;
    }
    ans.first = min(ans.first, (long double) n - 1);
    ans.second = min(ans.second, (long double) m - 1);
    assert(ans.first + 1 <= n && ans.second + 1 <= m);
    cout << "! " << ans.first << ' ' << ans.second << endl;
}