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
    int n, m;
    cin >> n >> m;
    if (m % n) {
        cout << "-1\n";
        return 0;
    }
    m /= n;
    int ans = 0;
    while (m > 1) {
        if (m % 2 == 0) {
            m /= 2;
            ++ans;
        }
        else if (m % 3 == 0) {
            m /= 3;
            ++ans;
        }
        else {
            break;
        }
    }
    if (m > 1) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << '\n';
}