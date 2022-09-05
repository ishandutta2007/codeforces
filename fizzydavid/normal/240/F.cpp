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

struct segmenttree
{
    struct node
    {
        int sum,l,r;
    }a[400111];
    void build(int l,int r,int id=1)
    {
        a[id].l=l;a[id].r=r;a[id].sum=0;
        if(l==r)return;
        int m=l+r>>1;
        build(l,m,id<<1);
        build(m+1,r,id<<1|1);
    }
    void set(int x,int y,int v,int id=1)
    {
        int &l=a[id].l,&r=a[id].r,m=l+r>>1;
        if(x<=l&&r<=y)
        {
            a[id].sum=v*(r-l+1);
            return;
        }
        if(a[id].sum==0)
        {
            a[id<<1].sum=a[id<<1|1].sum=0;
        }
        else if(a[id].sum==r-l+1)
        {
            a[id<<1].sum=m-l+1;
            a[id<<1|1].sum=r-m;
        }
        if(x<=m)set(x,y,v,id<<1);
        if(m<y)set(x,y,v,id<<1|1);
        a[id].sum=a[id<<1].sum+a[id<<1|1].sum;
    }
    int query(int x,int y,int id=1)
    {
        int &l=a[id].l,&r=a[id].r,m=l+r>>1;
        if(x<=l&&r<=y)return a[id].sum;
        if(a[id].sum==0)
        {
            a[id<<1].sum=a[id<<1|1].sum=0;
        }
        else if(a[id].sum==r-l+1)
        {
            a[id<<1].sum=m-l+1;
            a[id<<1|1].sum=r-m;
        }
        int ans=0;
        if(x<=m)ans+=query(x,y,id<<1);
        if(m<y)ans+=query(x,y,id<<1|1);
        return ans;
    }
}seg[26];
int n,m,cnt[26];
char s[100111];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    getii(n,m);
    for(int i=1;i<=n;i++)s[i]=getchar();
    for(int i=0;i<26;i++)seg[i].build(1,n);
    for(int i=1;i<=n;i++)seg[s[i]-'a'].set(i,i,1);
    int x,y;
    for(int i=1;i<=m;i++)
    {
        getii(x,y);
        int odd=0;
        for(int j=0;j<26;j++)cnt[j]=seg[j].query(x,y),odd+=cnt[j]&1;
        if(odd>1)continue;
        int pos1=x,pos2=y,m=(x+y+1)>>1;
        for(int j=0;j<26;j++)
        {
            if(cnt[j]==0)continue;
            seg[j].set(x,y,0);
            int l=cnt[j]>>1;
            seg[j].set(pos1,pos1+l-1,1);
            seg[j].set(pos2-l+1,pos2,1);
            pos1+=l;pos2-=l;
            if(cnt[j]&1)
            {
                seg[j].set(m,m,1);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(seg[j].query(i,i)==1)
            {
                putchar('a'+j);
                break;
            }
        }
    }
    putchar('\n');
    return 0;
}