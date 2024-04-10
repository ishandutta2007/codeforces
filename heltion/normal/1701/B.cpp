#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        cout << "2\n";
        vector<int> v(n + 1), p;
        for (int i = 1; i <= n; i += 1)
            if (not v[i])
                for (int k = i; k <= n; k *= 2) {
                    cout << k << " ";
                    v[k] = 1;
                }
        cout << "\n";
    }
}