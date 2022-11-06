#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000010
#define mod 998244353
using namespace std;
int main()
{
    int n,r=1;
    scanf("%d",&n);
    while(r<n-1) r=r*2+1+(r&1);
    if(r==n || r==n-1) puts("1");
    else puts("0");
    return 0;
}