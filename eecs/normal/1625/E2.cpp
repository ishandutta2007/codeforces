#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

const int maxn = 300010;
int n, q, pre[maxn], nxt[maxn];
char s[maxn];
long long c[maxn];
vector<int> V[maxn * 2];
vector<pair<int, int>> seg[maxn * 2];
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tr[maxn * 2];

void add(int p, long long v) {
    for (; p <= n; p += p & -p) c[p] += v;
}

long long query(int p) {
    long long s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

int main() {
    scanf("%d %d %s", &n, &q, s + 1);
    pre[0] = n, V[n].push_back(0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (s[i] == '(') pre[i]++;
        if (s[i] == ')') pre[i]--;
        V[pre[i]].push_back(i);
    }
    vector<int> st;
    for (int i = n; ~i; i--) {
        while (!st.empty() && pre[i] <= pre[st.back()]) st.pop_back();
        nxt[i] = st.empty() ? n + 1 : st.back(), st.push_back(i);
    }
    for (int i = 0; i <= 2 * n; i++) if (!V[i].empty()) {
        for (int x : V[i]) tr[i].insert(x);
        for (int l = 0, r; l < V[i].size(); l = r) {
            if (s[V[i][l] + 1] == '(') {
                for (r = l; r < V[i].size() && nxt[V[i][l]] > V[i][r]; r++);
                long long t = 1LL * (r - l - 1) * (r - l) / 2;
                add(V[i][l] + 1, t);
                seg[i].push_back({V[i][l], V[i][r - 1]});
            } else {
                r = l + 1;
            }
        }
    }
    while (q--) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) {
            assert(pre[l - 1] == pre[r]);
            auto it = prev(lower_bound(seg[pre[r]].begin(), seg[pre[r]].end(), make_pair(l, 0)));
            assert(it->first < l && it->second >= l - 1);
            int num = tr[pre[r]].order_of_key(it->second) - tr[pre[r]].order_of_key(it->first);
            tr[pre[r]].erase(l - 1);
            add(it->first + 1, 1LL * (num - 1) * num / 2 - 1LL * num * (num + 1) / 2);
        } else {
            long long res = query(r) - query(l);
            int k = tr[pre[r]].order_of_key(r) - tr[pre[r]].order_of_key(l - 1);
            res += 1LL * k * (k + 1) / 2;
            printf("%lld\n", res);
        }
    }
    return 0;
}