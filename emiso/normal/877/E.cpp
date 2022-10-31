#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a, c, arr[MN], t = 1, st[MN], ft[MN];
vector<int> adj[MN];

void calc(int node, int parent) {
    arr[t] = node;
    st[node] = t++;

    for(int i=0;i<adj[node].size();i++) {
        int v = adj[node][i];
        if(v == parent) continue;

        calc(v, node);
    }

    ft[node] = t;
}

int tree[800400][2], lazy[800400], N, Q;

inline int gm(int a,int b) {
    return a+(b-a)/2;
}

void build(int node,int a,int b) {
    if(a==b) {
        tree[node][0] = 1;
        return;
    }
    build(node*2,a,gm(a,b));
    build(node*2+1,gm(a,b)+1,b);
    tree[node][0] = tree[node*2][0] + tree[node*2+1][0];
}

void update(int node, int a, int b, int x, int y) {
    if(lazy[node] != 0) {
        if(a!=b) {
            lazy[node*2] = (lazy[node*2]+lazy[node])%2;
            lazy[node*2+1] = (lazy[node*2+1]+lazy[node])%2;
        }
        while(lazy[node] > 0) {
            swap(tree[node][0], tree[node][1]);
            lazy[node]--;
        }
    }

    if(x > b || y < a) return;

    if(a>=x && b<=y) {
        swap(tree[node][0], tree[node][1]);
        if(a!=b) {
            lazy[node*2] = (lazy[node*2]+1)%2;
            lazy[node*2+1] = (lazy[node*2+1]+1)%2;
        }
        return;
    }

    update(node*2,a,gm(a,b),x,y);
    update(node*2+1,gm(a,b)+1,b,x,y);

    tree[node][0] = tree[node*2][0] + tree[node*2+1][0];
    tree[node][1] = tree[node*2][1] + tree[node*2+1][1];
}

int query(int node, int a, int b, int x, int y) {
    if(lazy[node] != 0) {
        if(a!=b) {
            lazy[node*2] = (lazy[node*2]+lazy[node])%2;
            lazy[node*2+1] = (lazy[node*2+1]+lazy[node])%2;
        }
        while(lazy[node] > 0) {
            swap(tree[node][0], tree[node][1]);
            lazy[node]--;
        }
    }
    if(x > b || y < a) return 0;

    if(x <= a && y >= b) return tree[node][1];
    return query(node*2, a, gm(a,b), x, y)
          + query(node*2+1, gm(a,b)+1, b, x, y);
}

int main() {
    scanf("%d", &n);

    for(int i=2;i<=n;i++) {
        scanf("%d", &a);
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    calc(1, -1);
    build(1, 1, t+1);
    for(int i=1;i<=n;i++) {
        scanf("%d", &c);
        if(c) update(1, 1, t+1, st[i], st[i]);
    }

    int q;
    scanf("%d", &q);
    while(q--) {
        int v; char op[10];
        scanf("%s %d", op, &v);

        if(op[0] == 'g') {
            printf("%d\n", query(1, 1, t+1, st[v], ft[v]-1));
        }

        else if(op[0] == 'p') {
            update(1, 1, t+1, st[v], ft[v]-1);
        }

        else assert(false);
    }
    return 0;
}