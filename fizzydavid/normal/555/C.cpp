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
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
struct segmenttree
{
    struct node
    {
        int l,r,v,mk;
    }a[800111];
    void build(int l,int r,int id=1)
    {
        a[id].l=l;a[id].r=r;a[id].v=0;
        if(l==r)return;
        int m=l+r>>1;
        build(l,m,id<<1);
        build(m+1,r,id<<1|1);
    }
    int query(int x,int id=1)
    {
        int &l=a[id].l,&r=a[id].r;
        if(a[id].mk>0)
        {
            a[id].v=max(a[id].v,a[id].mk);
            if(l!=r)
            {
                a[id<<1].mk=max(a[id<<1].mk,a[id].mk);
                a[id<<1|1].mk=max(a[id<<1|1].mk,a[id].mk);
            }
            a[id].mk=0;
        }
        if(l==x&&x==r)return a[id].v;
        int m=l+r>>1;
        if(x<=m)return query(x,id<<1);
        else return query(x,id<<1|1);
    }
    void set(int x,int y,int val,int id=1)
    {
        int &l=a[id].l,&r=a[id].r;
        if(x<=l&&r<=y)a[id].mk=max(a[id].mk,val);
        if(a[id].mk>0)
        {
            a[id].v=max(a[id].v,a[id].mk);
            if(l!=r)
            {
                a[id<<1].mk=max(a[id<<1].mk,a[id].mk);
                a[id<<1|1].mk=max(a[id<<1|1].mk,a[id].mk);
            }
            a[id].mk=0;
        }
        if(x<=l&&r<=y)return;
        int m=l+r>>1;
        if(x<=m)set(x,y,val,id<<1);
        if(m<y)set(x,y,val,id<<1|1);
    }
}r,c;
int n,q,rn,cn;
vector<int>ptr,ptc;
pair<pair<int,int>,bool>qr[200111];
bool f[200111];
int main()
{
    getii(n,q);
    int x,y;
    char dir;
    for(int i=1;i<=q;i++)
    {
        getii(y,x);
        dir=mygetchar();
        qr[i].FF=MP(x,y);
        qr[i].SS=(dir=='U');
        ptr.PB(x);
        ptc.PB(y);
    }
    sort(ptr.begin(),ptr.end());
    sort(ptc.begin(),ptc.end());
    int rn=ptr.size(),cn=ptc.size();
    r.build(1,cn);
    c.build(1,rn);
    for(int i=1;i<=q;i++)
    {
        qr[i].FF.FF=lower_bound(ptr.begin(),ptr.end(),qr[i].FF.FF)-ptr.begin()+1;
        qr[i].FF.SS=lower_bound(ptc.begin(),ptc.end(),qr[i].FF.SS)-ptc.begin()+1;
    }
    bool d;
    for(int i=1;i<=q;i++)
    {
        x=qr[i].FF.FF;y=qr[i].FF.SS;d=qr[i].SS;
        if(f[x])
        {
            putsi(0);
            continue;
        }
        else
        {
            f[x]=1;
        }
        if(d)
        {
            int tmp=r.query(y);
            if(tmp==0)putsi(ptr[x-1]);else putsi(ptr[x-1]-ptr[tmp-1]);
            if(tmp==0)tmp++;
            c.set(tmp,x,y);
        }
        else
        {
            int tmp=c.query(x);
            if(tmp==0)putsi(ptc[y-1]);else putsi(ptc[y-1]-ptc[tmp-1]);
            if(tmp==0)tmp++;
            r.set(tmp,y,x);
        }
    }
    return 0;
}