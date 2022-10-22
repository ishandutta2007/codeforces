#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9 + 7;

int get(int l1, int r1, int l2, int r2) {
    int l = max(l1, l2);
    int r = min(r1, r2);
    int len = r - l + 1;
    return max(0ll, len);
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l1, r1, t1, l2, r2, t2;
    cin >> l1 >> r1 >> t1 >> l2 >> r2 >> t2;

    int d = __gcd(t1, t2);

    int l = -INF;
    int r = INF;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (l2 + m * d < l1) {
            l = m;
        }   
        else {
            r = m;
        }   
    }   

    cout << max(get(l1, r1, l2 + l * d, r2 + l * d), get(l1, r1, l2 + r * d, r2 + r * d)) << '\n';
    return 0;
}