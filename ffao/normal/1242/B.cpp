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


#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


int n,m;
vector<int> par;

int find(int a) {
    if (par[a]==a) return a;
    return par[a]=find(par[a]);
}

void link(int a, int b) {
    //printf("link %d %d\n",a,b);
    int x = find(a), y = find(b);
    par[y]=x;
}

void solve()
{
    re(n,m);

    vector<set<int>> g(n);
    par.resize(n); rep(i,n) par[i] = i;

    rep(i,n) g[i].insert(n);
    rep(i,m) {
        int a, b; re(a,b); a--; b--;
        g[a].insert(b);
        g[b].insert(a);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) if (par[i] == i) {
        queue<int> visit;
        
        int la = 0;
        for (int x : g[i]) {
            for (int y = la; y < x; y++) if (y != i) {
                link(i,y);
                visit.push(y);
            }
            la = x+1;
        }

        while (!visit.empty()) {
            int c = visit.front();
            visit.pop();

            vector<int> seen;
            for (int x : g[i]) {
                if (!g[c].count(x)) {
                    seen.push_back(x);
                }
            }

            for (int x : seen) {
                g[i].erase(x);
                link(i,x);
                visit.push(x);
            }
        }
        
        ans++;
    }    

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