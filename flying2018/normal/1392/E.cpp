#include<iostream>
#include<cstdio>
#include<cstring>
#define N 60
using namespace std;
#define ll long long
ll num[N][N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        if((i&1)==0) for(int j=0;j<n;j++) num[n-i][n-j]=1ll<<(i+j);
        else for(int j=0;j<n;j++) num[n-i][n-j]=0;
    }
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=n;j++) printf("%lld ",num[i][j]);
    fflush(stdout);
    int q;
    scanf("%d",&q);
    while(q --> 0)
    {
        ll k;
        scanf("%lld",&k);
        int x=1,y=1;
        printf("%d %d\n",x,y);
        k-=num[x][y];
        for(int i=1;i<2*n-1;i++)
        {
            if((num[x][y+1] && k>=num[x][y+1]) || (num[x+1][y] && k<num[x+1][y])) y=y+1;
            else x=x+1;
            k-=num[x][y];
            printf("%d %d\n",x,y);
        }
        fflush(stdout);
    }
    return 0;
}