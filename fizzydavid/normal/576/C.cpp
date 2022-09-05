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
int n,a[30000000],nxt[1000111],cnt[22];
pair<int,int>pt[1000111];
inline int absi(int x)
{
    return x<0?-x:x;
}
ll totcost;
inline void connect(int x,int y)
{
#ifdef SEE
    totcost+=absi(pt[x].FF-pt[y].FF)+absi(pt[x].SS-pt[y].SS);
#endif
    nxt[x]=y;
}
pair<int,int> run(int x,int bx,int by,int l,int r)
{
    if(r<l)return MP(-1,-1);
    if(l==r)return MP(a[l],a[l]);
#ifdef DEBUG
    cout<<"run:"<<x<<" "<<l<<" "<<r<<endl;
    for(int i=l;i<=r;i++)
    {
        puti(a[i]);
    }
    cout<<endl;
#endif
    int size=1<<(20-x);
    if(x>11)
    {
        for(int i=l;i<r;i++)
        {
            connect(a[i],a[i+1]);
            cnt[x]++;
        }
        return MP(a[l],a[r]);
    }
    int tot,pre=-1,fir=-1;
    pair<int,int>tmp;
    tot=r;
    for(int i=l;i<=r;i++)
        if(pt[a[i]].FF-bx<size&&pt[a[i]].SS-by<size)
            a[++tot]=a[i];
    tmp=run(x+1,bx,by,r+1,tot);
    if(fir==-1&&tmp.FF!=-1)fir=tmp.FF;
    if(pre!=-1&&tmp.FF!=-1)connect(pre,tmp.FF),cnt[x]++;
    if(tmp.SS!=-1)pre=tmp.SS;
    
    tot=r;
    for(int i=l;i<=r;i++)
        if(pt[a[i]].FF-bx>=size&&pt[a[i]].SS-by<size)
            a[++tot]=a[i];
    tmp=run(x+1,bx+size,by,r+1,tot);
    if(fir==-1&&tmp.FF!=-1)fir=tmp.FF;
    if(pre!=-1&&tmp.FF!=-1)connect(pre,tmp.FF),cnt[x]++;
    if(tmp.SS!=-1)pre=tmp.SS;
    
    tot=r;
    for(int i=l;i<=r;i++)
        if(pt[a[i]].FF-bx>=size&&pt[a[i]].SS-by>=size)
            a[++tot]=a[i];
    tmp=run(x+1,bx+size,by+size,r+1,tot);
    if(fir==-1&&tmp.FF!=-1)fir=tmp.FF;
    if(pre!=-1&&tmp.FF!=-1)connect(pre,tmp.FF),cnt[x]++;
    if(tmp.SS!=-1)pre=tmp.SS;
    
    tot=r;
    for(int i=l;i<=r;i++)
        if(pt[a[i]].FF-bx<size&&pt[a[i]].SS-by>=size)
            a[++tot]=a[i];
    tmp=run(x+1,bx,by+size,r+1,tot);
    if(fir==-1&&tmp.FF!=-1)fir=tmp.FF;
    if(pre!=-1&&tmp.FF!=-1)connect(pre,tmp.FF),cnt[x]++;
    if(tmp.SS!=-1)pre=tmp.SS;
    return MP(fir,pre);
}
int main()
{
#ifdef SEE
    freopen("576C.in","r",stdin);
#endif
    geti(n);
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
        geti(pt[i].FF);
        geti(pt[i].SS);
    }
    int p=run(1,0,0,1,n).FF;
#ifndef SEE
    while(p!=0)
    {
        puti(p);
        p=nxt[p];
    }
#endif

#ifdef SEE
    cout<<totcost<<endl;
    for(int i=1;i<=20;i++)cout<<cnt[i]<<endl;
#endif
    return 0;
}