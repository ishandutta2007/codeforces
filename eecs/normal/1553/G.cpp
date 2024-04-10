#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, q, a[maxn], mark[maxn], prime[maxn], fa[maxn], fir[maxn];
unordered_set<int> S[maxn];
map<pair<int, int>, int> mp;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), mark[a[i]] = i;
    }
    iota(fa + 1, fa + n + 1, 1);
    for (int i = 2; i <= 1000001; i++) if (!prime[i]) {
        int o = 0;
        for (int j = i; j <= 1000001; j += i) {
            if (mark[j]) {
                if (o) fa[find(o)] = find(mark[j]);
                o = mark[j];
            }
            if (j > i) prime[j] = 1;
        }
        fir[i] = o;
    }
    for (int i = 1; i <= n; i++) {
        int x = a[i] + 1;
        S[find(i)].insert(i);
        for (int j = 1; j * j <= x; j++) if (!(x % j)) {
            if (fir[j]) S[find(fir[j])].insert(i);
            if (fir[x / j]) S[find(fir[x / j])].insert(i);
        }
    }
    while (q--) {
        int s, t;
        scanf("%d %d", &s, &t);
        s = find(s), t = find(t);
        pair<int, int> p(min(s, t), max(s, t));
        if (mp.count(p)) { printf("%d\n", mp[p]); continue; }
        if (s == t) { printf("%d\n", mp[p] = 0); continue; }
        bool flag = 0;
        if (S[s].size() > S[t].size()) swap(s, t);
        for (int x : S[s]) if (S[t].count(x)) { flag = 1; break; }
        printf("%d\n", mp[p] = flag ? 1 : 2);
    }
    return 0;
}