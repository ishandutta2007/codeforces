#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 9;

#define lx t[f].lc
#define rx t[f].rc

struct VNode{
    int sz, a[10];
    void push(int x){
        a[sz++] = x;
    }
    void add(int x){
        if (sz < 10) a[sz++] = x;
        else{
            for (int i = 0; i < 10; i++)
            if (x < a[i]){
                for (int j = 8; j >= i; j--)
                    a[j + 1] = a[j];
                a[i] = x;
                break;
            }
        }
    }

};

struct Tnode{
    int lc, rc, fa;
    VNode vec;
} t[N];
struct Edge{
    int y, next;
} e[N + N];

VNode vec[N];

int par[N];
int tot, head[N];



void Addedge(int x, int y){
    e[++tot].y = y; e[tot].next = head[x]; head[x] = tot;
    e[++tot].y = x; e[tot].next = head[y]; head[y] = tot;
}


VNode merge(const VNode &a, const VNode &b){
    int l = 0, r = 0;
    VNode ret;
    ret.sz = 0;
    while (ret.sz < 10 && (l < a.sz || r < b.sz)){
        if (l < a.sz && r < b.sz){
            if (a.a[l] < b.a[r]) ret.push(a.a[l++]);
            else ret.push(b.a[r++]);
        }else if (l < a.sz) ret.push(a.a[l++]);
        else ret.push(b.a[r++]);
    }
    return ret;
}



void Update(int f, int x, int flag){
    if (x) t[x].fa = f;
    if (f){
        if (flag) t[f].lc = x; else t[f].rc = x;
        t[f].vec = merge(vec[f], merge(t[lx].vec, t[rx].vec));
    }
}

void Up(int x){
    int y = t[x].fa, z = t[y].fa;
    if (t[y].lc == x){
        Update(y, t[x].rc, 1);
        Update(x, y, 0);
        Update(z, x, t[z].lc == y);
    }else{
        Update(y, t[x].lc, 0);
        Update(x, y, 1);
        Update(z, x, t[z].lc == y);
    }
}

void Splay(int x){
    int y = t[x].fa, z = t[y].fa, rt = x;
    while (t[rt].fa) rt = t[rt].fa;
    while (y){
        if (z && (t[z].lc == y) == (t[y].lc == x)) Up(y);
        Up(x); y = t[x].fa; z = t[y].fa;
    }
    par[x] = par[rt]; if (x != rt) par[rt] = 0;
}

void Access(int x){
    int y = x; x = 0;
    while (y){
        Splay(y);
        t[t[y].rc].fa = 0;
        if (t[y].rc) par[t[y].rc] = y;
        Update(y, x, 0);
        par[x] = 0;
        x = y;
        y = par[y];
    }
}

VNode Calc(int x){
    int y = x;  x = 0;
    Splay(y);
    if (!par[y]){
        return merge(vec[y], t[t[y].rc].vec);
    }
    while (1){
        Splay(y);
        if (!par[y]) break;
        t[t[y].rc].fa = 0;
        if (t[y].rc) par[t[y].rc] = y;
        Update(y, x, 0);
        x = y;
        y = par[y];
    }
    return merge(merge(t[x].vec, t[t[y].rc].vec), vec[y]);
}
void Dfs(int x, int parent){
    vec[x] = t[x].vec;
    par[x] = parent;
    for (int p = head[x]; p != -1; p = e[p].next)
    if (e[p].y != parent) Dfs(e[p].y, x);
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, q, x, y, z;
    scanf("%d%d%d", &n, &m, &q);
    tot = -1, memset(head, -1, sizeof(head));
    for (int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        Addedge(x, y);
    }
    for (int i = 0; i < m; i++){
        scanf("%d", &x);
        t[x].vec.add(i + 1);
    }
    Dfs(1, 0);
    while (q--){
        scanf("%d%d%d", &x, &y, &z);
        Access(x);
        VNode ans = Calc(y);
        printf("%d", min(ans.sz, z));
        for (int i = 0; i < min(ans.sz, z); i++)
            printf(" %d", ans.a[i]);
        puts("");
    }
}