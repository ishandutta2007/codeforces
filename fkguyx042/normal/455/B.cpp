#include<stdio.h>
#include<cstring>
#define MAXN 210000
using namespace std;
int go[MAXN][27];int tot=1;
int n,k;
bool win[MAXN]={false};
bool t2[MAXN];
int q[MAXN];
char str[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
            scanf("%s",str+1);int len=strlen(str+1);int now=1;
            for(int j=1;j<=len;j++)
            {
                    if(!go[now][str[j]-'a'+1])go[now][str[j]-'a'+1]=++tot;
                    now=go[now][str[j]-'a'+1];
                    }
                                 }
    q[q[0]=1]=1;
    for(int i=1;i<=q[0];i++)
    {
            int x=q[i];
            for(int j=1;j<=26;j++)if(go[x][j])q[++q[0]]=go[x][j];
            }
    for(int i=q[0];i>=1;i--)
    {
            bool ch=1;
            int x=q[i];win[x]=0;t2[x]=0;
            for(int j=1;j<=26;j++)
            {
                    if(go[x][j])ch=0;
                    if(go[x][j]&&(!win[go[x][j]]))win[x]=1;
                    if(go[x][j]&&(!t2[go[x][j]]))t2[x]=1;
                    }
            if(ch)t2[x]=1;
            }
    bool u=win[1];
    if(!u){printf("Second");return 0;}
    else
    {
        if(t2[1])printf("First\n");
        else 
        {
             if(k%2==0)printf("Second\n");
             else printf("First\n");
             }
             }
    return 0;
}