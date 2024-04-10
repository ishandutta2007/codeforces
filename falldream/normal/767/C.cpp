#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
inline int read()
{
   int  x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}

int n,rt,cnt=0;
struct edge{
    int to,next;
}e[4000005];
int head[2000005];
int tot=0,has=0;
int s[2000005];

int ans1=-1,ans2=-1;

inline void ins(int f,int t)
{
    e[++cnt].next=head[f];
    head[f]=cnt;
    e[cnt].to=t;
}

inline void insw(int f,int t){ins(f,t);ins(t,f);}

void findans(int x)
{
    if(has>2) return;
    else has++;
    if(ans1==-1) ans1=x;
    else if(ans2==-1) ans2=x;
}

void dfs(int x,int fa)
{
    for(int i=head[x];i>0;i=e[i].next)
    {
        int v=e[i].to;
        if(v!=fa)
        {
            dfs(v,x);
            if(s[v]==tot) findans(v);
            else s[x]+=s[v];
        }
    }
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int u=read();s[i]=read();
        if(u==0) rt=i;
        else insw(i,u);
        tot+=s[i];
    }
    if(tot%3!=0) return 0*puts("-1");
    else tot/=3;
    dfs(rt,0);
    if(has>=2)
    printf("%d %d\n",ans1,ans2);
    else puts("-1");
    return 0;
}