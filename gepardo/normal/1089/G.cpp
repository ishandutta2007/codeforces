#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
int tst;
void solve() {
    vector < int > a(7);
    ll k;
    cin >> k;
    int all = 0;
    for (int& v : a) {
        cin >> v;
        all += v;
    }
    ll mn = (ll)1e18;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            int days = 0;
            int val = 0;
            if (j >= i) {
                days = j - i + 1;
                for (int t = i; t <= j; t++) {
                    val += a[t];
                }
                ll need = (max(0LL, k - val) + all - 1) / all;
                mn = min(mn, days + 7 * need);
            }
            else {
                for (int t = i; t < 7; t++) {
                    val += a[t];
                    days++;
                }
                for (int t = 0; t <= j; t++) {
                    val += a[t];
                    days++;
                }
                ll need = (max(0LL, k - val) + all - 1) / all;
                mn = min(mn, days + 7 * need);
            }
        }
    }
    cout << mn << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}