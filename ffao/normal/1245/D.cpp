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


void re(int& x);
void re(long long& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);
void pr(long long x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


pair<int, int> loc[2100];
int dist[2100];
int fr[2100];
int marked[2100];

long long k[2100];
vector<pair<int,int>> edge;

int n;
void solve()
{
    memset(fr,-1,sizeof(fr));
    re(n);
    REP(i,n) re(loc[i].first, loc[i].second);
    REP(i,n) re(dist[i]);
    REP(i,n) re(k[i]);

    long long ans = 0;

    for (int it = 0; it < n; it++) {
        int bst = -1, bstval = 2000000001;
        for (int i = 0; i < n; i++) if(!marked[i]) {
            if (dist[i] < bstval) {
                bst = i;
                bstval = dist[i];
            }
        }

        ans += bstval;
        if (fr[bst] != -1) edge.push_back( {bst, fr[bst]} );
        marked[bst] = 1;

        for (int j = 0; j < n; j++) if (!marked[j]) {
            long long dx = abs(loc[bst].first - loc[j].first);
            long long dy = abs(loc[bst].second - loc[j].second);
            long long d = (k[bst]+k[j]) * 1ll * (dx+dy);

            if (d < dist[j]) {
                fr[j] = bst;
                dist[j] = d;
            }
        }
    }

    ps(ans);
    ps(n - (int)edge.size());
    
    REP(i, n) if (fr[i]==-1) {
        pr(i+1); pr(" ");
    }
    ps();
    
    ps((int)edge.size());
    for (auto t : edge) {
        ps(t.first+1, t.second+1);
    }
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }
void re(long long& x) { scanf("%lld", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


void pr(int x) { printf("%d", x); }
void pr(long long x) { printf("%lld", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}