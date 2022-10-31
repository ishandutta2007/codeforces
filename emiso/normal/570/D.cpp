#include <bits/stdc++.h>
#define MN 500500

using namespace std;

int n, m, pai[MN], st[MN], fn[MN], arr[2 * MN], cur_time, c[MN], dep[MN];
vector<int> adj[MN];

void dfs(int node, int parent = -1) {
    st[node] = cur_time;
    arr[cur_time++] = node;
    if(parent != -1) dep[node] = 1 + dep[parent];

    for(int i = 0; i < adj[node].size(); i++) {
        if(adj[node][i] != parent) dfs(adj[node][i], node);
    }

    fn[node] = cur_time;
    //arr[cur_time++] = node;
}

int freq[2 * MN][26], odd[2 * MN], l, r = -1, v, d, lq, rq, sqn, ans[MN];
struct qry {
    int l, r, d, id;
    bool operator <(const qry &o) const {
        if(l / sqn == o.l / sqn) return r < o.r;
        return l < o.l;
    }
};
vector<qry> q;

inline void add(int i) {
    freq[dep[arr[i]]][c[arr[i]] - 'a']++;
    odd[dep[arr[i]]] += (freq[dep[arr[i]]][c[arr[i]] - 'a'] % 2)  ? 1 : -1;
}

inline void rem(int i) {
    freq[dep[arr[i]]][c[arr[i]] - 'a']--;
    odd[dep[arr[i]]] += (freq[dep[arr[i]]][c[arr[i]] - 'a'] % 2)  ? 1 : -1;
}

void solve() {
    sort(q.begin(), q.end());

    for(int i = 0; i < q.size(); i++) {
        lq = q[i].l, rq = q[i].r, d = q[i].d;

        while(l < lq) { ///remove -> move l++
            add(l++);
        }
        while(l > lq) { ///move l-- -> add
            add(--l);
        }
        while(r < rq) { ///move r++ -> add
            add(++r);
        }
        while(r > rq) { ///remove -> move r--
            rem(r--);
        }

        ans[q[i].id] = (odd[d - 1] < 2);
    }

}

int main() {
    scanf("%d %d", &n, &m);
    sqn = sqrt(n) + 1;

    for(int i = 2; i <= n; i++) {
        scanf("%d ", &pai[i]);
        adj[pai[i]].push_back(i);
    }

    dfs(1);

    for(int i = 1; i <= n; i++) {
        scanf("%c", &c[i]);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &v, &d);
        lq = st[v];
        rq = fn[v] - 1;
        q.push_back(qry{lq, rq, d, i});
    }

    solve();

    for(int i = 0; i < m; i++) {
        printf("%s\n", ans[i] ? "Yes" : "No");
    }

    return 0;
}