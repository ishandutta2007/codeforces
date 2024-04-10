#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
struct node{
    int son[2];
    int size, v, key, cnt;
    int tagv, tagcnt;
    node(int V = 0, int SIZE = 0){
        son[0] = 0;
        son[1] = 0;
        size = SIZE;
        v = V;
        key = rand();
        tagv = tagcnt = 0;
        cnt = 0;
    }
    void upd(int _tagcnt, int _tagv) {
        tagcnt += _tagcnt;
        tagv += _tagv;
        cnt += _tagcnt;
        v += _tagv;
    }
}T[N];
int root;
void update(int x) {
    if (!x) return;
    T[x].size = 1 + T[T[x].son[0]].size + T[T[x].son[1]].size;
}
void down(int x) {
    if (T[x].son[0]) T[T[x].son[0]].upd(T[x].tagcnt, T[x].tagv);
    if (T[x].son[1]) T[T[x].son[1]].upd(T[x].tagcnt, T[x].tagv);
    T[x].tagv = T[x].tagcnt = 0;
}
int merge(int a, int b) {//ab
    if (!a) return b;
    if (!b) return a;
    down(a);
    down(b);
    if (T[a].key < T[b].key) {//keykey
        T[a].son[1] = merge(T[a].son[1], b);
        update(a);
        return a;
    } else {
        T[b].son[0] = merge(a, T[b].son[0]);
        update(b);
        return b;
    }
}
pair<int, int> split(int a, int k){
    if (!a) return {0, 0};
    pair<int, int> s;
    down(a);
    if (k >= T[a].size) return make_pair(a, 0);
    if (T[T[a].son[0]].size >= k) {
        s = split(T[a].son[0], k);
        T[a].son[0] = s.second;
        s.second = a;
    } else {
        s = split(T[a].son[1], k - T[T[a].son[0]].size - 1);
        T[a].son[1] = s.first;
        s.first = a;
    }
    update(a);
    return s;
}
int findl(int s, int x){
    if (!s)return -100000000;
    down(s);
    if (T[s].v<x){
        return max(findl(T[s].son[1],x)+T[T[s].son[0]].size+1,T[T[s].son[0]].size+1);
    }else
        return findl(T[s].son[0],x);
}
int right(int s) {
    if (!s) return -1e9;
    while (T[s].son[1]) {
        down(s);
        s = T[s].son[1];
    }
    return s;
}
int left(int s) {
    if (!s) return 1e9;
    while (T[s].son[0]) {
        down(s);
        s = T[s].son[0];
    }
    return s;
}
int merge_t(int x, int y) {
    if (!x) return y;
    if (!y) return x;
    int l = right(x), r = left(y);
    while (l != -1e9 && r != 1e9 && T[l].v > T[r].v) {
        auto u = split(x, findl(x, T[r].v + 1));
        auto v = split(y, findl(y, T[r].v + 1));
        x = merge(merge(u.first, v.first), u.second);
        y = v.second;
        l = right(x), r = left(y);
    }
    return merge(x, y);
}
int n, m;
pair<int, int> a[N];
int ans[N];
void dfs1(int x){
    if (!x) return;
    down(x);
    ans[x] = T[x].cnt;
    dfs1(T[x].son[0]);
    dfs1(T[x].son[1]);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n;i ++) {
        scanf("%d %d", &a[i].second, &a[i].first);
        a[i].first *= -1;
    }
    sort(a + 1, a + n +1);
    scanf("%d", &m);
    root = 1;
    for (int i = 1; i <= m; i ++)
    {
        int x;
        scanf("%d", &x);
        T[i] = node(x, 1);
        if (i != 1) {
            root = merge_t(root, i);
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (!root) break;
        int x = findl(root, a[i].second);
        if (x == m) continue;
        if (x < 0) {
            T[root].upd(1, -a[i].second);
        } else {
            auto u = split(root, x);
            T[u.second].upd(1, -a[i].second);
            root = merge_t(u.first, u.second);
        }
        x = findl(root, 1);
        if (x > 0) {
            auto u = split(root, x);
            root = u.second;
            dfs1(u.first);
        }
    }
    dfs1(root);
    for (int i = 1; i <= m; i ++)
        printf("%d%c", ans[i], " \n"[i == m]);
    return 0;
}