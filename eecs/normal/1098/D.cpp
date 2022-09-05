#include <bits/stdc++.h>
using namespace std;

int q, num, mn[32];
long long sum[32];
multiset<int> S[32];

int main() {
    scanf("%d", &q);
    while (q--) {
        char op[2]; int x;
        scanf("%s %d", op, &x);
        int t = __builtin_clz(x);
        if (op[0] == '+') {
            S[t].insert(x), num++;
            sum[t] += x, mn[t] = *S[t].begin();
        } else {
            S[t].erase(S[t].find(x)), num--;
            sum[t] -= x, mn[t] = S[t].empty() ? 0 : *S[t].begin();
        }
        int ans = num;
        long long cur = 0;
        for (int i = 31; ~i; i--) {
            if (mn[i] > cur << 1) ans--;
            cur += sum[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}