#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        vector<int> v;
        int n;
        cin >> n;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            if (a & 1) v.push_back(i);
        }
        if (abs((int)v.size() - (n - (int)v.size())) > 1) {
            cout << "-1\n";
            continue;
        }
        int ans = 0;
        if (n & 1) {
            if ((int)v.size() == n / 2) for (int i = 1, j = 0; i < n; i += 2, j += 1) ans += abs(v[j] - i); 
            else for (int i = 0, j = 0; i < n; i += 2, j += 1) ans += abs(v[j] - i); 
        }
        else {
            int A = 0, B = 0;
            for (int i = 0, j = 0; i < n; i += 2, j += 1) A += abs(v[j] - i); 
            for (int i = 1, j = 0; i < n; i += 2, j += 1) B += abs(v[j] - i);
            ans = min(A, B);
        }
        cout << ans << "\n";
    }
    return 0;
}