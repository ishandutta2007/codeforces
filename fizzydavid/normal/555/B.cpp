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
int n,m;
set<pair<ll,int> >st;
struct segment
{
    ll x,y;
    int id;
    bool operator<(const segment &tmp)const
    {
        if(y!=tmp.y)return y<tmp.y;
        else return x<tmp.x;
    }
}seg[200111];
pair<ll,int>b[200111];
int ans[200111];
int main()
{
    getii(n,m);
    ll lx,ly,x,y;
    getii(lx,ly);
    for(int i=1;i<n;i++)
    {
        getii(x,y);
        seg[i].x=x-ly;
        seg[i].y=y-lx;
        seg[i].id=i;
        lx=x;ly=y;
    }
    for(int i=1;i<=m;i++)
    {
        geti(b[i].FF);
        b[i].SS=i;
    }
    sort(b+1,b+m+1);
    sort(seg+1,seg+n);
    int it=1;
    for(int i=1;i<n;i++)
    {
        while(it<=m&&b[it].FF<=seg[i].y)
        {
            st.insert(b[it]);
            it++;
        }
        set<pair<ll,int> >::iterator sit=st.lower_bound(MP(seg[i].x,-1));
        if(sit==st.end())
        {
            puts("No");
            return 0;
        }
        else
        {
            ans[seg[i].id]=sit->SS;
            st.erase(sit);
        }
    }
    puts("Yes");
    for(int i=1;i<n;i++)puti(ans[i]);
    return 0;
}