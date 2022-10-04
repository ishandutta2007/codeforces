#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    ll cr = n;
    int cnt = 0;
    ll who = -1;
    for (ll dv = 2; dv * dv <= cr; ++dv) {
        if (cr % dv == 0) {
            who = dv;
            ++cnt;
            while (cr % dv == 0) cr /= dv;
        }
    }
    if (cr > 1) {
        ++cnt;
        who = cr;
    }
    if (cnt > 1) {
        cout << 1 << '\n';
    } else {
        cout << who << '\n';
    }
}