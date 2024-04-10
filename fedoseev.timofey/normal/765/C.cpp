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
    int k, a, b;
    cin >> k >> a >> b;
    if (k > a && k > b) {
        cout << "-1\n";
        exit(0);
    }
    int c1 = a / k;
    int c2 = b / k;
    int d1 = a % k;
    int d2 = b % k;
    if ((ll)(k - 1) * c1 < d2 || (ll)(k - 1) * c2 < d1) {
        cout << "-1\n";
        exit(0);
    }
    cout << c1 + c2 << '\n';
}