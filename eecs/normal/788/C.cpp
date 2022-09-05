#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, K, used[maxn];
vector<int> V, leq, geq;

int main() {
    scanf("%d %d", &n, &K);
    while (K--) {
        int x; scanf("%d", &x);
        if (used[x]) continue;
        used[x] = 1, V.push_back(x);
        if (x == n) puts("1"), exit(0);
        if (x < n) leq.push_back(n - x);
        else geq.push_back(x - n);
    }
    if (leq.empty() || geq.empty()) puts("-1"), exit(0);
    bitset<maxn * 1000 * 2> b, c;
    b[0] = 1;
    for (int i = 1; ; i++) {
        c.reset();
        for (int j : V) c |= (b << j);
        b = c;
        if (b.test(n * i)) printf("%d\n", i), exit(0);
    }
    return 0;
}