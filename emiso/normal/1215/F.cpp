#include <bits/stdc++.h>

using namespace std;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

template<int SZ> struct TwoSat {
    vector<int> radj[2*SZ];
    int N = 0, ans[SZ];
    TwoSat(int N_): N(N_+1) {}
    int addVar() { return N++;}
    void either(int x, int y) {
        x = max(2*x,-1-2*x), y = max(2*y,-1-2*y);
        radj[y].push_back(x^1); radj[x].push_back(y^1);
    }
    void implies(int x, int y) { either(~x, y);}
    void setVal(int x) { either(x, x);}
    void xor0(int x, int y) {either(x, ~y); either(~x, y);}
    void xor1(int x, int y) {either(x, y); either(~x, ~y);}
    void atMostOne(const vector<int> &v) {
        if(v.size() <= 1) return;
        int cur = ~v[0];
        for(int i = 2; i < (int)v.size(); i++) {
            int next = addVar();
            either(cur, ~v[i]);
            either(cur,next);
            either(~v[i], next);
            cur = ~next;
        }
        either(cur, ~v[1]);
    }
    vector<int> val, comp, z; int time_ = 0;
    int dfs(int u){
        int low = val[u] = ++time_, x; z.push_back(u);
        for(int v : radj[u]) if(!comp[v])
            low = min(low, val[v] ? val[v] : dfs(v));
        if(low == val[u]) do {
            x = z.back(); z.pop_back();
            comp[x] = low;
            if(ans[x/2] == -1) ans[x/2] = x&1;
        } while(x != u);
        return val[u] = low;
    }
    bool solve() {
        fill(ans, ans + N, -1);
        val.assign(2*N, 0); comp = val;
        for(int i = 0; i < 2*N; i++) if(!comp[i]) dfs(i);
        for(int i = 0; i < 2*N; i+=2) if(comp[i] == comp[i^1]) return 0;
        return 1;
    }
};

int n, p, maxi, m, l[500050], r[500050], pref[500050], suf[500050];
TwoSat<1000300> s(500100);

int main() {
    scanf("%d %d %d %d", &n, &p, &maxi, &m);

    for(int i = 1, x, y; i <= n; i++) {
        scanf("%d %d", &x, &y);
        s.either(x, y);
    }

    pref[0] = s.addVar();
    for(int i = 1; i <= maxi; i++) {
        pref[i] = s.addVar();
        s.implies(pref[i-1], pref[i]);
    }
    for(int i = 1; i <= p; i++) {
        scanf("%d %d", &l[i], &r[i]);
        s.implies(i, ~pref[l[i]-1]);
        s.implies(i, pref[r[i]]);
    }

    for(int i = 1, x, y; i <= m; i++) {
        scanf("%d %d", &x, &y);
        s.either(~x, ~y);
    }

    if(!s.solve()) puts("-1");
    else {
        if(s.ans[pref[0]] || !s.ans[pref[maxi]]) puts("-1");
        else {
            int cont = 0;
            for(int i = 1; i <= p; i++)
                if(s.ans[i])
                    cont++;

            for(int i = 1; i <= maxi; i++) {
                if(s.ans[pref[i]]) {
                    printf("%d %d\n", cont, i);
                    break;
                }
            }

            for(int i = 1; i <= p; i++)
                if(s.ans[i])
                    printf("%d ", i);
        }
    }
    return 0;
}