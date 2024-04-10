#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

void re(int& x);

void re(char& x);

template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(int x);

void pr(char x);
void pr(const char *x);

template<class T> void pr(const std::vector<T> x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

int cnt[4194304];
int st[510000];
int ft[510000];
int sz[510000];
int ma[510000];
int ver[510000];
int d[510000];
vector< int > g[510000];
vector<int> as;
int cc;

void getsz(int v){
    sz[v] = 1;
    ver[cc] = v;
    st[v] = cc++;
    for(auto u : g[v]) {
        getsz(u);
        sz[v] += sz[u];
    }

    ft[v] = cc;
}

void dfs(int v, bool keep){
    int ans = 0;
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != bigChild) {
            dfs(u, 0);
            ans = max(ans, as[u]);
        }
    if(bigChild != -1) {
        dfs(bigChild, 1);
        ans = max(ans, as[bigChild]);
    }
    for(auto u : g[v]) {
	    if(u != bigChild) {
            for(int p = st[u]; p < ft[u]; p++) {
                // dbg(v+1, ver[p]+1, ma[ver[p]], cnt[1]);
                for (int i = 0; i < 22; i++) if (cnt[ ma[ver[p]] ^ (1<<i) ] != -1)
                    ans = max(ans, cnt[ ma[ver[p]] ^ (1<<i) ] + d[ver[p]] - 2 * d[v]);

                if (cnt[ma[ver[p]]] != -1)
                    ans = max(ans, cnt[ma[ver[p]]] + d[ver[p]] - 2*d[v]);
            }

	        for(int p = st[u]; p < ft[u]; p++)
		        cnt[ ma[ ver[p] ] ] = max(cnt[ ma[ ver[p] ] ], d[ver[p]]);
        }
    }
    for (int i = 0; i < 22; i++) if (cnt[ ma[v] ^ (1<<i) ] != -1)
        ans = max(ans, cnt[ ma[v] ^ (1<<i) ] + d[v] - 2 * d[v]);
    if (cnt[ma[v]] != -1)
        ans = max(ans, cnt[ma[v]] + d[v] - 2 * d[v]);

    cnt[ ma[v] ] = max(cnt[ma[v]], d[v]);
    // dbg(v+1, ma[v], d[v]);

    as[v] = ans;
    if(keep == 0)
        for(int p = st[v]; p < ft[v]; p++)
	    cnt[ ma[ ver[p] ] ]=-1;
}

void solve()
{
    int n;
    re(n); as.resize(n);

    memset(cnt,-1,sizeof(cnt));

    for (int i = 1; i < n; i++) {
        int p; char c;
        re(p, c); p--;
        c -= 'a';

        ma[i] = ma[p] ^ (1<<c);
        d[i] = d[p]+1;
        g[p].push_back(i);
    }

    getsz(0);
    dfs(0, 0);
    ps(as);
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

void re(char& x) { scanf(" %c", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(int x) { printf("%d", x); }

void pr(char x) { printf("%c", x); }
void pr(const char *x) { printf("%s", x); }

template<class T> void pr(std::vector<T> v) {
    int f=0;
    for (int x : v) {
        if (f++) pr(' ');
        pr(x);
    }
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}