#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#define N 250010
using namespace std;
vector<int>a[N];
int res[N],n,m;
int dif_count(int i)
{
    int c=0;
    for(int j=1;j<=m;j++) c+=res[j]!=a[i][j];
    return c;
}
void check()
{
    for(int i=2;i<=n;i++) if(dif_count(i)>2) return;
    puts("Yes");
    for(int i=1;i<=m;i++) printf("%d ",res[i]);
    exit(0);
}
int cnt[N];
void check_p(int x)
{
    for(int i=2;i<=n;i++)
    {
        cnt[i]=0;
        for(int j=1;j<=m;j++)
        if(j!=x) cnt[i]+=res[j]!=a[i][j];
    }
    int p=0;
    for(int i=2;i<=n;i++)
    if(cnt[i]>=2)
    {
        if(cnt[i]>2) return;
        if(p && a[p][x]!=a[i][x]) return;
        p=i;
    }
    if(p) res[x]=a[p][x];
    puts("Yes");
    for(int i=1;i<=m;i++) printf("%d ",res[i]);
    exit(0);
}
int main()
{
    scanf("%d%d",&n,&m);
    if(m<=2)
    {
        puts("Yes");
        for(int i=1;i<=m;i++) printf("1 ");
        return 0;
    }
    for(int i=0;i<=n;i++) a[i].resize(m+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    int mx=0,u=0;
    for(int i=1;i<=m;i++) res[i]=a[1][i];
    check();
    for(int i=2;i<=n;i++)
    {
        int c=dif_count(i);
        if(c>mx) mx=c,u=i;
    }
    if(mx>4){puts("No");return 0;}
    int p[5]={0,0,0,0},pt=0;
    for(int i=1;i<=m;i++)
    if(a[u][i]!=a[1][i]) p[pt++]=i;
    if(mx==4)
    {
        for(int i=0;i<4;i++)
            for(int j=i+1;j<4;j++)
            {
                for(int k=0;k<4;k++) res[p[k]]=a[1][p[k]];
                res[p[i]]=a[u][p[i]];res[p[j]]=a[u][p[j]];
                check();
            }
        puts("No");
        return 0;
    }
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<4;k++) res[p[k]]=a[1][p[k]];
        res[p[(i+2)%3]]=a[1][p[(i+2)%3]];
        res[p[(i+1)%3]]=a[u][p[(i+1)%3]];
        check_p(p[i]);
        res[p[(i+2)%3]]=a[u][p[(i+2)%3]];
        res[p[(i+1)%3]]=a[1][p[(i+1)%3]];
        check_p(p[i]);
    }
    puts("No");
    return 0;
}
/*
3 5
1 1 1 1 1
1 2 2 2 2
2 3 1 2 1

1 2 1 2 1
*/