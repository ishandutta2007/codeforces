#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rnd(123);

bool ask(int x, int y) { // y > x
    cout << "? " << x << ' ' << y << endl;
    char c;
    cin >> c;
    if (c == 'y') return true;
    return false;
   // return (y % a) > (x % a);
}

int solve() {
    int sz = 0;
    for (int x = 1; x < 30; ++x) {
        int ps = (1 << (x - 1)) - 1;
        int pf = (1 << x) - 1;
        if (!ask(ps, pf)) {
            break;
        }
        sz = x;
    }
    if (sz == 0) return 1;
    int ps = (1 << sz);
    int pf = (1 << (sz + 1)) - 1;
    int l = ps;
    int r = pf + 1;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (ask(ps, m)) l = m;
        else r = m;
    }
    if (r == pf + 1) return (1 << sz);
    return r;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    while (true) {
        string s;
        cin >> s;
        if (s == "start") {
            int x = solve();
            cout << "! " << x << endl;
        }
        else {
            exit(0);
        }
    }
}