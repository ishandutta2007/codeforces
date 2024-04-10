#include <algorithm>
#include <cstdio>
#define new_node(val, sz, fa, ls, rs, height, balance) (&(*st[avl_cnt ++] = node(val, sz, fa, ls, rs, height, balance)))
#define release(a) (st[--avl_cnt] = a)
#define update(u) (u->height = max(u->son[0]->height, u->son[1]->height) + 1, u->balance = u->son[0]->height - u->son[1]->height, u->sz = u->son[0]->sz + u->son[1]->sz + 1, u->allv = u->son[0]->allv + u->son[1]->allv + u->val)
using namespace std;
const int N = 4e5 + 10;
struct node{
    node * son[2], *fa;
    int height, balance, val, sz;
    long long allv;
    node(int val = 0, int sz = 0, node* fa = NULL, node* ls = NULL, node * rs = NULL, int height = 0, int balance = 0):val(val), sz(sz), fa(fa), height(height), balance(balance){
        son[0] = ls, son[1] = rs;
        allv = val;
    }
}t[N], *root[N], *null, *st[N];
int avl_cnt;
void pre() {
    null = new node(0, 0, NULL, NULL, NULL, 0, 0);
    for (int i = 0; i < N ; i++)
        st[i] = &t[i], root[i] = NULL;
    avl_cnt = 0;
}
void rot(node * u, bool s) {//s=0u 
    node* fa=  u->fa;
    fa->son[s] = u->son[s ^ 1];
    u->son[s^1]->fa = fa;
    u->son[s^1] = fa;
    u->fa = fa ->fa;
    fa->fa = u;
    update(fa);
    update(u);
    if (u->fa != NULL) {
        if (u->fa->son[0] == fa) u->fa->son[0] = u;
        else
            u->fa->son[1] = u;
        update(u->fa);
    }
}
void rebalance(node * u, int rtid) {
    while (1) {
        update(u);
        if (u->balance == 2 || u->balance == -2) {
            bool s = u->balance == -2;
            if (u->son[s]->son[s]->height < u->son[s]->son[s^1]->height)
                rot(u->son[s]->son[s^1], s^1);
            rot(u->son[s], s), u = u->fa;
        }
        if (u->fa == NULL) {
            root[rtid] = u;
            return;
        }else
            u = u->fa;
    }
}

long long spv;
int srk = 0;
void ins(int val, int rtid) {
    if (root[rtid] == NULL)  {
        root[rtid] = new_node(val, 1, NULL, null, null, 1, 0);
        update(root[rtid]);
        return;
    }
    node * u = root[rtid];
    while (1) {
        bool s = (val >= u->val);
        if (u->son[s] == null) {
            if (s == 1) {
                spv += u->val + u->son[0]->allv;
                srk += u->son[0]->sz + 1;
            }
            u->son[s] = new_node(val, 1, u, null, null, 1, 0);
            rebalance(u, rtid);
            return;
        } else  {
            if (s == 1) {
                spv += u->val + u->son[0]->allv;
                srk += u->son[0]->sz + 1;
            }
            u = u->son[s];
        }
    }
}
int n;
int l[N], r[N];
long long allv[N];
long long ans = 0;
#include <set>
#include <vector>
set<pair<int, int> > s;
vector<int> d;
void dfs(node * a) {
    if (a == null) return;
    d.push_back(a->val);
    release(a);
    dfs(a->son[0]), dfs(a->son[1]);
}
int main() {
 //   freopen("input", "r", stdin);
    pre();
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int v;
        scanf("%d %d", &l[i], &v);
        r[i] = l[i];
        ins(v, i);
        allv[i] = 1ll * l[i] * v;
        int x = i;
        while (!s.empty()) {
            auto u = s.lower_bound(make_pair(l[x], 0));
            if (u == s.end() || (u->first > r[x] + 1 && u != s.begin()))
                u--;
            if (u->first > r[x] + 1 || r[u->second] < l[x] - 1)
                break;
            int y = u->second;
            s.erase(u);
            if (r[y] - l[y] > r[x] - l[x]) swap(x, y);
            int sum = r[y] - l[y] +1 + r[x] - l[x] + 1;
            int diff = l[x] - min(l[x], l[y]);
            l[x] = min(l[x], l[y]);
            r[x] = l[x] + sum - 1;
            ans -= allv[y]  + root[x]->allv * diff;
            allv[x] -= root[x]->allv * diff;
            d.clear();
            dfs(root[y]);
            spv = 0;
            for (auto u:d) {
                spv = 0;
                srk = 0;
                ins(u, x);
                allv[x] += spv + 1ll * (l[x]+root[x]->sz - 1 - srk) * u;
                ans += spv + 1ll * (l[x] +root[x]->sz - 1- srk) * u;
            }
        }
        s.insert(make_pair(l[x], x));
        printf("%lld\n", ans);
    }
    return 0;
}