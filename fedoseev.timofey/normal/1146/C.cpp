#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int get(int x, vector <int> a) {
    cout << "1 " << a.size() << ' ' << x + 1 << ' ';
    for (auto y : a) {
        cout << y + 1 << ' ';
    }
    cout << endl;
    int t;
    cin >> t;
    return t;
}

void solve() {
    int n;
    cin >> n;
    vector <int> a;
    for (int i = 1; i < n; ++i) {
        a.push_back(i);
    }
    int kek = get(0, a);
    while (a.size() > 1) {
        int m = a.size() / 2;
        vector <int> b = vector <int> (a.begin(), a.begin() + m);
        vector <int> c = vector <int> (a.begin() + m, a.end());
        if (get(0, b) == kek) a = b;
        else a = c;
    }
    int x = a[0];
    a.clear();
    for (int i = 0; i < n; ++i) {
        if (i != x) a.push_back(i);
    }
    int res = get(x, a);
    cout << "-1 " << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}