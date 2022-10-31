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

typedef unsigned long long ull;


int main()
{
    ull a,b,ans=0,aux;
    scanf("%I64u %I64u",&a,&b);
    for(aux = (1ull<<62)-1; aux > 0; aux &= aux>>1) {
        for(int i = 0; 1ull<<(i+1) <= aux; i++) {
            if((aux-(1ull<<i)) >= a && (aux-(1ull<<i)) <= b) ans++;
        }
    }
    printf("%I64u\n",ans);
    return 0;
}