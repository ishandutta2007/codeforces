#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, p[maxn];
bool ok[26];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    ok['a' - 'a'] = 1;
    ok['e' - 'a'] = 1;
    ok['i' - 'a'] = 1;
    ok['o' - 'a'] = 1;
    ok['u' - 'a'] = 1;
    ok['y' - 'a'] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    string s;
    getline(cin, s);
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        int cnt = 0;
        for (char ch : s) if (isalpha(ch)) cnt += ok[ch - 'a'];
        if (cnt ^ p[i]) cout << "NO\n", exit(0);
    }
    cout << "YES\n";
    return 0;
}