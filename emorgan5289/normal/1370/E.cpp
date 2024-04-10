#include <bits/stdc++.h>
using namespace std;
int n, c[2], f[2];
int main() {
    cin >> n;
    string s, t; cin >> s >> t;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i]) {
            int x = s[i]-'0'; f[x]++, c[x]++;
            if (f[x^1]) f[x^1]--;
        }
    cout << (c[0]!=c[1]?-1:f[0]+f[1]) << "\n";
}