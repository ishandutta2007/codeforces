#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>


using namespace std;


const int maxN = int(2e5) + 10;
const long long INF = 1LL << 60;


struct Tree {
    long long v, add;
    Tree*pl, *pr;
    int l, r, m;
    Tree(int l, int r) {
        this->l = l, this->r = r;
        add = 0;
        m = (l + r) >> 1;
        v = -INF;
        if (l + 1 == r) {
            pl = pr = 0;
            return;
        }
        pl = new Tree(l, m);
        pr = new Tree(m, r);
    }
    void apply(long long a) {
        add += a;
        v += a;
    }
    void relax() { 
        if (!add) {
            return;
        }
        pl->apply(add);
        pr->apply(add);
        add = 0;
    }
    void update() {
        v = max(pl->v, pr->v);
    }
    long long ask(int L, int R) {
        if (L >= R) {
            return -INF;
        }
        if (L == l && R == r) {
            return v;
        }
        relax();
        if (L >= m) {
            return pr->ask(L, R);
        } else if (R <= m) {
            return pl->ask(L, R);
        } else {
            return max(pl->ask(L, m), pr->ask(m, R));
        }
    }
    void addRange(int L, int R, long long a) {
        if (L >= R) {
            return;
        }
        if (L == l && R == r) {
            apply(a);
            return;
        }
        relax();
        if (L >= m) {
            pr->addRange(L, R, a);
        } else if (R <= m) {
            pl->addRange(L, R, a);
        } else {
            pl->addRange(L, m, a);
            pr->addRange(m, R, a);
        }
        update();
    }
    void change(int at, long long to) {
        if (l + 1 == r) {
            v = to;
            return;
        }
        relax();
        if (at < m) {
            pl->change(at, to);
        } else {
            pr->change(at, to);
        }
        update();
    }
}*root;

struct Pay {
    int l;
    long long c;
    Pay(int _l, long long _c) :
            l(_l), c(_c) {
    }
};


vector<Pay> at[maxN];
int nRoads, nPays;
long long cost[maxN];


int main() {
    cin >> nRoads >> nPays;
    for (int i = 1; i <= nRoads; i++) {
        int x;
        scanf("%d", &x);
        cost[i] = x;
    }
    for (int i = 0; i < nPays; i++) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        at[r].push_back(Pay(l, c));
    }
    root = new Tree(0, nRoads + 1);
    root->change(0, 0);
    for (int i = 1; i <= nRoads; i++) {
        long long me = root->ask(0, i);
        root->change(i, me);
        root->addRange(0, i, -cost[i]);
        for(auto e: at[i]) {
            root->addRange(0, e.l, e.c);
        }
    }
    long long ans = root->v;
    cout << ans << endl;
    return 0;
}