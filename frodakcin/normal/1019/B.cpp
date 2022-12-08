#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 101000;

int N;

bool getv(int n) {
    int a, b;
    printf("? %d\n", 1 + n);
    fflush(stdout);
    scanf("%d", &a);
    printf("? %d\n", 1 + n + (N/2) );
    fflush(stdout);
    scanf("%d", &b);
    
    if(a == b) { 
        printf("! %d\n", 1 + n);
        exit(0);
    }
    return a > b;
}

int main() {
    scanf("%d", &N);
    if(N%4 > 0)
    {
        printf("! -1\n");
        return 0;
    }
    
    bool bvt = getv(0);
    
    int low = 0, high = N/2;
    while(high > low + 1)
    {
        int mid = low + (high - low)/2;
        if(getv(mid) == bvt) low = mid;
        else high = mid;
    }
    getv(high);
    printf("! -1\n");
    
    return 0;
}