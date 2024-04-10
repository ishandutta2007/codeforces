#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int u=1,v=n;
    printf("%d ",u),u++;
    while(k --> 1)
    {
        if(u+v>n+1) printf("%d ",v),v--;
        else printf("%d ",u),u++;
    }
    if(u+v<=n+1) for(;v>=u;v--) printf("%d ",v);
    else for(;u<=v;u++) printf("%d ",u);
    return 0;
}