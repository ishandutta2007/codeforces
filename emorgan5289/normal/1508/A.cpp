#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> a(3);
        vector<int> z(3), o(3);
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
            for (char c: a[i])
                if (c == '0') z[i]++;
                else o[i]++;
        }
        for (int i = 0; i < 3; i++) {
            int j = (i+1)%3;
            if (max(z[i], z[j]) <= n) {
                int x = 0;
                if (o[i] < o[j]) swap(a[i], a[j]);
                debug(a[i], a[j], '0');
                for (char c : a[i]) {
                    if (c == '0') cout << '0';
                    else {
                        // debug(x);
                        while (x < 2*n && a[j][x] == '0')
                            cout << '0', x++;
                        x++;
                        cout << '1';
                    }
                }
                while (x < 2*n && a[j][x] == '0')
                    cout << '0', x++;
                x++;
                break;
            } else if (max(o[i], o[j]) <= n) {
                int x = 0, y = 0;
                if (z[i] < z[j]) swap(a[i], a[j]);
                debug(a[i], a[j], '1');
                for (char c : a[i]) {
                    if (c == '1') cout << '1';
                    else {
                        while (x < 2*n && a[j][x] == '1')
                            cout << '1', x++;
                        x++;
                        cout << '0';
                    }
                }
                while (x < 2*n && a[j][x] == '1')
                    cout << '1', x++;
                x++;
                break;
            }
        }
        cout << "\n";
    }
}