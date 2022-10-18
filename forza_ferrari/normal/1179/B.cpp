#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=(n>>1);++i)
        for(register int j=1;j<=m;++j)
            printf("%d %d\n%d %d\n",i,j,n-i+1,m-j+1);
    if(n&1)
    {
        for(register int i=1;i<=(m>>1);++i)
            printf("%d %d\n%d %d\n",(n+1)>>1,i,(n+1)>>1,m-i+1);
        if(m&1)
            printf("%d %d\n",(n+1)>>1,(m+1)>>1);
    }
    return 0;
}