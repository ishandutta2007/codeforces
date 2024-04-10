#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (auto& si : s) cin >> si;
        if (s[0][0] == '1') {
            cout << "-1\n";
            continue;
        }
        int p = 0;
        for (auto& si : s)
            for (auto& sij : si)
                p += sij - '0';
        cout << p << "\n";
        for (int j = m - 1; j >= 1; j -= 1)
            for (int i = 0; i < n; i += 1)
                if (s[i][j] == '1')
                    cout << i + 1 << " " << j << " " << i + 1 << " " << j + 1 << "\n";
        for (int i = n - 1; i >= 1; i -= 1)
            if (s[i][0] == '1')
                cout << i << " " << 1 << " " << i + 1 << " " << 1 << "\n";
    }
    return 0;
}