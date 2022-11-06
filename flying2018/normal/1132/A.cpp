#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a!=d) puts("0");
    else if(a==0 && c!=0) puts("0");
    else puts("1");
    return 0;
}