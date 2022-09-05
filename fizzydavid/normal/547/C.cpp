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
#define puti(x) putnum(x)
#define putii(x,y) puti(x),putnum(y)
#define putiii(x,y,z) putii(x,y),putnum(z)
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
int n,q,cnt[500111],now,cnt1;
bool f[200111];
vector<int>pl[200111];
int pr[500111],pn;
bool isp[500111];
void prework()
{
    for(int i=2;i*i<=500000;i++)
    {
        if(!isp[i])
        {
            for(int j=i*2;j<=500000;j+=i)
            {
                isp[j]=1;
            }
        }
    }
    for(int i=2;i<=500000;i++)
    {
        if(!isp[i])
        {
            pr[++pn]=i;
        }
    }
}
int main()
{
    prework();
    getii(n,q);
    for(int i=1;i<=n;i++)
    {
        int x;
        geti(x);
        for(int j=1;j<=pn&&pr[j]*pr[j]<=x;j++)
        {
            if(x%pr[j]==0)
            {
                while(x%pr[j]==0)x/=pr[j];
                pl[i].PB(j);
            }
        }
        if(x>1)pl[i].PB(lower_bound(pr+1,pr+pn+1,x)-pr);
    }
    int x;
    ll ans=0;
    while(q--)
    {
        geti(x);
        int sz=pl[x].size();
        ll res=0;
        if(sz==0)
        {
            if(f[x])
            {
                cnt1--;
                now--;
                ans-=now;
            }
            else
            {
                cnt1++;
                ans+=now;
                now++;
            }
            f[x]^=1;
            putsi(ans);
            continue;
        }
        for(int i=1;i<(1<<sz);i++)
        {
            int count1=0,tmp=1;
            for(int j=0;j<sz;j++)
            {
                if((i>>j)&1)
                {
                    count1++;
                    tmp*=pr[pl[x][j]];
                }
            }
            if(count1&1)res+=cnt[tmp];else res-=cnt[tmp];
            if(f[x])cnt[tmp]--;else cnt[tmp]++;
        }
//      cout<<now<<" "<<res<<endl;
        if(f[x])ans-=now-res,now--;else ans+=now-res,now++;
        f[x]^=1;
        putsi(ans);
    }
    return 0;
}