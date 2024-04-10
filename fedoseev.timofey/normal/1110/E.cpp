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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
        cout << "No\n";
        exit(0);
    }
    vector <int> c;
    vector <int> d;
    for (int i = 1; i < n; ++i) {
        c.push_back(a[i] - a[i - 1]);
        d.push_back(b[i] - b[i - 1]);
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    if (c == d) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}