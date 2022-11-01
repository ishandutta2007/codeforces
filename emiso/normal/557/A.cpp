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

int mn[4],mx[4];

int main()
{
    int i,n;
    scanf("%d %d %d %d %d %d",&n,&mn[1],&mx[1],&mn[2],&mx[2],&mn[3],&mx[3]);
    int first = min(mx[1],n-mn[2]-mn[3]);
    int second = min(mx[2],n-mn[3]-first);
    int third = n-first-second;
    printf("%d %d %d\n",first,second,third);
    return 0;
}