#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int exgcd(int a, int b, LL &x, LL &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    priority_queue<int> hp;
    vector<LL> ans(n + 1);
    for (auto &[x, y] : p) {
        cin >> x >> y;
        ans[0] += y, hp.push(x - y);
    }
    int mid = 0;
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + hp.top();
        if (ans[i] > ans[i - 1]) {
            mid = i;
        }
        hp.pop();
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        LL a, b;
        int d = exgcd(x, y, a, b);
        if (n % d == 0) {
            int mod = y / d;
            a = ((a % mod) * (n / d % mod) % mod + mod) % mod;
            if (a * x > n) {
                puts("-1");
            } else {
                int p = a * x;
                LL q = 1ll * x * y / d;
                int cl = (mid - p) / q;
                p += cl * q;
                LL val = ans[p];
                if (p + q <= n) {
                    val = max(val, ans[p + q]);
                }
                printf("%lld\n", val);
            }
        } else {
            puts("-1");
        }
    }
    return 0;
}