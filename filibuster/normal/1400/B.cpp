#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int p, f;
    cin >> p >> f;

    int c1, c2, a1, a2;
    cin >> c1 >> c2 >> a1 >> a2;

    if(a1 > a2) {
        swap(a1, a2);
        swap(c1, c2);
    }

    int ans = 0;
    for(int i = 0; i <= c1; i++) {
//        cout << i << ' ' << i * a1 << ' ' << p << endl;
        if(i * 1ll * a1 > p)
            break;

        int k = min(c1 - i, f / a1);
//        cout << k << endl;
        int res = i + k;
        int b = (p - i * a1) / a2;
        int d = (f - k * a1) / a2;
//        cout << b << ' ' << d << endl;
        res += min(c2, b + d);
        ans = max(ans, res);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}