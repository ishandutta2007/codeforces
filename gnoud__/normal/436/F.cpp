#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=1e5+10;
int n,w,t[N];
pii a[N];
bool cmp(pii u,pii v) {return u.se<v.se;}
void upd(int i)
{
    for(;i;i-=i&-i) t[i]++;
}
ll get(int i)
{
    int g=0;
    for(;i<=1e5;i+=i&-i) g+=t[i];
    return g;
}
main()
{
    //freopen("BANNERS.inp","r",stdin);
    //freopen("BANNERS.out","w",stdout);
    n=in,w=in;
    int mb=0;
    forinc(i,1,n) a[i]={in,in},mb=max(mb,a[i].se);
    sort(a+1,a+n+1,cmp);
    cout<<0<<" "<<0<<"\n";
    int i=1,p=0;
    ll ans=0;
    forinc(c,1,mb+1)
    {
        int R=0;
        while(i<=n&&a[i].se<c)
        {
            R=max(R,a[i].fi);
            upd(a[i++].fi);
        }
        while(R>0)
        {
            int l=1,r=R,v=0;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(get(mid)*R>ans) v=mid,l=mid+1;
                else r=mid-1;
            }
            if(v)
            {
                ll f=get(v)*v;
                if(ans<f) ans=f,p=v;
            }
            R=v-1;
        }
        cout<<ans+1ll*(n-i+1)*c*w<<" "<<p<<"\n";
    }
}