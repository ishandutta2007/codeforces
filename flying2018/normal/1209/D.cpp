#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int f[N];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int main()
{
    int n,m,tt=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(find(x)==find(y)) ++tt;
        else f[find(x)]=find(y);
    }
    printf("%d\n",tt);
    return 0;
}