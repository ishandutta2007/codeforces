#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        cout << (s[0] - 'a') * 25 + (s[1] - 'a' - (s[1] > s[0])) + 1 << "\n";
    }
}