#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define C 26
using namespace std;
int pre[N],suf[N];
char s[N],t[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s%s",s+1,t+1);
    if(n==m){puts("1");return 0;}
    pre[0]=0;
    for(int i=1;i<=m;i++)
    {
        pre[i]=pre[i-1]+1;
        while(pre[i]<=n && s[pre[i]]!=t[i]) pre[i]++;
    }
    suf[m+1]=n+1;
    for(int i=m;i>=1;i--)
    {
        suf[i]=suf[i+1]-1;
        while(suf[i] && s[suf[i]]!=t[i]) suf[i]--;
    }
    // for(int i=1;i<=m;i++) printf("%d ",pre[i]);puts("");
    // for(int i=1;i<=m;i++) printf("%d ",suf[i]);puts("");
    int ans=0;
    for(int i=1;i<m;i++) ans=max(ans,suf[i+1]-pre[i]);
    printf("%d\n",ans);
    return 0;
}