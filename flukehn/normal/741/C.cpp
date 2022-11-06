#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 400010
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct zgz
{
    int next,to;
}edge[N<<1];
int cnt=1,head[N];
void add(int from,int to)
{
    edge[cnt].to=to;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}
bool vis[N];
int c[N];
void col(int x,int c_)
{
    c[x]=c_;
    vis[x]=1;
    c_=(c_==1?2:1);
    for(int i=head[x];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(!vis[to])col(to,c_);
    }
}
int n;
int a[N],b[N];
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int x=read(),y=read();
        a[i]=x,b[i]=y;
        add(i*2-1,i*2);
        add(i*2,i*2-1);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=2*n;i++)
    	if(!vis[i])col(i,1);
    for(int i=1;i<=n;i++)
    printf("%d %d\n",c[a[i]],c[b[i]]);
}