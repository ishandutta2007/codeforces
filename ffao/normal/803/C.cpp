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


void re(long long& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(long long x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


long long n,k;

vector<long long> ans;

bool test(long long n, long long k) {
    if (k >= 1000000 || k * (k+1)/2 > n) return false;

    for (long long i = 1; i < k; i++) {
        ans.push_back(i);
    }
    ans.push_back(n - k*(k-1)/2);
    return true;
}

void solve()
{
    re(n,k);

    vector<long long> divs;
    for (long long p = 1; p*p <= n; p++) if (n%p == 0) {
        divs.push_back(p);
        divs.push_back(n/p);
    }

    sort(divs.begin(),divs.end(), greater<long long>());
    for (long long d : divs) {
        if (test(n/d, k)) {
            for (long long t : ans) {
                pr(t*d); pr(" ");
            }
            return;
        }
    }
    ps("-1");
}


int main() {


    solve();
}


void re(long long& x) { scanf("%lld", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


void pr(long long x) { printf("%lld", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}