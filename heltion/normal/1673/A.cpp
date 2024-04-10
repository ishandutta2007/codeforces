#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        int sum = 0;
        for (char c : s)
            sum += c - 'a' + 1;
        if (s.size() % 2 == 0)
            cout << "Alice " << sum << '\n';
        else if (s.size() > 1)
            cout << "Alice " << sum - 2 * (min(s[0], s.back()) - 'a' + 1) << "\n";
        else cout << "Bob " << sum << "\n";
    }
}