#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        ranges::reverse(s);
        string t;
        for (int i = 0; i < n; i += 1) 
            if (s[i] == '0') t += (s[i + 1] - '0') + (s[i + 2] - '0') * 10 - 1 + 'a', i += 2;
            else t += s[i] - '0' - 1 + 'a';
        ranges::reverse(t);
        cout << t << "\n";
    }
}