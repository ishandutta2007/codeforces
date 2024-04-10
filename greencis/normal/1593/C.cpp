#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(k);
        for (int& x : v) cin >> x;
        sort(all(v), greater<>());
        int sum = 0;
        int i = 0;
        for (; i < k && v[i]; ++i) {
            sum += n - v[i];
            if (sum >= n) break;
        }
        cout << i << '\n';
    }
}