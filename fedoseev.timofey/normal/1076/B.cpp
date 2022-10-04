#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

int get(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return i;
        }
    }
    return x;
}

// a + b = d
// a*b = d
//a = d / b
// d / b + b = d

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int ans = 0;
    while (n) {
        int x = get(n);
        if (x == 2) {
            ans += n / x;
            n = 0;
        }
        else {
            ++ans;
            n -= x;
        }
    }
    cout << ans << '\n';
}