#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
#define M 26
char str[N];
int f[N][M+2],pre[N][M],suf[N][M],g[N],n;
int ans[M+2];
int dfs(int l,int r,int c,int fl)
{
    if(l>r) return 0;
    if(ans[c]!=-1) return ans[c];
    int u=0;
    for(int i=0;i<M;i++)
    {
        int L=suf[l][i],R=pre[r][i];
        if(R<l) continue;
        int s=g[L]^g[R];
        if(!fl) s^=f[L-1][c]^dfs(R+1,r,i,0);
        else s^=dfs(l,L-1,i,1)^f[r][i];
        u|=1<<s;
    }
    return ans[c]=__builtin_ctz(~u);
}
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<M;j++) pre[i][j]=pre[i-1][j];
        pre[i][str[i]-'a']=i;
    }
    for(int i=0;i<M;i++) suf[n+1][i]=n+1;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<M;j++) suf[i][j]=suf[i+1][j];
        suf[i][str[i]-'a']=i;
    }
    for(int i=1;i<=n;i++)
    {
        int c=str[i]-'a';
		g[i]=f[i-1][c]^g[pre[i-1][c]];
		memset(ans,-1,sizeof(ans));
		for(int j=0;j<M;j++) f[i][j]=dfs(pre[i][j]+1,i,j,0);
	}
    int m;
    scanf("%d",&m);
    while(m --> 0)
    {
        int l,r;
        scanf("%d%d",&l,&r);
		memset(ans,-1,sizeof(ans));
		if(dfs(l,r,26,1)) puts("Alice");
        else puts("Bob");
    }
}