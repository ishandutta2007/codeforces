#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
#define INF 200000000000000000LL
#define MAXN 800000
#define MN 400000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int n,m,s,cnt=0;
ll d[MAXN+5];
struct node{
    ll x;int k;
    bool operator <(const node &y) const
    {
        return x>y.x;
    }
};
int top,id[MAXN+5],head[MAXN+5],num[MAXN+5];
priority_queue<node> q;
struct edge{
    int to,next;ll w;
}e[10000000];
bool mark[MAXN+5];

void ins(int f,int t,int w)
{
    e[++cnt]=(edge){t,head[f],w};head[f]=cnt;
    // cout<<"ins"<<f<<" "<<t<<" "<<w<<endl;
}

void get(int k,int l,int r,int lt=1,int rt=n)
{
    if(l==lt&&r==rt){id[++top]=k;return;}
    int mid=lt+rt>>1;
    if(r<=mid) get(k<<1,l,r,lt,mid);
    else if(l>mid) get(k<<1|1,l,r,mid+1,rt);
    else
    {get(k<<1,l,mid,lt,mid);get(k<<1|1,mid+1,r,mid+1,rt);}
}

void dij()
{
    d[num[s]]=0;q.push((node){0,num[s]});
    while(!q.empty())
    {
        node now=q.top();q.pop();
        if(mark[now.k]) continue;mark[now.k]=1;
        for(int i=head[now.k];i;i=e[i].next)
            if(d[now.k]+e[i].w<d[e[i].to])
            {
                d[e[i].to]=d[now.k]+e[i].w;
                q.push((node){d[e[i].to],e[i].to});
            }
    }
}

void build(int k,int l,int r)
{
    ins(k+MN,k,0);
    //   cout<<"build"<<k<<" "<<l<<" "<<r<<endl;
    if(l==r) {num[l]=k;return;}
    int mid=l+r>>1;
    ins(k<<1,k,0);ins(k<<1|1,k,0);
    ins(k+MN,(k<<1)+MN,0);ins(k+MN,(k<<1|1)+MN,0);
    build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}

int main()
{
    n=read();m=read();s=read();memset(d,127,sizeof(d));
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int t=read();
        if(t==1)
        {int l=read(),r=read(),w=read();ins(num[l],num[r]+MN,w);}
        else
        {
            int v=read(),l=read(),r=read(),w=read();
            top=0;get(1,l,r);
            for(int j=1;j<=top;j++)
                if(t==2)
                    ins(num[v],id[j]+MN,w);
                else
                    ins(id[j],num[v]+MN,w);
        }
    }
    dij();
    for(int i=1;i<=n;i++)
        d[num[i]]=min(d[num[i]],d[num[i]+MN]);
    for(int i=1;i<=n;i++)if(d[num[i]]>=INF)d[num[i]]=-1;
    for(int i=1;i<=n;i++)
        printf("%lld ",d[num[i]]);
    return 0;
}