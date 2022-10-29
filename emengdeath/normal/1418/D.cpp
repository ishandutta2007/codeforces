#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
multiset<int> g;
set<int> f;
int n, m;
void insert(int x) {
    auto u = f.upper_bound(x);
    if (u != f.end() && u != f.begin()) {
        g.erase(g.find(*u - *prev(u)));
    }
    auto v = f.insert(x).first;
    if (v != f.begin())
        g.insert(x - *prev(v));
    if (next(v) != f.end())
        g.insert(*next(v) - x);
}
void erase(int x) {
    auto u = f.lower_bound(x);
    if (u != f.begin())
        g.erase(g.find(x - *prev(u)));
    if (next(u) != f.end()) {
        g.erase(g.find(*next(u) - x));
        if (u != f.begin())
            g.insert(*next(u) - *prev(u));
    }
    f.erase(u);
}
void outputans() {
    if (f.size() <= 2) printf("0\n");
    else
        printf("%d\n", *f.rbegin() - *f.begin() - *g.rbegin());
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        insert(x);
    }
    outputans();
    while (m -- ){
        int x, y;
        scanf("%d %d", &x, &y);
        if (x)
            insert(y);
        else
            erase(y);
        outputans();
    }
    return 0;
}