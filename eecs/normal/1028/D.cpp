#include <bits/stdc++.h>
using namespace std;

const int maxn = 400000, P = 1000000007;
int n, ans = 1, cnt;
char op[10];
set<int> S;

int main() {
    scanf("%d", &n);
    S.insert(0), S.insert(INT_MAX);
    int l = 0, r = INT_MAX;
    for (int i = 1, p; i <= n; i++) {
        scanf("%s %d", op, &p);
        if (op[1] == 'D') {
            S.insert(p);
        } else {
            if (p < l || p > r) puts("0"), exit(0);
            if (p != l && p != r) (ans <<= 1) %= P;
            auto it = S.find(p);
            l = *prev(it), r = *next(it), S.erase(it);
        }
    }
    for (auto it = S.find(l); *it < r; it++) cnt++;
    printf("%lld\n", 1LL * cnt * ans % P);
    return 0;
}