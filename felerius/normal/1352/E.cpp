#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& i : a) cin >> i;
        map<int, int> s;
        for (auto& i : a)
            s[i]++;
        for (int i = 0; i < n; ++i) {
            int sum = a[i];
            for (int j = i + 1; j < n; ++j) {
                sum += a[j];
                auto it = s.find(sum);
                if (it != end(s))
                    s.erase(it);
            }
        }
        int c = n;
        for (auto [k, v] : s)
            c -= v;
        cout << c << '\n';
    }
    
    return 0;
}