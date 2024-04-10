#include <bits/stdc++.h>

#define MN 1001000

using namespace std;

int t, n, nxt[MN], ans[MN];
vector<pair<int, int>> adj[MN];
queue<int> fila;

int tree[4*MN], lazy[4*MN];

void push(int no, int l, int r) {
    if(lazy[no]) {
        tree[no] += lazy[no];
        if(l != r) {
            lazy[no*2] += lazy[no];
            lazy[no*2+1] += lazy[no];
        }
        lazy[no] = 0;
    }
}

void upd(int no, int l, int r, int lq, int rq, int val) {
    push(no, l, r);
    if(rq < l || r < lq) return;
    if(lq <= l && r <= rq) {
        lazy[no] += val;
        push(no, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(no*2, l, m, lq, rq, val);
    upd(no*2+1, m+1, r, lq, rq, val);
    tree[no] = min(tree[no*2], tree[no*2+1]);
}

int query(int no, int l, int r) {
    push(no, l, r);
    if(l == r) return l;
    int m = (l + r) / 2;
    push(no*2,   l,   m);
    push(no*2+1, m+1, r);
    if(tree[no*2] <= tree[no*2+1]) return query(no*2, l, m);
    else return query(no*2+1, m+1, r);
}

int query(int no, int l, int r, int pos) {
    push(no, l, r);
    if(l == r) return tree[no];

    int m = (l + r) / 2;
    if(pos <= m) return query(no*2, l, m, pos);
    else return query(no*2+1, m+1, r, pos);
}

bool check(int no, int l, int r) {
    int minidx = query(no, l, r);
    int minval = query(no, l, r, minidx);

    //printf("%d %d\n", minidx, minval);

    if(minval <= 0) {
        fila.push(minidx);
        upd(no, l, r, minidx, minidx, 1000000);
        return true;
    } else return false;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int tmp = n;
        for(int i = 0; i <= 4*n; i++) tree[i] = lazy[i] = 0;

        for(int i = 1; i <= n; i++) {
            scanf("%d", &nxt[i]);
            if(nxt[i] != -1) {
                if(i + 1 <= nxt[i] - 1) {
                    upd(1, 1, n, i + 1, nxt[i] - 1, 1);
                    adj[i].emplace_back(i + 1, nxt[i] - 1);
                }
                if(nxt[i] <= n) {
                    upd(1, 1, n, i, i, 1);
                    adj[nxt[i]].emplace_back(i, i);
                }
            }
        }

        while(check(1, 1, n));
        while(!fila.empty()) {
            int u = fila.front(); fila.pop();
            ans[u] = tmp--;
            //printf("%d %d\n", u, tmp);

            for(auto tt : adj[u]) upd(1, 1, n, tt.first, tt.second, -1);
            while(check(1, 1, n));
        }

        if(tmp == 0) {
            for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
            puts("");
        } else puts("-1");

        for(int i = 0; i <= n; i++) adj[i].clear();
    }
    return 0;
}