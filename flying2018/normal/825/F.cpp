#include<iostream>
#include<cstdio>
#include<cstring>
#define N 8010
using namespace std;
int nxt[N],f[N],g[N][N];
int _10[N];
char s[N];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) _10[i]=_10[i/10]+1;
    for(int i=1;i<=n;i++)
    {
        memset(nxt,-1,sizeof(nxt));
        g[i][i]=2,nxt[i]=i-1;
        int p=i-1;
        for(int j=i+1;j<=n;j++)
        {
            while(p>=i && s[p+1]!=s[j]) p=nxt[p];
            if(s[p+1]==s[j]) ++p;nxt[j]=p;
            int l=j-i+1,r=l-(nxt[j]-i+1);
            if(l%r==0) g[i][j]=r+_10[l/r];
            else g[i][j]=l+1;
        }
    }
    f[0]=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=i+1;
        for(int j=0;j<i;j++)
        f[i]=min(f[i],f[j]+g[j+1][i]);
    }
    printf("%d\n",f[n]);
    return 0;
}