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


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


const int mod = 1000000007;
int fib[110000];
char s[110000];

void solve()
{
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= 100000; i++) fib[i] = (fib[i-1] + fib[i-2]) % mod;

    int ans = 1;
    scanf("%s", s);
    int l = strlen(s);

    int u_cnt = 0;
    int n_cnt = 0;
    REP(i,l) {
        if (s[i] == 'w' || s[i] == 'm') {
            ps("0");
            return;
        }

        if (s[i] != 'u' && s[i] != 'n') {
            ans = (ans * 1ll * fib[u_cnt] * fib[n_cnt]) % mod;
            u_cnt = n_cnt = 0;
        }
        else if (s[i] == 'u') {
            u_cnt++;
            ans = (ans * 1ll * fib[n_cnt]) % mod;
            n_cnt = 0;
        }
        else if (s[i] == 'n') {
            n_cnt++;
            ans = (ans * 1ll * fib[u_cnt]) % mod;
            u_cnt = 0;
        }
    }

    ans = (ans * 1ll * fib[u_cnt] * fib[n_cnt]) % mod;
    ps(ans);
}


int main() {


    solve();
}


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}