#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m;
char s[105][105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> s[i] + 1;
    int ok = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '*') continue;
            if (s[i][j] == '.') s[i][j] = '0';
            int cnt = 0;
            for (int ii = -1; ii <= 1; ++ii)
                for (int jj = -1; jj <= 1; ++jj)
                    if ((ii || jj) && s[i + ii][j + jj] == '*')
                        ++cnt;
            ok &= (cnt == s[i][j] - '0');
        }
    }
    cout << (ok ? "YES" : "NO");
}