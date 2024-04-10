#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int T, n, K;
string s, f[maxn];

void chk(string &a, string b) {
    if (a > b) a = b;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> n >> K >> s;
        fill(f + 1, f + n + 1, 'z' + 1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            char _c = min({c, (c + 1) % K, (c + K - 1) % K}) + 'a';
            chk(f[i + 1], f[i] + _c);
            if (i) {
                chk(f[i + 1], f[i - 1] + _c + s[i - 1]);
                auto t = f[i];
                t.insert(t.begin() + i - 1, s[i]);
                chk(f[i + 1], t);
            }
            if (i > 1) {
                auto t = f[i - 1];
                t.insert(t.begin() + i - 2, s[i]);
                chk(f[i + 1], t + s[i - 1]);
            }
        }
        cout << f[n] << endl;
    }
    return 0;
}