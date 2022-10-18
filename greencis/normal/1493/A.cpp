#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for (int i = (k + 1) / 2; i < k; ++i) v.push_back(i);
        for (int i = k + 1; i <= n; ++i) v.push_back(i);
        cout << v.size() << endl;
        for (int x : v) cout << x << ' ';
        cout << endl;
    }
}