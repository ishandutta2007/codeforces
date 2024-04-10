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

#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


using namespace std;


#define all(v) (v).begin(), (v).end()
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


int n,m,q;

int par[410000];

int f(int *p, int a) {
    if (p[a]==a) return a;
    return p[a]=f(p, p[a]);
}

void l(int *p, int a, int b) {
    int x = f(p,a), y = f(p,b);
    p[x]=y;
}

void solve()
{
    re(n,m,q);

    REP(i,n+m) par[i]=i;

    REP(i,q) {
        int a,b;
        re(a,b); a--; b--;
        l(par, a, n+b);
    }    

    int ans = 0;
    for (int i = 0; i < n+m; i++) ans += (f(par,i)==i);
    ps(ans-1);
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