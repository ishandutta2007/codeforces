//while(true)rp++;
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
#define putsi(x) puti(x),putendl()
#define putsii(x,y) putii(x,y),putendl()
#define putsiii(x,y,z) putiii(x,y,z),putendl()
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
const int BS=700;
int n,q,a[500111];
struct blocks
{
    int beg,L,R;
    bool f;
    ll v[BS+2],lazy;
    map<ll,pair<int,int> >mp;
    blocks()
    {
        lazy=0;
    }
    void maintain()
    {
        f=0;
        mp.clear();
        for(int i=1;i<=R-beg;i++)
        {
            pair<int,int>&p=mp[v[i]];
            if(mp[v[i]].FF==0)p.FF=beg+i;else p.FF=min(p.FF,beg+i);
            p.SS=max(p.SS,beg+i);
        }
    }
    void add(int l,int r,int x)
    {
        l=max(l,L);
        r=min(r,R);
        if(l>r)return;
        if(l==L&&r==R)
        {
            lazy+=x;
        }
        else
        {
            f=1;
            for(int i=l-beg;i<=r-beg;i++)
            {
                v[i]+=x;
            }
        }
    }
}b[750];
int main()
{
    getii(n,q);
    for(int i=1;i<=n;i++)geti(a[i]);
    for(int i=0;BS*i+1<=n;i++)
    {
        b[i].L=i*BS+1;b[i].R=min(n,i*BS+BS);b[i].beg=i*BS;
        for(int j=i*BS+1;j<=i*BS+BS&&j<=n;j++)
        {
            b[i].v[j-i*BS]=a[j];
        }
        b[i].f=1;
    }
    int op,l,r,x;
    for(int i=1;i<=q;i++)
    {
        geti(op);
        if(op==1)
        {
            getiii(l,r,x);
            for(int j=0;BS*j+1<=n;j++)
            {
                b[j].add(l,r,x);
            }
        }
        else
        {
            geti(x);
            int ansl=n,ansr=0;
            for(int j=0;BS*j+1<=n;j++)
            {
                if(b[j].f)b[j].maintain();
                map<ll,pair<int,int> >::iterator it=b[j].mp.find(x-b[j].lazy);
                if(it!=b[j].mp.end())
                {
                    pair<int,int> p=it->SS;
                    if(p.FF!=0)ansl=min(ansl,p.FF);
                    if(p.SS!=0)ansr=max(ansr,p.SS);
                }
            }
            if(ansr-ansl<0)puts("-1");
            else putsi(ansr-ansl);
        }
    }
    return 0;
}