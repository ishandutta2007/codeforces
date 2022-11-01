#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll hmt() {ll x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
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
const int N=50010,mod=1e9+7;
int n,a[N],t[N*35][32],dd[N*35][2],id;
ll m;
void add(int s,int x,int i,int o)
{
    if(!i)
    {
        if(!o) t[s][o]++;
        else if(bit(x,o)) t[s][o]++;
        return;
    }
    if(dd[s][bit(x,i)]<0) dd[s][bit(x,i)]=++id;
    int l=dd[s][0],r=dd[s][1];
    add(dd[s][bit(x,i)],x,i-1,o);
    t[s][o]=0;
    if(l>0) t[s][o]+=t[l][o];
    if(r>0) t[s][o]+=t[r][o];
}
ll get(int s,int x,int y,int i,int o)
{
    if(s<0) return 0;
    if(!i) return t[s][o];
    int l=dd[s][0],r=dd[s][1];
    if(!bit(x,i))
    {
        if(!bit(y,i)) return ((r<0)?0:t[r][o])+get(l,x,y,i-1,o);
        return get(r,x,y,i-1,o);
    }
    else
    {
        if(!bit(y,i)) return ((l<0)?0:t[l][o])+get(r,x,y,i-1,o);
        return get(l,x,y,i-1,o);
    }
}
ll cal(int x)
{
    forinc(i,0,id) t[i][0]=0;
    ll ret=0;
    forinc(i,1,n)
    {
        ret+=get(0,a[i],x,30,0);
        add(0,a[i],30,0);
    }
    return ret;
}
main()
{
    //freopen("241B.inp","r",stdin);
    n=in,m=in;
    forinc(i,1,n) a[i]=in;
    int l=0,r=(1<<30)-1,val;
    reset(dd,-1);
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(cal(mid)>=m) val=mid,l=mid+1;
        else r=mid-1;
    }
    ll ans=0;
    reset(t,0);
    forinc(i,1,n)
    {
        forinc(j,1,30)
        {
            ll sl=get(0,a[i],val,30,j);
            if(bit(a[i],j)) sl=get(0,a[i],val,30,0)-sl;
            ans=(ans+1ll*sl*(1<<(j-1)))%mod;
            add(0,a[i],30,j);
        }
        add(0,a[i],30,0);
    }
    cout<<((ans-(cal(val)-m)*val)%mod+mod)%mod<<"\n";
}