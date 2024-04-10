#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, s, tot, val[maxn], cost[maxn], lnk[maxn];
char op[maxn][5];

struct node {
    ll tag = 0;
    map<int, ll> mp;
    multiset<ll> S;
} t[maxn];

void chk(int k, int p, ll v) {
    if (!t[k].mp.count(p)) { t[k].mp[p] = v, t[k].S.insert(v); return; }
    ll o = t[k].mp[p];
    if (o <= v) return;
    t[k].S.erase(t[k].S.find(o));
    t[k].mp[p] = v, t[k].S.insert(v);
}

int main() {
    scanf("%d %d", &n, &s);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        scanf("%s", op[i]);
        if (op[i][0] == 's') scanf("%d %d", &val[i], &cost[i]);
        if (op[i][0] == 'i') scanf("%d", &val[i]), st.push(i);
        if (op[i][0] == 'e') lnk[st.top()] = i, st.pop();
    }
    auto comb = [&](int i, int j) {
        if (t[i].mp.size() < t[j].mp.size()) {
            swap(t[i].mp, t[j].mp), swap(t[i].S, t[j].S);
            swap(t[i].tag, t[j].tag);
        }
        for (auto &p : t[j].mp) {
            chk(i, p.first, p.second + t[j].tag - t[i].tag);
        }
    };
    function<int(int, int, int)> solve = [&](int l, int r, int init) {
        int k = ++tot;
        t[k].mp[init] = 0, t[k].S = {0};
        for (int i = l; i <= r; i++) {
            if (op[i][0] == 's') {
                t[k].tag += cost[i];
                if (val[i] == s) continue;
                ll v = *t[k].S.begin();
                chk(k, val[i], v - cost[i]);
            } else {
                int j = lnk[i], _k = solve(i + 1, j - 1, val[i]);
                if (t[k].mp.count(val[i])) {
                    t[_k].tag += t[k].mp[val[i]] + t[k].tag;
                    t[k].S.erase(t[k].S.find(t[k].mp[val[i]])), t[k].mp.erase(val[i]);
                    comb(k, _k);
                }
                i = j;
            }
        }
        return k;
    };
    int k = solve(1, n, 0);
    ll ans = LLONG_MAX;
    for (auto &p : t[k].mp) ans = min(ans, p.second);
    printf("%lld\n", ans + t[k].tag);
    return 0;
}