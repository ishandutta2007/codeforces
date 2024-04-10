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
    int n, s;
    cin >> n >> s;
    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    if (!a[0]) {
        cout << "NO\n";
        return 0;
    }
    if (a[s - 1] == 1) {
        cout << "YES\n";
        return 0;
    }
    else {
        for (int i = s; i < n; ++i) {
            if (a[i] && b[i] && b[s - 1]) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}