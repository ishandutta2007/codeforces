#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, d[14];
ll ans = LLONG_MAX, f[1 << 13], sum[1 << 13];
string str;

int main() {
    cin >> str, n = str.size();
    reverse(str.begin(), str.end());
    for (int i = 0; i < n; i++) {
        d[i] = isdigit(str[i]) ? str[i] - '0' : str[i] - 'a' + 10;
    }
    int num = accumulate(d, d + n, 0);
    if (num % 15) cout << "NO\n", exit(0);
    auto solve = [&]() {
        memset(f, 0x3f, sizeof(f));
        f[0] = 0, sum[0] = d[n - 1];
        for (int i = 1; i < 1 << (n - 1); i++) {
            int j = __builtin_ctz(i);
            sum[i] = sum[i ^ (1 << j)] + d[j];
        }
        for (int i = 0; i < 1 << (n - 1); i++) {
            if (sum[i] < 0 || sum[i] > 15) continue;
            for (int j = 0; j < n - 1; j++) if (!(i >> j & 1)) {
                f[i | (1 << j)] = min(f[i | (1 << j)], f[i] + (sum[i] << (j << 2)));
            }
        }
        ans = min(ans, f[(1 << (n - 1)) - 1]);
    };
    function<void(int, int)> dfs = [&](int cur, int rem) {
        if (cur == n - 1) {
            if (!rem) solve();
            return;
        }
        dfs(cur + 1, rem);
        d[cur] -= 16, d[cur + 1]++;
        if (rem) dfs(cur + 1, rem - 1);
        d[cur] += 16, d[cur + 1]--;
    };
    dfs(0, num / 15);
    if (ans > 1e18) cout << "NO\n", exit(0);
    str.clear();
    for (int i = 0; i < n; i++, ans /= 16) {
        int c = ans % 16;
        str.push_back(c <= 9 ? c + '0' : c - 10 + 'a');
    }
    reverse(str.begin(), str.end());
    cout << str << "\n";
    return 0;
}