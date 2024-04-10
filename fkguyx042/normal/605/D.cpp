#include<set>
#include<cstdio>
#include<algorithm>

#define N 100010
#define mp make_pair
#define fi first
#define se second

using namespace std;

set<pair<int,int> >c[N*2];
set<pair<int,int> >::iterator it;

struct lhy{
    int x1,y1,x2,y2;
}a[N];

int n,l,h;
int dis[N],Q[N],X[2*N],flag[N],q[N],Last[N];

inline void add(int x,int val)
{
    for(;x<=X[0];x+=x&-x)c[x].insert(mp(a[val].y1,val));
}

inline void ask(int x,int y)
{
    for(;x;x-=x&-x)
    {
        for(it=c[x].begin();it!=c[x].end();it++)
        {
            if((*it).first>y)break;
            Q[++Q[0]]=(*it).second;
            if(flag[Q[Q[0]]])Q[0]--;
            else flag[Q[Q[0]]]=1;
        }
    }
}

inline void Del(int x,int val)
{
    for(;x<=X[0];x+=x&-x)c[x].erase(mp(a[val].y1,val));
}

int main()
{
    scanf("%d",&n);
    X[++X[0]]=0;
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2),X[++X[0]]=a[i].x1,X[++X[0]]=a[i].x2;
    sort(X+1,X+1+X[0]);
    X[0]=unique(X+1,X+1+X[0])-X-1;
    for(int i=1;i<=n;i++)
        a[i].x1=lower_bound(X+1,X+1+X[0],a[i].x1)-X,a[i].x2=lower_bound(X+1,X+1+X[0],a[i].x2)-X;
    for(int i=1;i<=n;i++)
        add(a[i].x1,i),dis[i]=-1;
    q[++l]=0;
    a[0].x2=1;
    flag[0]=1;
    while(h<l)
    {
        int v=q[++h];
        Q[0]=0;
        ask(a[v].x2,a[v].y2);
        for(int i=1;i<=Q[0];i++)
        {
            dis[Q[i]]=dis[v]+1;
            Last[Q[i]]=v;
            Del(a[Q[i]].x1,Q[i]);
            q[++l]=Q[i];
        }
    }
    printf("%d\n",dis[n]);
    if(dis[n]==-1)return 0;
    l=0;
    for(int i=n;i;i=Last[i])q[++l]=i;
    for(int i=l;i;i--)printf("%d ",q[i]);
}