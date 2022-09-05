#include <bits/stdc++.h>
#define y1 _y1
using namespace std;

int n;

int main() {
    cin >> n;
    auto query = [&](int x1, int x2, int y1, int y2) {
        cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        int x; cin >> x; return x;
    };
    auto solve = [&](int x11, int x12, int y11, int y12) {
        int l = x11, r = x12, x1 = -1, y1 = -1, x2 = -1, y2 = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int t = query(mid, x12, y11, y12);
            t ? l = (x1 = mid) + 1 : r = mid - 1;
        }
        l = x11, r = x12;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int t = query(x11, mid, y11, y12);
            t ? r = (x2 = mid) - 1 : l = mid + 1;
        }
        l = y11, r = y12;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int t = query(x11, x12, mid, y12);
            t ? l = (y1 = mid) + 1 : r = mid - 1;
        }
        l = y11, r = y12;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int t = query(x11, x12, y11, mid);
            t ? r = (y2 = mid) - 1 : l = mid + 1;
        }
        return make_tuple(x1, y1, x2, y2);
    };
    auto print = [&](tuple<int, int, int, int> p, tuple<int, int, int, int> q) {
        cout << "! " << get<0>(p) << " " << get<1>(p) << " " << get<2>(p) << " "
            << get<3>(p) << " " << get<0>(q) << " " << get<1>(q) << " " << get<2>(q)
            << " " << get<3>(q) << endl;
    };
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1, t = query(1, mid, 1, n);
        if (t == 1 && query(mid + 1, n, 1, n) == 1) {
            print(solve(1, mid, 1, n), solve(mid + 1, n, 1, n)), exit(0);
        }
        if (!t) l = mid + 1;
        else r = mid - 1;
    }
    l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1, t = query(1, n, 1, mid);
        if (t == 1 && query(1, n, mid + 1, n) == 1) {
            print(solve(1, n, 1, mid), solve(1, n, mid + 1, n)), exit(0);
        }
        if (!t) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}