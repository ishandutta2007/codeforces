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


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


typedef vector<int> vi;


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


int n;
vi a;
set<int> have;
set<int> fix;

void solve()
{
    re(n);
    a.resize(n);
    REP(i,n) re(a[i]);
    //REP(i,n) have.insert(a[i]);
    int ans = n;
    int at = 0;

    for (int i = n-1; i >= 0; i--) {
        if (!have.count(a[i])) have.insert(a[i]);
        else {
            at = i+1;
            break;
        }
    }
    
    ans = min(ans, n - (int)fix.size() - (int)have.size());
    for (int i = 0; i < n; i++) {
        while (have.count(a[i]) && at < n) {
            have.erase(a[at++]);
        }

        if (fix.count(a[i])) break;
        
        fix.insert(a[i]);
        ans = min(ans, n - (int)fix.size() - (int)have.size());
    }

    ps(ans);
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