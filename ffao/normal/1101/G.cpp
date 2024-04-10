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


template<class T> void re(std::vector<T>& a);

void pr(int x);


void pr(std::string x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


int n;
vector<int> a;

vector<int> ans;

void solve()
{
    re(n);
    a.resize(n); re(a);

    for (int i = 1; i < n; i++) a[i] = a[i] ^ a[i-1];
    if (a[n-1] == 0) {
        printf("-1\n");
        return;
    }

    ans.push_back(a[n-1]);
    for (int i = 0; i < n; i++) {
        for (int x : ans) if ((a[i] ^ x) < a[i]) a[i] ^= x;
        if (a[i]) ans.push_back(a[i]);
    }

    ps((int)ans.size());
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }


void pr(int x) { printf("%d", x); }


void pr(std::string x) { printf("%s", x.c_str()); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}