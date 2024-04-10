#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


using namespace std;


#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


typedef pair<int, int> pii;


#define rep(i, a, b) for(int i = a; i < (b); ++i)


int n1, n2, k;

const int mod = 998244353;

vector<int> g1[4100], g2[4100];

map< pair< pii, int >, int > c1;
map< pair< pii, int >, int > c2;
//int c1[4100][4100][40];
//int c2[4100][4100][40];

int tot1[4100][40];
int tot2[4100][40];

int seen1[4100][40];
int seen2[4100][40];

int tc1[40];
int tc2[40];

int binom[80][80];

int calc1(int v, int p, int cyc) {
    if (cyc == 0) return 1;

    pair<pii, int> ppp = {{v,p},cyc};
    auto it = c1.find(ppp);
    if (it != c1.end()) return it->second;

    int &ret = c1[ppp];
    ret = 0;

    if (seen1[v][cyc] == 0) {
        for (int x : g1[v]) if (x != p) {
            tot1[v][cyc] = (tot1[v][cyc] + calc1(x, v, cyc-1)) % mod;
        }
        seen1[v][cyc] = p;
    }    
    else if (seen1[v][cyc] != 4000 && seen1[v][cyc] != p) {
        tot1[v][cyc] = (tot1[v][cyc] + calc1(seen1[v][cyc], v, cyc-1)) % mod;
        seen1[v][cyc] = 4000;
    }

    for (int first_touch = 1; first_touch <= cyc; first_touch++) {
        int ft = tot1[v][first_touch];
        if (p != 4000 && seen1[v][first_touch] != p) ft = (ft - calc1(p, v, first_touch-1));
        if (ft < 0) ft += mod;

        //printf("%d %d %d (%d %d) -> %d %d\n", v, p, cyc, first_touch, tot1[v][first_touch], ft, calc1(v, p, cyc-first_touch));
        ret = (ret + ft * 1ll * calc1(v, p, cyc-first_touch)) % mod;
    }

    //printf("%d %d %d -> %d\n", v, p, cyc, ret);
    return ret;
}

int calc2(int v, int p, int cyc) {
    if (cyc == 0) return 1;

    pair<pii, int> ppp = {{v,p},cyc};
    auto it = c2.find(ppp);
    if (it != c2.end()) return it->second;

    int &ret = c2[ppp];
    ret = 0;

    if (seen2[v][cyc] == 0) {
        for (int x : g2[v]) if (x != p) {
            tot2[v][cyc] = (tot2[v][cyc] + calc2(x, v, cyc-1)) % mod;
        }
        seen2[v][cyc] = p;
    }    
    else if (seen2[v][cyc] != 4000 && seen2[v][cyc] != p) {
        tot2[v][cyc] = (tot2[v][cyc] + calc2(seen2[v][cyc], v, cyc-1)) % mod;
        seen2[v][cyc] = 4000;
    }

    for (int first_touch = 1; first_touch <= cyc; first_touch++) {
        int ft = tot2[v][first_touch];
        if (p != 4000 && seen2[v][first_touch] != p) ft = (ft - calc2(p, v, first_touch-1));
        if (ft < 0) ft += mod;

        ret = (ret + ft * 1ll * calc2(v, p, cyc-first_touch)) % mod;
    }
    return ret;
}

void solve()
{
    for (int i = 0; i <= 75; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) binom[i][j] = 1;
            else binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % mod;
        }
    }

    re(n1,n2,k);
    if (k % 2 != 0) {
        printf("0");
        return;
    }
    k /= 2;

    rep(i,0,n1-1) {
        int a, b; re(a,b); a--; b--;
        g1[a].push_back(b);
        g1[b].push_back(a);
    }
    rep(i,0,n2-1) {
        int a,b; re(a,b); a--; b--;
        g2[a].push_back(b);
        g2[b].push_back(a);
    }

    for (int c = 0; c <= k; c++) {
        for (int i = 0; i < n1; i++) tc1[c] = (tc1[c] + calc1(i, 4000, c)) % mod;
        for (int i = 0; i < n2; i++) tc2[c] = (tc2[c] + calc2(i, 4000, c)) % mod;
    }

    int ans = 0;
    for (int l = 0; l <= k; l++) {
        int r = k - l;
        long long t = (binom[2*k][2*l] * 1ll * tc1[l]) % mod;
        t = (t * 1ll * tc2[r]) % mod;
        ans = (ans + t) % mod;
    }

    ps(ans);
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}