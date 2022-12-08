#include <iostream>
#include <cstdio>

#include <utility>
#include <queue>
#include <functional>
#include <cassert>

using namespace std;

#define mp make_pair
#define pf first
#define ps second
typedef pair<int, int> pii;

const int MAXN = 10 + 5;
const int INF = 1e9 + 1e6;


int N;

int g[MAXN][MAXN];

struct state {
    int x, y, p, l, d, s;
    state(int a = -1, int b = -1, int c = -1, int h = -1, int e = -1, int f = -1) {x = a, y = b, l = c, p = h, d = e, s = f;}
    bool operator < (const state& o) const{if(d != o.d) return d < o.d; else return s < o.s;}
    bool operator > (const state& o) const {if(d != o.d) return d > o.d; else return s > o.s;}
};

int d[MAXN][MAXN][MAXN * MAXN][3];
int s[MAXN][MAXN][MAXN * MAXN][3];
bool v[MAXN][MAXN][MAXN * MAXN][3];

typedef priority_queue<state, vector<state>, greater<state> > pqs;

bool& gv(const state& st) {return v[st.x][st.y][st.l][st.p];}
int& gs(const state& st) {return s[st.x][st.y][st.l][st.p];}
int& gd(const state& st) {return d[st.x][st.y][st.l][st.p];}


bool in_bound(int x, int y) {return x >= 0 and x < N and y >= 0 and y < N;}
inline bool in_bound(const state& st) {return in_bound(st.x, st.y);}

bool addS(pqs& pq, const state& st) {
    if(!in_bound(st) or gv(st)) return false;
    if(st.d < gd(st) or (gd(st) == st.d and st.s < gs(st))) {
        gd(st) = st.d;
        gs(st) = st.s;
        pq.push(st);
        return true;
    }
    return false;
}

void addss(pqs& pq, const state& st) {
    state t = st;
    t.d++;
    t.s++;
    for(int i = 0;i < 3;i++) if(st.p != i) if(!v[st.x][st.y][st.l][i]) {
        t.p = i;
        addS(pq, t);
    }
}

const int dxk[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dyk[8] = {1, 2, 2, 1, -1, -2, -2, -1};
void addK(pqs& pq, const state& st) {
    assert(st.p == 0);
    for(int i = 0;i < 8;i++) {
        state t = st;
        t.d++;
        t.x += dxk[i];
        t.y += dyk[i];
        if(!in_bound(t) or gv(t)) continue;
        addS(pq, t);
    }
}
const int dxb[4] = {1, 1, -1, -1};
const int dyb[4] = {1, -1, 1, -1};
void addB(pqs& pq, const state& st) {
    assert(st.p == 1);
    for(int i = 0;i < 4;i++) {
        state t = st;
        t.d++;
        t.x += dxb[i];
        t.y += dyb[i];
        while(in_bound(t)) {
            addS(pq, t);
            t.x += dxb[i];
            t.y += dyb[i];
        }
    }
}
const int dxr[4] = {1, -1, 0, 0};
const int dyr[4] = {0, 0, 1, -1};
void addR(pqs& pq, const state& st) {
    assert(st.p == 2);
    for(int i = 0;i < 4;i++) {
        state t = st;
        t.d++;
        t.x += dxr[i];
        t.y += dyr[i];
        while(in_bound(t)) {
            addS(pq, t);
            t.x += dxr[i];
            t.y += dyr[i];
        }
    }
}

int main() {
    scanf("%d", &N);
    
    pii st, en;
    
    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) {
        scanf("%d", &g[i][j]);
        if(g[i][j] == 1) st = mp(i, j);
        if(g[i][j] == N*N) en = mp(i, j);
    }
    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++) for(int k = 0;k <= N*N;k++) for(int l = 0;l < 3;l++) d[i][j][k][l] = s[i][j][k][l] = INF, v[i][j][k][l] = false;
    for(int i = 0;i < 3;i++) d[st.pf][st.ps][1][i] = 0, s[st.pf][st.ps][1][i] = 0;
    
    pqs pq;
    for(int i = 0;i < 3;i++) pq.push(state(st.pf, st.ps, 1, i, 0, 0));
    
    while(!pq.empty()) {
        state s = pq.top();
        pq.pop();
        if(s.l > N*N or gv(s)) continue;
        gv(s) = true;
        if(g[s.x][s.y] == s.l) s.l++;
        addss(pq, s);
        if(s.p == 0) addK(pq, s);
        if(s.p == 1) addB(pq, s);
        if(s.p == 2) addR(pq, s);
    }
    
    pii ans = mp(INF, INF);
    for(int i = 0;i < 3;i++) if(d[en.pf][en.ps][N*N][i] < ans.pf or (d[en.pf][en.ps][N*N][i] == ans.pf and s[en.pf][en.ps][N*N][i] < ans.ps)) ans = mp(d[en.pf][en.ps][N*N][i], s[en.pf][en.ps][N*N][i]);
    printf("%d %d\n", ans.pf, ans.ps);
    
    return 0;
}