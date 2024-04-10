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


void re(char* c);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


int n;
char s[1100000];

void solve()
{
    int c = 0;
    int la = -1;

    re(n); re(s);
    int ans = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            c++;
            if (c == 0) ans += (i-la);
        }
        if (s[i] == ')') {
            c--;
        }
        if (c >= 0) la = i; 
    }

    if (c != 0) ps(-1);
    else ps(ans);
}


int main() {


    solve();
}


 // and triples


void re(int& x) { scanf("%d", &x); }


void re(char* c) { scanf("%s", c); }


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}


#include <array>