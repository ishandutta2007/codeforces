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
    set <int> a;
    for (int i = 1; i <= 100; ++i) a.insert(i);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        set <int> b;
        for (int j = 0; j < x; ++j) {
            int y;
            cin >> y;
            if (a.count(y)) b.insert(y);
        }
        a = b;
    }
    for (auto x : a) {
        cout << x << ' ';
    }
}