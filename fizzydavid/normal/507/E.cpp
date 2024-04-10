//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<deque>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF=1<<30;
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
struct heap
{
    pair<pair<int,int>,int>  arr[100011];
    int heap_size;
    heap()
    {
        memset(arr,0,sizeof(pair<pair<int,int>,int> ));
        heap_size=0;
    }
    int size()
    {
        return heap_size;
    }
    bool empty()
    {
        return heap_size>0;
    }
    pair<pair<int,int>,int>  top()
    {
        return arr[1];
    }
    void push(pair<pair<int,int>,int>  x)
    {
        arr[++heap_size]=x;
        int i=heap_size;
        while(i!=1&&arr[i/2]>arr[i])
        {
            swap(arr[i],arr[i/2]);
            i=i/2;
        }
    }
    pair<pair<int,int>,int>  pop()
    {
        pair<pair<int,int>,int>  ans=arr[1];
        arr[1]=arr[heap_size];
        heap_size--;
        int i=1;
        while(i*2<=heap_size&&arr[i]>arr[i*2]||i*2+1<=heap_size&&arr[i]>arr[i*2+1])
        {
            if(arr[i*2+1]>arr[i*2])
            {
                swap(arr[i*2],arr[i]);
                i=i*2;
            }
            else if(arr[i*2]>arr[i*2+1])
            {
                swap(arr[i*2+1],arr[i]);
                i=i*2+1;
            }
        }
        return ans;
    }
};
struct edge
{
    int FF,SS,c;
};
edge make_edge(int FF,int SS,int c)
{
    edge res;
    res.FF=FF;res.SS=SS;res.c=c;
    return res;
}
int n,m,mk[100111],lastv[100111],laste[100111];
pair<int,int>dist[100111];
vector<edge>con[100111];
heap s;
bool vis[100111];
edge e[100111];
void dijstra(int x,int y)
{
    s.push(MP(MP(0,0),x));
    mk[x]=1;
    for(int i=1;i<=n;i++)dist[i].FF=INF,dist[i].SS=INF;
    dist[x]=MP(0,0);
    while(s.size()>0)
    {
        pair<int,int> d=s.top().FF;
        int u=s.top().SS;
        mk[u]=2;s.pop();
        for(int i=0;i<con[u].size();i++)
        {
            int v=con[u][i].FF,d2=con[u][i].SS;
            if(mk[v]==0||mk[v]==1&&MP(d.FF+1,d.SS+d2)<dist[v])
            {
                mk[v]=1;
                dist[v]=MP(d.FF+1,d.SS+d2);lastv[v]=u;laste[v]=con[u][i].c;
                s.push(MP(dist[v],v));
            }
        }
    }
}
vector<pair<int,int> >ans0,ans1;
int main()
{
    scanf("%d%d",&n,&m);int x,y,z;
    edge tmp;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        tmp.FF=y;tmp.SS=-z;tmp.c=i;con[x].PB(tmp);
        tmp.FF=x;tmp.SS=-z;tmp.c=i;con[y].PB(tmp);
        tmp.FF=x;tmp.SS=y;tmp.c=z;e[i]=tmp;
    }
    dijstra(1,n);
    int pos=n;
    while(pos!=1)
    {
        vis[laste[pos]]=1;
        if(e[laste[pos]].c==0)ans1.PB(MP(pos,lastv[pos]));
        pos=lastv[pos];
    }
    for(int i=1;i<=m;i++)if(!vis[i]&&e[i].c)ans0.PB(MP(e[i].FF,e[i].SS));
    printf("%d\n",ans0.size()+ans1.size());
    for(int i=0;i<ans0.size();i++)printf("%d %d 0\n",ans0[i].FF,ans0[i].SS);
    for(int i=0;i<ans1.size();i++)printf("%d %d 1\n",ans1[i].FF,ans1[i].SS);
    return 0;
}