//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
    register ll r=0;register bool ng=0;register char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')ng=1,c=getchar();
    while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
    if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
    if(x<0)putchar('-'),x=-x;
    register short a[20]={},sz=0;
    while(x>0)a[sz++]=x%10,x/=10;
    if(sz==0)putchar('0');
    for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,a[100111];
ll dis[100111];
bool vis[100111];
priority_queue<pair<ll,int> > pq;
const int dir[2]={-1,1};
void insert(int x,int v)
{
    pq.push(MP(v,x));
    dis[x]=-v;
}
int main()
{
    geti(n);
    for(int i=1;i<=n;i++)
        geti(a[i]);
    insert(1,-1);
    insert(n,-1);
    for(int i=2;i<n;i++)
        insert(i,-min(min(a[i-1]+1,a[i+1]+1),a[i]));
    while(!pq.empty())
    {
        int u=pq.top().SS,d=-pq.top().FF;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<2;i++)
        {
            int v=u+dir[i];
            if(v<1||v>n)continue;
            if(dis[u]+1<dis[v])
            {
                dis[v]=dis[u]+1;
                pq.push(MP(-dis[v],v));
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,dis[i]);
    cout<<ans<<endl;
    return 0;
}