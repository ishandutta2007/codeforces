#include <bits/stdc++.h>
#define fir first
#define sec second
using namespace std;

typedef pair<int, int> P;
const int maxn = 100010;
int n, K, cur, tag;
vector<P> G[maxn], fish[maxn];

inline int get(P A) { return A.fir + (A.sec > 0 ? -tag : tag); }
struct comp { bool operator () (P A, P B) { return get(A) < get(B); } };

struct DS {
    int tag;
    set<P, comp> diff;
    set<pair<int, P>> S;

    void ins_collision(P A, P B) {
        if (A.sec < 0 && B.sec > 0) S.emplace((B.fir - A.fir + 1) / 2, A);
    }
    void del_collision(P A, P B) {
        if (A.sec < 0 && B.sec > 0) S.erase({(B.fir - A.fir + 1) / 2, A});
    }
    void ins(set<P, comp>::iterator it) {
        auto pre = it, nxt = next(it);
        if (pre != diff.begin()) {
            ins_collision(*--pre, *it);
            if (nxt != diff.end()) del_collision(*pre, *nxt);
        }
        if (nxt != diff.end()) ins_collision(*it, *nxt);
    }
    void del(set<P, comp>::iterator it) {
        auto pre = it, nxt = next(it);
        if (pre != diff.begin()) {
            del_collision(*--pre, *it);
            if (nxt != diff.end()) ins_collision(*pre, *nxt);
        }
        if (nxt != diff.end()) del_collision(*it, *nxt);
        diff.erase(it);
    }
    void ins(P v) {
        if (!v.sec) return;
        int o = v.fir;
        ::tag = tag, v.fir += v.sec > 0 ? tag : -tag;
        auto it = diff.find(v);
        if (it != diff.end()) v.sec += it->sec, del(it);
        if (!v.sec) return;
        v.fir = o + (v.sec > 0 ? tag : -tag);
        ins(it = diff.insert(v).fir);
    }
    int delta(int p) {
        ::tag = tag;
        auto it = diff.find({p + tag, 1});
        return it != diff.end() ? it->sec : 0;
    }

    void advance(int l) {
        ::tag = tag;
        while (!S.empty() && S.begin()->fir - tag <= l) {
            auto p = *S.begin();
            auto it = diff.find(p.sec);
            auto L = *it;
            it++, del(prev(it));
            auto R = *it; del(it);
            if (L.sec += R.sec) ins({get(L.sec > 0 ? R : L), L.sec});
        }
        tag += l;
    }
    void merge(DS &o) {
        if (diff.size() < o.diff.size()) swap(tag, o.tag), swap(diff, o.diff), swap(S, o.S);
        static vector<P> tmp;
        ::tag = o.tag, tmp.clear();
        for (auto p : o.diff) tmp.emplace_back(get(p), p.sec);
        ::tag = tag;
        for (auto p : tmp) ins(p);
    }
    void upd(vector<P> &fish, int l) {
        ::tag = tag;
        vector<int> tmp;
        for (auto p : fish) {
            int a = delta(p.fir - 1), b = delta(p.fir), c = delta(p.fir + 1);
            tmp.push_back(max(0, p.sec + a + b - max({a, a + b, a + b + c})));
        }
        advance(1);
        for (int i = 0; i < fish.size(); i++) if (tmp[i]) {
            ins({fish[i].fir, tmp[i]}), ins({fish[i].fir + 1, -tmp[i]});
        }
        advance(l - 1);
    }
    void print() {
        ::tag = tag;
        int cur = 0, mx = 0;
        for (auto p : diff) mx = max(mx, cur += p.sec);
        printf("%d\n", mx);
    }
} f[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w), w <<= 1;
        G[u].emplace_back(v, w), G[v].emplace_back(u, w);
    }
    scanf("%d", &K);
    while (K--) {
        int d, f, p; scanf("%d %d %d", &d, &f, &p);
        fish[p].emplace_back(d << 1, f);
    }
    function<void(int, int, int)> dfs = [&](int v, int fa, int w) {
        for (auto e : G[v]) if (e.fir ^ fa) {
            dfs(e.fir, v, e.sec), f[v].merge(f[e.fir]);
        }
        f[v].upd(fish[v], w);
    };
    dfs(1, 0, 1), f[1].print();
    return 0;
}