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

int main()
{
    int a,b,c,x,y,z, need = 0,possible = 0;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&x,&y,&z);
    if(a < x) need += x-a;
    else possible += (a-x)/2;
    if(b < y) need += y-b;
    else possible += (b-y)/2;
    if(c < z) need += z-c;
    else possible += (c-z)/2;
    if(possible >= need )printf("Yes\n");
    else printf("No\n");
    return 0;
}