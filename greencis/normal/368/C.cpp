#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, x, y;
int cnt[3][100105];
char s[100105];

int main()
{
    cin >> s + 1 >> m;
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        cnt[0][i] = cnt[0][i - 1];
        cnt[1][i] = cnt[1][i - 1];
        cnt[2][i] = cnt[2][i - 1];
        ++cnt[s[i] - 'x'][i];
    }

    while (m--) {
        cin >> x >> y;
        int mn = 1e9, mx = -1e9;
        mx = max(mx, cnt[0][y] - cnt[0][x - 1]);
        mx = max(mx, cnt[1][y] - cnt[1][x - 1]);
        mx = max(mx, cnt[2][y] - cnt[2][x - 1]);
        mn = min(mn, cnt[0][y] - cnt[0][x - 1]);
        mn = min(mn, cnt[1][y] - cnt[1][x - 1]);
        mn = min(mn, cnt[2][y] - cnt[2][x - 1]);
        cout << (mx - mn > 1 && y - x + 1 >= 3 ? "NO" : "YES") << "\n";
    }

    return 0;
}