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

long long expo(long long b, long long e) {
    long long res = 1;
    while(e--) {
        res *= b;
    }
    return res;
}

int main()
{
    long long n,bx,ex,x,resx = 0,y,resy = 0,by;
    scanf("%I64d %I64d",&n,&bx);
    ex = expo(bx,n-1);
    for(int i=0;i<n;i++) {
        scanf("%I64d",&x);
        resx += (x*ex);
        ex /= bx;
    }
    scanf("%I64d %I64d",&n,&by);
    ex = expo(by,n-1);
    for(int i=0;i<n;i++) {
        scanf("%I64d",&y);
        resy += (y*ex);
        ex /= by;
    }
    if(resx == resy) printf("=\n");
    else printf("%c\n",(resx>resy)?'>':'<');
    return 0;
}