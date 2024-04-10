#include <bits/stdc++.h>
using namespace std;
string s;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int n = s.size();
    string t;
    if (n >= 2) {
        t += s[n - 2];
    }   
    t += s[n - 1];
    int x = stoi(t);
    if (x % 4 == 0) {
        cout << 4 << '\n';
    }   
    else {
        cout << 0 << '\n';
    }
}