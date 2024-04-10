#include <algorithm>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
using namespace std;
namespace Revocable_disjoint_set {
    const int N = 1e6;
    struct node{
        int sz, fa;
    }f[N];
    stack<int> record;//
    void init(int n){
        while (!record.empty()) record.pop();
        for (int i = 1; i <= n ; i ++)
            f[i].sz = 1, f[i].fa = i;
    }
    int root(int x){
        while (f[x].fa!=x) x = f[x].fa;
        return x;
    }
    bool merge(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return 0;
        if (f[x].sz > f[y].sz) swap(x, y);
        f[x].fa = y;
        f[y].sz += f[x].sz;
        record.push(x);
        return 1;
    }
    void undo() {
        int x = record.top();
        record.pop();
        f[f[x].fa].sz -= f[x].sz;
        f[x].fa = x;
    }
    void undo_to_x(int x) {
        while (record.size() > x) undo();
    }
}
const int N = 1e6;
int n, q;
map<pair<int, int>, int> f;
struct node{
    int x, y, l, r;
};
vector<node> d;
bool ans[N];
bool try_merge(int x, int y) {
    if (Revocable_disjoint_set::root(x + n) == Revocable_disjoint_set::root(y + n) || Revocable_disjoint_set::root(x) == Revocable_disjoint_set::root(y)) return 0;
    Revocable_disjoint_set::merge(x, y + n);
    Revocable_disjoint_set::merge(y, x + n);
    return 1;
}
void work(int l, int r, vector<node>&d, bool sig) {

    vector<node>dl, dr;
    int mid = (l + r) / 2;
    int t = Revocable_disjoint_set::record.size();
    if (sig) {
        for (auto u:d)
            if (u.l <= l && r <= u.r) {
                if (sig && !try_merge(u.x, u.y)) sig = 0;
            } else {
                if (max(l, u.l) <= min(mid, u.r))
                    dl.push_back(u);
                if (max(mid + 1, u.l) <= min(r, u.r))
                    dr.push_back(u);
            }
    }
    if (l == r) {
        ans[l] = sig;
        return;
    }
    work(l, mid, dl, sig);
    work(mid + 1, r, dr, sig);
    Revocable_disjoint_set::undo_to_x(t);
}
int main() {
    scanf("%d %d", &n, &q);
    Revocable_disjoint_set::init(n + n);
    for (int i = 1; i<= q; i ++)
    {
        int x ,y;
        scanf("%d %d", &x, &y);
        if (f.find(make_pair(x, y))!=f.end()) {
            d.push_back(node{x, y, f[make_pair(x, y)], i - 1});
            f.erase(f.find(make_pair(x, y)));
        }  else
            f[make_pair(x, y)] = i;
    }
    for (auto u:f)
        d.push_back(node{u.first.first,u.first.second, u.second, q});
    work(1, q, d, 1);
    for (int i = 1; i <= q; i ++)
        if (ans[i]) {
            puts("YES");
        } else
            puts("NO");
    return 0;
}