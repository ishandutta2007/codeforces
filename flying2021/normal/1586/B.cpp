#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
bool ban[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) ban[i]=false;
        for(int i=1;i<=m;i++){int u,v,w;scanf("%d%d%d",&u,&v,&w);ban[v]=true;}
        for(int i=1;i<=n;i++) if(!ban[i])
        {
            for(int j=1;j<=n;j++)
            if(i!=j) printf("%d %d\n",i,j);
            break;
        }
    }
    return 0;
}