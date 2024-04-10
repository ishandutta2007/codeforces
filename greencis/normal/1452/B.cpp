#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

int a[100100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a + n);

        ll lvl = max<ll>(a[n - 1], (sum + n - 2) / (n - 1));
        cout << lvl * (n - 1) - sum << endl;
    }
}