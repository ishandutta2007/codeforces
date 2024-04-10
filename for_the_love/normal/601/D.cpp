#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 3e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

struct Trie{
    int last;
    Trie *next[26];
    Trie(){memset(next, 0, sizeof(next)); last = 0;}
} *root;

int fa[N][20], dep[N], c[N], cnt[N];
vector <int> e[N];

void dfs(int x, int par){
    fa[x][0] = par;
    dep[x] = dep[par] + 1;
    for (int i = 1; i < 20; i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != par)
        dfs(e[x][i], x);
}

int lca(int x, int y){
    if (dep[x] < dep[y]) swap(x, y);
    int t = dep[x] - dep[y];
    for (int i = 19; i >= 0; i--)
    if (t >> i & 1) x = fa[x][i];
    if (x == y) return x;
    for (int i = 19; i >= 0; i--)
    if (fa[x][i] != fa[y][i])
        x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

char s[N];

void calc(int x, int par, Trie* cur){
    if (!cur->next[s[x] - 'a']) cur->next[s[x] - 'a'] = new Trie();
    cur = cur->next[s[x] - 'a'];
    if (cur->last){ 
        int y = lca(x, cur->last);
        cnt[y]--;
    }
    cur->last = x;
    cnt[x] = 1;
    for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != par){
        calc(e[x][i], x, cur);
        cnt[x] += cnt[e[x][i]];
    }
}

int main(){
//    freopen("in.txt", "r", stdin);
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    scanf("%s", s + 1);
    for (int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    root = new Trie();
    calc(1, 0, root);
    int ans = 0, tot = 0;
    for (int i = 1; i <= n; i++)
    if (ans < c[i] + cnt[i]){
        ans = c[i] + cnt[i];
        tot = 1;
    }else if (ans == c[i] + cnt[i]) tot++;
    printf("%d\n%d\n", ans, tot);
}