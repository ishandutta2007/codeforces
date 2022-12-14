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

struct edge{
    int to,next;
}e[600005];
int head[600005];
int n,rt,cnt=0;
bool b[600005];
int ans=0;
int num[600005];
int col[600005];
int beg[600005];

void ins(int f,int t)
{
    e[++cnt].next=head[f];head[f]=cnt;
    e[cnt].to=t;
}

void dfs(int x,int fa)
{
    num[x]=1;
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            dfs(e[i].to,x);
            num[x]++;
        }
    if(fa!=0)num[x]++;
}

void solve(int x,int fa)
{
//	cout<<"solve"<<x<<" "<<fa<<" "<<col[x]<<" "<<col[fa]<<endl;
    int c=1;
    for(int i=head[x];i;i=e[i].next,c=c+1)
        if(!col[e[i].to])
        {
            while(c==col[x]||c==col[fa])c=c+1;
            col[e[i].to]=c;
            solve(e[i].to,x);
		}
		else c--;
}

int main()
{
    n=read();
    for(int i=1;i<n;i++)
    {int u=read(),v=read();ins(u,v);ins(v,u);}
    dfs(1,0);for(int i=1;i<=n;i++)if(num[i]>ans){ans=num[i];rt=i;}
    col[rt]=1;solve(rt,0);printf("%d\n",ans);
    for(int i=1;i<=n;i++)printf("%d ",col[i]);
    return 0;
}