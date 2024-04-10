//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, k;
        cin >> n >> k;
        if (2 * k - 1 > n) {
            cout << "-1\n";
        } else {
            vector<string> v(n, string(n, '.'));
            for (int i = 0; i < k; ++i)
                v[2 * i][2 * i] = 'R';
            for (int i = 0; i < n; ++i) {
                cout << v[i] << '\n';
            }
        }
    }
}