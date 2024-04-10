#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        set<char> sc;
        for (int i = 0; i < 2; i += 1) {
            string s;
            cin >> s;
            for (char c : s)
                sc.insert(c);
        }
        cout << sc.size() - 1 << "\n";
    }
}