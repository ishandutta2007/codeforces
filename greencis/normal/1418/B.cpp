#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<int> v(n), block(n);
        for (int& i : v) cin >> i;
        for (int& i : block) cin >> i;
        vector<int> allowed;
        for (int i = 0; i < n; ++i) {
            if (!block[i])
                allowed.push_back(v[i]);
        }
        sort(all(allowed));
        for (int i = 0; i < n; ++i) {
            if (!block[i]) {
                v[i] = allowed.back();
                allowed.pop_back();
            }
        }
        for (int i = 0; i < n; ++i)
            cout << v[i] << ' ';
        cout << '\n';
    }
}