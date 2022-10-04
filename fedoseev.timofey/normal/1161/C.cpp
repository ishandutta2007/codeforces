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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
    }
    for (int i = 1; i <= 51; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] > i) ++cnt;
        }
        if (cnt != n) {
            if (cnt >= n / 2) {
                cout << "Alice\n";
                return 0;
            }
            else {
                cout << "Bob\n";
                return 0;
            }
        }
    }
}