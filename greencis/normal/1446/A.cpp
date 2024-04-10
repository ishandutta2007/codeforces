#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

int a[200200];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        ll w;
        cin >> n >> w;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= (w + 1) / 2 && a[i] <= w) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            cout << "1\n" << idx + 1 << "\n";
            continue;
        }
        vector<int> v;
        ll cur = 0;
        for (int i = 0; i < n; ++i) {
            if (cur + a[i] > w) continue;
            v.push_back(i);
            cur += a[i];
            if (cur >= (w + 1) / 2)
                break;
        }
        if (cur >= (w + 1) / 2 && cur <= w) {
            cout << v.size() << "\n";
            for (int x : v) cout << x + 1 << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
}