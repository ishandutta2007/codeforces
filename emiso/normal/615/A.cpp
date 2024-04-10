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

int on[101];

int main()
{
    int n,m,a,b,flag=1;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%d",&a);
        for(int j=0;j<a;j++) {
            scanf("%d",&b);
            on[b]++;
        }
    }
    for(int i=1;i<=m;i++) {
        if(on[i] == 0) flag = 0;
    }
    printf("%s\n",flag?"YES":"NO");
    return 0;
}