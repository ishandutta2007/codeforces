#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector < int > k[200010];
struct node {
    ll a, b;
} ans;
int operator < (const node &a, const node &b) {
    return 1ll * a.a * b.b < 1ll * b.a * a.b;
}
ll cur[200010], sum[200010];
int id[200010];
inline void get(int S) {
    for (int i = 1; i <= 200000; i++) {
        cur[i] = 0;
        id[i] = i;
        for (auto j : k[i]) cur[i] += min(S, j);
    }
    sort(id + 1, id + 1 + 200000, [](int a, int b) {
        return cur[a] > cur[b];
    });
    for (int i = 1; i <= 200000; i++) sum[i] = sum[i - 1] + cur[id[i]];
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int m, cur;
        scanf("%d%d", &m, &cur);
        k[m].push_back(cur);
    }
    for (int i = 1; i <= n; i++) {
        if (i <= 20) get(i);
        if (i == 1) ans = node{sum[i], i};
        else if (ans < node{sum[i], i}) ans = node{sum[i], i};
    }
    get(ans.b);
    printf("%lld\n", ans.b);
    for (int i = 1; i <= ans.b; i++) printf("%d%c", id[i], " \n"[i == ans.b]);
}