#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int n,i;
double c[1100000],q;

void binsearch(double b) {
    double t = b, u = b/2, l = 0;
    int N =  2*n,j;
    while(1) {
        int flag = 0;
        if(2*u > c[N-1]);
        else {
            j = lower_bound(c,c+N,2*u)-c;
            if(N-j >= n) flag = 1;
        }
        if(flag == 1) {
            q = u*3*n;
            if(u == b || u==l) break;
            else {
                l = u;
                u = (l+t)/2;
            }
        }
        else {
        t = u;
        u = (l+t)/2;
        }
    }
}

int main()
{
    double w,best;
    scanf("%d",&n);
    scanf("%lf",&w);
    for(i=0;i<2*n;i++) {
        scanf("%lf",&c[i]);
    }
    sort(c,c+2*n);
    best = min(w/(3*n),c[0]);

    binsearch(best);
    printf("%f\n",q);
    return 0;
}