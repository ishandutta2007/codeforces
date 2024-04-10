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


void re(long long& x);


void pr(int x);
void pr(long long x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


using namespace std;


long long n;
void solve()
{
    re(n);

    vector<long long> d;
    for (long long i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            while (n % i == 0) n /= i;
        }
    }

    if (n != 1) d.push_back(n);

    if (d.size() == 1) {
        ps(d[0]);
        return;
    }
    else ps(1); 
}


int main() {


    solve();
}


void re(long long& x) { scanf("%lld", &x); }


void pr(int x) { printf("%d", x); }
void pr(long long x) { printf("%lld", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}