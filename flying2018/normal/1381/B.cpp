#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 4010
using namespace std;
int num[N];
int v[N],tot;
int f[N][N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++) scanf("%d",&num[i]);
        tot=0;
        for(int i=1;i<=2*n;)
        {
            int j=i+1;
            for(;j<=2*n;j++)
            if(num[j]>num[i]) break;
            v[++tot]=j-i;
            i=j;
        }
        memset(f[0],0,sizeof(f[0]));
        f[0][0]=1;
        for(int i=1;i<=tot;i++)
            for(int j=0;j<=n;j++)
            {
                f[i][j]=f[i-1][j];
                if(j>=v[i])f[i][j]|=f[i-1][j-v[i]];
            }
        puts(f[tot][n]?"YES":"NO");
    }
    return 0;
}