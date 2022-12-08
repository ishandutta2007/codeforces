#include <iostream>
#include <cstdio>

#include <cmath>

using namespace std;

typedef double lf;
#define tlf(x) static_cast<lf>(x)

int D;

void solve() {
    scanf("%d", &D);
    
    int disc = D*D - 4*D;
    
    if(disc < 0) {printf("N\n");return;}
    
    lf d2 = sqrt(tlf(disc));
    
    printf("Y %.10g %.10g\n", (tlf(D) + d2)/tlf(2), (tlf(D) - d2)/tlf(2));
    
}

int T;

int main() {
    scanf("%d", &T);
    
    while(T--) solve();
    
    return 0;
}