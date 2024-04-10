#include<iostream>
#include<cstdio>
#include<cstring>
#define N 80
using namespace std;
bool a[N][N];
int b[N][N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&b[i][j]);
    int c=0;
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
        if(b[i][j] && b[i+1][j] && b[i][j+1] && b[i+1][j+1]) a[i][j]=true,c++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(b[i][j] && !(a[i][j] || a[i][j-1] || a[i-1][j] || a[i-1][j-1])){puts("-1");return 0;}
    printf("%d\n",c);
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
        if(a[i][j]) printf("%d %d\n",i,j);
    return 0;
}