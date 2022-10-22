#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int main()
{
    int n;ll m;
    scanf("%d%lld",&n,&m);
    printf("%d ",max(0ll,n-m*2));
    for(int i=0;i<=n;i++)
    if(1ll*i*(i-1)/2>=m){printf("%d",n-i);return 0;}
    printf("%d",0);
    return 0;
}