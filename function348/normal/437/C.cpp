#include<cstdio>
#include<iostream>
const int N=2020;
int a[N],v[N];
int map[N][N];
int n,m,res;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        map[x][y]=map[y][x]=1;
    }
    res=0;
    for (int ii=1;ii<=n;ii++)
    {
        int k=0;
        for (int i=1;i<=n;i++)
        if (!v[i]&&a[i]>a[k]) k=i;
        v[k]=1;
        for (int i=1;i<=n;i++)
        if (map[i][k]&&!v[i]) res+=a[i];
    }
    printf("%d\n",res);
    return 0;
}