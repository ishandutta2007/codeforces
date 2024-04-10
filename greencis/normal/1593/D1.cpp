#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int& x : v) cin >> x;
        int mn = *min_element(v.begin(), v.end());
        int g = 0;
        for (int i = 0; i < n; ++i)
            g = gcd(g, v[i] - mn);
        if (g == 0) g = -1;
        cout << g << '\n';
    }
}