#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int ans=0;
        for(int i=30;i>=0;i--)
        if(((n>>i)&1)^((m>>i)&1)) ans+=1<<i;
        printf("%d\n",ans);
    }
    return 0;
}