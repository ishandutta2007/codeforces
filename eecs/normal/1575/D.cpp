#include <bits/stdc++.h>
using namespace std;

string s;
int n, ans, pw[10];

int main() {
    ios::sync_with_stdio(0);
    cin >> s, n = s.size();
    for (int i = pw[0] = 1; i <= n; i++) {
        pw[i] = 10 * pw[i - 1];
    }
    if (n == 1 && (s[0] == '0' || s[0] == '_' || s[0] == 'X')) ans++;
    for (int i = pw[n - 1]; i < pw[n]; i++) {
        bool flag = !(i % 25);
        int z = -1;
        for (int j = n - 1, x = i; ~j && flag; j--) {
            int v = x % 10;
            if (isdigit(s[j])) {
                flag &= v == s[j] - '0';
            } else if (s[j] == 'X') {
                if (!~z) z = v;
                else flag &= z == v;
            }
            x /= 10;
        }
        if (flag) ans++;
    }
    cout << ans << '\n';
    return 0;
}