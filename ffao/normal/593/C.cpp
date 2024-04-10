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


int n;
int x[50], y[50], k;
int coefs[50];

void go(int* x) {
    for (int i = 0; i < n; i++) {
        for (int p = 0; p < i; p++) {
            x[i] -= 2*((i+1)-p)*coefs[p];
        }

        coefs[i] = x[i]/2;
    }

    for (int i = 0; i < n; i++) {
        if (i!=n-1) printf("(");
        if (coefs[i] < 0) {
            printf("(%d*((%d-t)-abs((t-%d))))", -coefs[i], i, i);
        }
        else {
            printf("(%d*(abs((t-%d))-(%d-t)))", coefs[i], i, i);
        }
        if (i!=n-1) printf("+");
    }

    for (int i = 0; i < n-1; i++) printf(")");
    printf("\n");
}

void solve()
{
    re(n);
    for (int i = 0; i < n; i++) {
        re(x[i], y[i], k);
        x[i] -= x[i]%2;
        y[i] -= y[i]%2;
    }
    
    go(x);
    go(y);
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}