#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>


using namespace std;


#include <cmath>

void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


#ifndef ONLINE_JUDGE
#define dbg(x...) pr("[",#x,"] = ["), pc(x);
#else

#endif


#include <array>


#define rep(i, a, b) for(int i = a; i < (b); ++i)


int n,m,k;
int has[1100000];
int p2[1100000];
const int mod = 1000000007;

void solve()
{
    re(n,m,k);

    int lt = n-k-1, rt = -1;

    p2[0] = 1; rep(i,1,1000011) p2[i] = (p2[i-1]+p2[i-1])%mod;

    rep(i,0,m) {
        int u,v; re(u,v);
        if (v == u+k+1) {
            has[u] = 1;
            lt = min(lt,u);
            rt = max(rt,u);
        }
        if (v != u+k+1 && v != u+1) { ps(0); return; }
    }

    for (int i = 1; i <= n; i++) has[i] += has[i-1];
    int ans = has[n] ? 0 : 1;
    
    for (int left = 1; left <= lt; left++) {
        if (left + k + 1 <= rt) continue;
        int in = has[left+k]-has[left-1];
        int hm = min(n-k-1,left+k) - (left-1);
        if (has[left] - has[left-1] == 0) hm--;
        //dbg(left,hm,in,hm-in);
        ans = (ans + (p2[hm-in])) % mod;
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