#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int T, n, a[maxn];

int main() {
    cin >> T;
    // T = 1000;
    auto ask = [&](int i, int j, int k) {
        cout << "? " << i << " " << j << " " << k << endl;
        return cin >> i, i;
        // return max({a[i], a[j], a[k]}) - min({a[i], a[j], a[k]});
    };
    // mt19937 rnd(time(0));
    while (T--) {
        cin >> n;
        // n = 5;
        // for (int i = 1; i <= n; i++) {
            // a[i] = rnd() % 1000000000 + 1;
        // }
        // a[rnd() % n + 1] = 0;
        int mx = -1, mn = INT_MAX, res1;
        for (int i = 3; i <= n; i++) {
            int t = ask(1, 2, i);
            mn = min(mn, t);
            if (t > mx) mx = t, res1 = i;
        }
        int o = mx;
        int ano = res1 == 3 ? 4 : 3, res2;
        mx = -1;
        int mn2 = INT_MAX;
        for (int i = 1; i <= n; i++) if (i ^ res1 && i ^ ano) {
            int t = ask(res1, ano, i);
            mn2 = min(mn2, t);
            if (t > mx) mx = t, res2 = i;
        }
        if (o == mn && mx <= o) {
            res1 = 1, res2 = 2;
        }
        if (mn2 == mx && o <= mn2) {
            res2 = ano;
        }
        cout << "! " << res1 << " " << res2 << endl;
    }
    return 0;
}