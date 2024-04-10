#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define timer 1.0*clock()/CLOCKS_PER_SEC
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
int n;
int a[N],p[N],gg[N];
int bit[N];
priority_queue<pii> h;
void update(int i,int x)
{
    for(; i<=n; i+=i&-i) bit[i]+=x;
}
int get(int i)
{
    int g=0;
    for(; i; i-=i&-i) g+=bit[i];
    return g;
}
int htop()
{
    while(h.size() && gg[h.top().se]!=h.top().fi) h.pop();
    assert(h.size()>0);
    return h.top().fi;
}
int get(int l,int r)
{
    return get(r)-get(l-1);
}
void Sol(int i,int &tmp)
{
    int mx=htop();
    if(gg[p[i]]!=mx) {tmp=0;return;}
    int L=p[i]+1,mi,R=n, lf=p[i],rt=n+1;
    while(L<=R)
    {
        mi=(L+R)/2;
        if(get(p[i]+1,mi)==mi-p[i]) L=mi+1;
        else rt=mi,R=mi-1;
    }
    L=1,R=p[i]-1;
    while(L<=R)
    {
        mi=(L+R)/2;
        if(get(mi,p[i]-1)==p[i]-mi) lf=mi,R=mi-1;
        else L=mi+1;
    }
    gg[p[i]]=-1;
    int vall=p[i]-lf+1;
    if(rt<=n)
    {
        gg[rt]+=vall;
        h.push({gg[rt],rt});
    }
    update(p[i],1);
    update(p[i]+1,-1);
}
void Enter()
{
    int T=in;
    while(T--)
    {
        n=in;
        forinc(i,1,n)
        {
            int x=in;
            a[i]=x;
            p[x]=i;
        }
        forinc(i,1,n) h.push({gg[i]=1,i});
        int tmp=1;
        forinc(i,1,n) Sol(i,tmp);
        if(tmp) cout<<"Yes\n";
        else cout<<"No\n";
        while(h.size()) h.pop();
        forinc(i,1,n) bit[i]=gg[i]=a[i]=p[i]=0;
    }
}
main()
{
    //freopen("baiA.inp","r",stdin);
    Enter();
}