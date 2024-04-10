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
    int b, k;
    cin >> b >> k;
    vector <int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 0; i < k; ++i) {
        res *= b;
        res += a[i];
        res %= 2;
    }
    if (res == 0) {
        cout << "even\n";
    }
    else {
        cout << "odd\n";
    }
}