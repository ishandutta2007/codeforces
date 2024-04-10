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
        int n, a, b;
        cin >> n >> a >> b;
        if (a + b > n - 2 || abs(a - b) > 1) {
            cout << "-1\n";
            continue;
        }
        vector<int> v;
        if (a + 1 == b) {
            for (int i = 0; i < b; ++i) {
                v.push_back(n + 1 - (n - 1 - 2 * i));
                v.push_back(n + 1 - (n - 0 - 2 * i));
            }
            for (int i = n - 2 * b; i >= 1; --i)
                v.push_back(n + 1 - i);
        } else if (a == b) {
            for (int i = 0; i < a; ++i) {
                v.push_back(n - 1 - 2 * i);
                v.push_back(n - 0 - 2 * i);
            }
            for (int i = 1; i <= n - 2 * a; ++i)
                v.push_back(i);
        } else {
            for (int i = 0; i < a; ++i) {
                v.push_back(n - 1 - 2 * i);
                v.push_back(n - 0 - 2 * i);
            }
            for (int i = n - 2 * a; i >= 1; --i)
                v.push_back(i);
        }
        for (int x : v)
            cout << x << ' ';
        cout << endl;
    }
}