#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;
struct node{
    long long all;
    map<int, long long> f;
    set<pair<long long, int> > s;
    node() {
        f.clear();
        s.clear();
        all = 0;
    }
    void add(int x, long long y) {
        auto u = f.find(x);
        if (u == f.end()) {
            f[x] = y;
            s.insert({y, x});
            return;
        }
        if (u->second > y) {
            s.erase({u->second, u->first});
            f[x] = y;
            s.insert({y, x});
        }
    }
    long long getv(int x) {
        return f[x] + all;
    }
    bool own(int x) {
        return f.find(x) != f.end();
    }
    void del(int x) {
        auto u = f.find(x);
        f.erase(u);
        s.erase({u->second, u->first});
    }
    long long get_min() {
        return s.begin()->first + all;
    }
};
int main() {
    vector<node> d;
    d.push_back(node());
    d[0].add(0, 0);
    int n, s;
    scanf("%d %d", &n, &s);
    while (n --) {
        char c[15];
        scanf("%s", c);
        if (c[0] == 's') {
            int x, y;
            scanf("%d %d", &x, &y);
            if (d[d.size() - 1].s.empty()) continue;
            long long v = d[d.size() - 1].get_min();
            d[d.size() - 1].all += y;
            if (x != s)d[d.size() - 1].add(x, v - d[d.size() - 1].all);
        } else
            if (c[0] == 'i'){
                int x;
                scanf("%d", &x);
                d.push_back(node());
                auto &u = d[d.size() - 2], &v= d[d.size() - 1];
                if (u.own(x)) {
                    v.add(x, u.getv(x));
                    u.del(x);
                }
            } else {
                auto &u = d[d.size() - 2], &v= d[d.size() - 1];
                if (u.s.size() < v.s.size()) {
                    swap(u, v);
                }
                for (auto w:v.f)
                    u.add(w.first, w.second + v.all - u.all);
                d.pop_back();
            }
    }
    printf("%lld\n", d[0].get_min());
    return 0;
}