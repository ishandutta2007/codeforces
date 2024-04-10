#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        vector<string> s(8);
        for (auto& si : s) cin >> si;
        for (int i = 1; i + 1 < 8; i += 1)
            for (int j = 1; j + 1 < 8; j += 1)
                if (s[i][j] == '#'
                    and s[i - 1][j - 1] == '#'
                    and s[i - 1][j + 1] == '#'
                    and s[i + 1][j - 1] == '#'
                    and s[i + 1][j + 1] == '#')
                    cout << i + 1 << " " << j + 1 << "\n";
    }
}