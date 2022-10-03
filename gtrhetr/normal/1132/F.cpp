#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 505
int f[MAX][MAX],n;char s[MAX];
int main()
{
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;++i)f[i][i]=1;
    memset(f,63,sizeof(f));
    for(int i=1;i<=n;++i)f[i][i-1]=0;
    for(int r=1;r<=n;++r)
        for(int l=1;l<=r;++l)
        {
            f[l][r]=f[l][r-1]+1;
            for(int k=r-1;k;--k)
                if(s[k]==s[r])
                    f[l][r]=min(f[l][r],f[l][k-1]+f[k][r-1]);
        }
    printf("%d\n",f[1][n]);
    return 0;
}