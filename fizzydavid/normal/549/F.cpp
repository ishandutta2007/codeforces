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
int n,k,ans;
int a[300111],cnt[1000111];
ll calc(int l,int r)
{
    if(l>=r)return 0;
    int m=l+r>>1;
    ll ans=calc(l,m-1)+calc(m+1,r);
    int lit=m,rit=m+1,ls=0,rs=0,lmx=0,rmx=0;
    //max is on the left
    ls=(ls+a[lit])%k;
    lmx=max(lmx,a[lit]);
    for(int i=m+1;i<=r;i++)
    {
        rmx=max(rmx,a[i]);
        while(lit>=l&&lmx<rmx)
        {
            ans+=cnt[(-ls+lmx%k+k)%k];
            lit--;
            if(lit<l)break;
            ls=(ls+a[lit])%k;
            lmx=max(lmx,a[lit]);
        }
        rs=(rs+a[i])%k;
        cnt[rs]++;
    }
    while(lit>=l)
    {
        ans+=cnt[(-ls+lmx%k+k)%k];
        lit--;
        if(lit<l)break;
        ls=(ls+a[lit])%k;
        lmx=max(lmx,a[lit]);
    }
    rs=0;
    for(int i=m+1;i<=r;i++)
    {
        rs=(rs+a[i])%k;
        cnt[rs]--;
    }
    //max is on the right
    ls=rs=lmx=rmx=0;
    rs=(rs+a[rit])%k;
    rmx=max(rmx,a[rit]);
    for(int i=m;i>=l;i--)
    {
        lmx=max(lmx,a[i]);
        while(rit<=r&&rmx<=lmx)
        {
            ans+=cnt[(-rs+rmx%k+k)%k];
            rit++;
            if(rit>r)break;
            rs=(rs+a[rit])%k;
            rmx=max(rmx,a[rit]);
        }
        ls=(ls+a[i])%k;
        cnt[ls]++;
        if(i<m&&(ls-lmx%k+k)%k==0)ans++;
    }
    while(rit<=r)
    {
        ans+=cnt[(-rs+rmx%k+k)%k];
        rit++;
        if(rit>r)break;
        rs=(rs+a[rit])%k;
        rmx=max(rmx,a[rit]);
    }
    ls=0;
    for(int i=m;i>=l;i--)
    {
        ls=(ls+a[i])%k;
        cnt[ls]--;
    }
    return ans;
}
int main()
{
    getii(n,k);
    for(int i=1;i<=n;i++)geti(a[i]);
    putsi(calc(1,n));
    return 0;
}