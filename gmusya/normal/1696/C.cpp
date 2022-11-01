#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        int k;
        cin >> k;
        vector<int> b(k);
        for (int& x : b) {
            cin >> x;
        }
        vector<pair<int, ll>> c;
        for (int i = 0; i < n; ++i) {
            ll cnt = 1;
            while (a[i] % m == 0) {
                a[i] /= m;
                cnt *= m;
            }
            if (!c.empty() && c.back().first == a[i]) {
                c.back().second += cnt;
            } else {
                c.emplace_back(a[i], cnt);
            }
        }
        int iterC = 0;
        int iterB = 0;
        int t = c.size();
        while (iterB < k && iterC < t) {
            int cnt = 1;
            while (b[iterB] % m == 0) {
                b[iterB] /= m;
                cnt *= m;
            }
            if (b[iterB] != c[iterC].first || cnt > c[iterC].second) {
                break;
            }
            ++iterB;
            c[iterC].second -= cnt;
            if (!c[iterC].second) {
                ++iterC;
            }
        }
        if (iterB == k && iterC == t) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}