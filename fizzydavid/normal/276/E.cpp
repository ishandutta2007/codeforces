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
struct two_dimensional_BIT
{
    vector<int>a[200111];
    int tot,size[200111];
    two_dimensional_BIT()
    {
        memset(size,0,sizeof(size));
        tot=0;
    }
    void init()
    {
        for(int i=1;i<=tot;i++)
        {
            for(int j=i;j<=2*tot;j+=j&(-j))
            {
                size[j]=max(size[j],size[i]);
            }
        }
        tot*=2;
        for(int i=1;i<=tot;i++)
        {
            a[i].PB(0);
            while(size[i]--)
            {
                a[i].PB(0);
            }
        }
    }
    int sum(int x,int y)
    {
        int ans=0;
        for(int i=x;i<=tot;i+=i&(-i))
        {
            for(int j=y;j<a[i].size();j+=j&(-j))
            {
                ans+=a[i][j];
            }
        }
        return ans;
    }
    void add(int x,int y,int delta)
    {
        for(int i=min(x,tot);i>0;i-=i&(-i))
        {
            for(int j=min(y,int(a[i].size())-1);j>0;j-=j&(-j))
            {
                a[i][j]+=delta;
            }
        }
    }
    void addsegment(int A,int B,int C,int D,int delta)
    {
//      cout<<"add segment:"<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<delta<<endl;
        add(C,D,delta);
        add(A-1,D,-delta);
        add(C,B-1,-delta);
        add(A-1,B-1,delta);
    }
}bit;
vector<int>con[100111];
int n,q,sz,dis[100111],top[100111],gr[100111],sum1;
void dfs(int x,int d,int pre,int g)
{
    dis[x]=d;
    gr[x]=g;
    bit.size[g]++;
    for(int i=0;i<con[x].size();i++)
        if(con[x][i]!=pre)
            dfs(con[x][i],d+1,x,g);
}
int main()
{
    getii(n,q);
    for(int i=1;i<n;i++)
    {
        int x,y;
        getii(x,y);
        con[x].PB(y);
        con[y].PB(x);
    }
    sz=con[1].size();
    bit.tot=sz;
    for(int i=1;i<=sz;i++)
    {
        top[i]=con[1][i-1];
        dfs(top[i],1,1,i);
    }
    bit.init();
    while(q--)
    {
        int op,v,x,d;
        geti(op);
        if(op==1)
        {
            geti(v);
            if(v==1)putsi(sum1);
            else putsi(bit.sum(gr[v],dis[v]));
        }
        else
        {
            getiii(v,x,d);
            if(v==1)
            {
                sum1+=x;
                bit.addsegment(1,1,sz,d,x);
            }
            else
            {
                bit.addsegment(gr[v],dis[v]-d,gr[v],dis[v]+d,x);
                int rest=d-dis[v];
                if(rest>=0)
                {
                    sum1+=x;
                    if(rest>0)
                    {
                        bit.addsegment(1,1,sz,rest,x);
                        bit.addsegment(gr[v],1,gr[v],rest,-x);
                    }
                }
            }
        }
    }
    return 0;
}