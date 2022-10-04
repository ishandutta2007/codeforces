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
    int cur = 0;
    vector <int> mem(n);
    set <pair <int, int>> cnt;
    for (int i = 0; i < n; ++i) cnt.insert({0, i});
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x;
        cnt.erase({mem[x], x});
        ++mem[x];
        cnt.insert({mem[x], x});
        if (cnt.begin()->first > cur) {
            cout << '1';
            ++cur;
        }
        else {
            cout << '0';
        }
    }
}