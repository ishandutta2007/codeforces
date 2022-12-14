#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

const int N = 101111;
const int mo = 1000000007;
const LL Seed = 999991;
LL p[N + 111], pow2[N + 111];
int head[N], pre[N];
bool b[N], pp;
int start, destination, num, Deep;
int n, m;

struct Edge{
    int x, next, w;
}gragh[N << 1];

struct Node{
    Node *l, *r;
    bool isFull, flag;
    LL hash;

    Node(){
        isFull = flag = false;
        hash  = 0;
        l = r = NULL;
    }

    Node(const Node *x):l(x->l), r(x->r), hash(x->hash), isFull(x->isFull), flag(x->flag){}

    void pushdown(){
        if (!flag) return;
        hash = 0;
        isFull = false;
        flag = false;
        if (l){
            l = new Node(l);
            l->flag = true;
        }
        if (r){
            r = new Node(r);
            r->flag = true;
        }
    }

    void update(int L, int R){
        pushdown();
        l->pushdown();
        r->pushdown();
        hash = r->hash + l->hash * p[R - ((L + R) >> 1)];
        isFull = (l->isFull && r->isFull);
    }
}*d[N];

bool Less(Node *u, Node *v, int l, int r){
    u->pushdown();
    v->pushdown();
    if (l == r){
        if (u->hash < v->hash) return true; else return false;
    }
    int mid = (l + r) >> 1;
    u->l->pushdown(); u->r->pushdown();
    v->l->pushdown(); v->r->pushdown();
    if (u->r->hash != v->r->hash) return Less(u->r, v->r, mid + 1, r); else return Less(u->l, v->l, l, mid);
}

struct Compare{
    bool operator ()(pair<int, Node*> x, pair<int, Node*> y){
        return Less(y.second, x.second, 0, N);
    }
};

priority_queue<pair<int, Node*>, vector<pair<int, Node*> >, Compare > Q;

void add_edge(int x, int y, int w){
    gragh[++num].x = y;
    gragh[num].next = head[x];
    gragh[num].w = w;
    head[x] = num;
}

Node* build_tree(int l, int r){
    Node *t = new Node();
    if (l == r) return t;
    int mid = (l + r) >> 1;
    t->l = build_tree(l, mid);
    t->r = build_tree(mid + 1, r);
    return t;

}

bool add(Node *&u, int l, int r, int pos){
    if (r < pos) return false;
    u = new Node(u);
    u->pushdown();
    if (pos <= l && u->isFull){
        u->flag = true;
if (pp) cout << '!' << l << ' ' << r << endl;
        return false;
    }
    if (l == r){
        u->hash = 1;
        u->flag = false;
        u->isFull = true;
        return true;
    }
    int mid = (l + r) >> 1;
    bool done = false;
    if (!add(u->l, l, mid, pos)){
        done = add(u->r, mid + 1, r, pos);
    } else done = true;
    u->update(l, r);
if (pp){
    cout << l << ' '<< r << ' ';
    if (u->l->l) cout << u->l->l->flag;
    cout << endl;
}
    return done;
}

int getAns(int l, int r, Node *u){
    u->pushdown();
    if (l == r){
        if (u->hash){
            return pow2[l]; 
        }else return 0;
    }
    int mid = (l + r) >> 1;
    int ans = getAns(l, mid, u->l) + getAns(mid + 1, r, u->r);
    ans %= mo;
    return ans;
}

void dfs(int u){
    if (u == 0){
        printf("%d\n", Deep);
        return;
    }
    ++Deep;
    dfs(pre[u]);
    printf("%d", u);
    if (u != destination) printf(" ");
}

int main(){
    p[0] = 1;
    for (int i = 1; i <= N + 10; ++i)
        p[i] = p[i - 1] * Seed;
    pow2[0] = 1;
    for (int i = 1; i <= N + 10; ++i){
        pow2[i] = pow2[i - 1] << 1;
        pow2[i] %= mo;
    }
    scanf("%d%d", &n, &m);
    num = 0;
    for (int i = 0; i < m; ++i){
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        add_edge(x, y, w);
        add_edge(y, x, w);
    }
    scanf("%d%d", &start, &destination);
    Node *root = build_tree(0, N);
    Node *inf = new Node(root);
    add(inf, 0, N, N - 1);
    for (int i = 1; i <= n; ++i)
        if (i != start) d[i] = new Node(inf);
    d[start] = new Node(root);
    for (int i = 1; i <= n; ++i) b[i] = false;
    for (int i = 1; i <= n; ++i) pre[i] = -1;
    pre[start] = 0;
    Q.push(make_pair(start, d[start]));
    while (!Q.empty()){
        pair<int, Node*> now = Q.top();
        Q.pop();
        if (b[now.first]) continue;
        b[now.first] = true;
        for (int i = head[now.first]; i; i = gragh[i].next)
            if (!b[gragh[i].x]){
                Node *t = now.second;
                add(t, 0, N, gragh[i].w);
                if (Less(t, d[gragh[i].x], 0, N)){
                    d[gragh[i].x] = t;
                    pre[gragh[i].x] = now.first;
                    Q.push(make_pair(gragh[i].x, d[gragh[i].x]));
                }
pp = false;
            }
    }
    if (pre[destination] == -1){
        puts("-1");
        return 0;
    }
    printf("%d\n", getAns(0, N, d[destination])); 
    Deep = 0;
    dfs(destination);
    printf("\n");
    return 0;
}