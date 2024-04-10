#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 100010;
int n, a[maxn], pre[maxn];
bool vis[maxn];
vector<int> V, pos[maxn];
unordered_map<ull, long long> mp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        bool flag = 1;
        for (int x = a[i]; x; x /= 10) {
            flag &= x % 10 == 4 || x % 10 == 7;
        }
        if (flag) V.push_back(i);
    }
    long long ans = 0;
    map<int, int> lst;
    for (int i = 0; i < V.size(); i++) {
        if (!lst.count(a[V[i]])) lst[a[V[i]]] = i;
        pos[pre[i] = lst[a[V[i]]]].push_back(i);
    }
    for (int i = 0; i < V.size(); i++) {
        fill(vis, vis + V.size(), 0);
        set<int> S = {V.size()};
        auto calc = [&](int l, int r) {
            int len = (r == V.size() ? n + 1 : V[r]) - V[l] - 1;
            return 1LL * len * (len + 1) / 2;
        };
        long long ways = 0, cur = 0;
        for (int j = i; j < V.size(); j++) {
            if (!vis[pre[j]]) {
                for (int k : pos[pre[j]]) if (k > i) {
                    auto it = S.insert(k).first;
                    if (it != S.begin() && next(it) != S.end()) cur -= calc(*prev(it), *next(it));
                    if (it != S.begin()) cur += calc(*prev(it), k);
                    if (next(it) != S.end()) cur += calc(k, *next(it));
                }
                vis[pre[j]] = 1;
            }
            while (*S.begin() <= j) {
                if (S.size() > 1) cur -= calc(*S.begin(), *next(S.begin()));
                S.erase(S.begin());
            }
            ways += 1LL * ((j + 1 == V.size() ? n + 1 : V[j + 1]) - V[j]) * cur;
            int len = (*S.begin() == V.size() ? n + 1 : V[*S.begin()]) - V[j];
            int ub = min(len, (j + 1 == V.size() ? n + 1 : V[j + 1]) - V[j]);
            int lb = len - ub, rb = len - 1;
            long long sum = 1LL * (lb + rb) * (rb - lb + 1) / 2;
            sum += (1LL * rb * (rb + 1) * (2 * rb + 1) - 1LL * (lb - 1) * lb * (2 * lb - 1)) / 6;
            ways += sum / 2;
        }
        ans += (V[i] - (i ? V[i - 1] : 0)) * ways;
    }
    for (int i = 1; i <= n; i++) {
        auto it = upper_bound(V.begin(), V.end(), i);
        ans += 1LL * (n - i) * (n - i + 1) / 2 * (i - (it == V.begin() ? 0 : *prev(it)));
    }
    printf("%lld\n", ans);
    return 0;
}