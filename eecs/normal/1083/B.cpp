#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, K, tot = 1, ch[maxn][2];
char s[maxn];
bool ban[maxn][2];
vector<int> V;

void dfs(int k, int dep) {
    if (!k) { V.push_back(n - dep); return; }
    if (dep == n) return;
    if (ch[k][0] || !ban[k][0]) dfs(ch[k][0], dep + 1);
    if (ch[k][1] || !ban[k][1]) dfs(ch[k][1], dep + 1);
}

int main() {
    scanf("%d %d", &n, &K);
    if (K == 1) printf("%d\n", n), exit(0);
    scanf("%s", s + 1);
    K -= 2;
    int cur = 1;
    long long ans = n;
    for (int i = 1; i <= n; i++) {
        int c = s[i] - 'a';
        if (!ch[cur][c]) ch[cur][c] = ++tot;
        if (c) ban[cur][0] = 1;
        cur = ch[cur][c];
    }
    scanf("%s", s + 1), cur = 1;
    for (int i = 1; i <= n; i++) {
        int c = s[i] - 'a';
        if (!ch[cur][c]) ch[cur][c] = ++tot, ans++;
        if (!c) ban[cur][1] = 1;
        cur = ch[cur][c];
    }
    dfs(1, 0);
    if (V.empty()) printf("%lld\n", ans), exit(0);
    int mx = *max_element(V.begin(), V.end()) + 1;
    while (1) {
        long long num = 0;
        for (int x : V) if (x + 1 >= mx) {
            if (x + 1 == mx) {
                num++;
            } else {
                if (x - mx > 30) { num = 1e18; break; }
                num += 1LL << (x - mx);
            }
        }
        long long t = min(num, (long long)K);
        ans += t * mx, K -= t;
        if (!K || !t) break;
        mx--;
    }
    printf("%lld\n", ans);
    return 0;
}