#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        multiset<int> S;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), S.insert(a[i]);
        }
        long long sum = accumulate(a + 1, a + n + 1, 0LL);
        bool flag = 1;
        int cnt = 0;
        function<void(long long)> solve = [&](long long x) {
            if (!flag) return;
            if (S.count(x)) { S.erase(S.find(x)); return; }
            if (x == 1 || ++cnt > n) { flag = 0; return; }
            solve(x / 2), solve(x - x / 2);
        };
        solve(sum);
        puts(flag && S.empty() ? "YES" : "NO");
    }
    return 0;
}