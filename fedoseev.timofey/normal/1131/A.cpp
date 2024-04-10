#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    int c = 2 * w1 + 2 * h1 + 4;
    c -= w2;
    c += w2 + h2 + h2;
    cout << c << endl;
}