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


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


using namespace std;


int gr[110000];
int grx[110000];
int ans[110000];

void solve()
{
    int n;
    re(n);

    for (int tn = 2; tn <= n; tn++) {
        set<int> goes;
        for (int piles = 2; piles*1ll*(piles+1)/2 <= tn; piles++) {
            long long inc = piles*1ll*(piles+1)/2;
            long long on = tn - inc;

            if (on >= 0 && (on % piles == 0)) {
                long long f = 1 + on / piles;
                int g = grx[f+piles-1] ^ grx[f-1];
                goes.insert(g);
                if (ans[tn] == 0 && g == 0) ans[tn] = piles;
            } 
        }

        for (int i = 0; ; i++) if (!goes.count(i)) {
            gr[tn] = i;
            break;
        }
        grx[tn] = gr[tn] ^ grx[tn-1];
    }

    ps(ans[n] == 0 ? -1 : ans[n]);
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}