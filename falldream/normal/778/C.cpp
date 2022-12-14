#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define MAXN 600000
using namespace std;
inline int read()
{
   int  x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}


int n,m;
int c[MAXN+5][26];
char ch;
int sum[MAXN+5];

int newnode(int x)
{
    for(int i=0;i<26;i++) c[m][i]=c[x][i];
    return m++;
}

void merge(int&x,int y,int dep)
{
    if(!x||!y){x+=y;return;}
    x=newnode(x);++sum[dep];
    for(int i=0;i<26;i++)merge(c[x][i],c[y][i],dep);
}

void dfs(int x,int dep)
{
    sum[dep-1]++;int nown=0;m=n+1;
    for(int i=0;i<26;i++,nown=0)
        for(int j=0;j<26;j++)
            if(c[c[x][j]][i])
                merge(nown,c[c[x][j]][i],dep);
    for(int i=0;i<26;i++) if(c[x][i]) dfs(c[x][i],dep+1);
}

int main()
{
    n=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();scanf("%c",&ch);
        c[u][ch-'a']=v;
    }
    dfs(1,1);int ans=1;
    for(int i=1;i<=n;i++) if(sum[i]>sum[ans]) ans=i;
    printf("%d\n%d",n-sum[ans],ans);
    return 0;
}