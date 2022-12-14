#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        cin >> n;

        vi a{6, 10, 14};
        if (n < 31) cout << "NO\n";
        else {
            cout << "YES\n";

            int x = n - 30;
            for (int i : a) if (x == i) {
                a[2] = 15;
                x--;
            }
            cout << x;
            for (int i : a) cout << ' ' << i;
            cout << '\n';
        }
    }

    return 0;
}