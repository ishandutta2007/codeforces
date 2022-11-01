#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
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
const int N=300010;
int n,t[4*N],mem[4*N];
void tran(int s)
{
    int x=mem[s];
    if(!x) return;
    t[2*s]+=x;
    t[2*s+1]+=x;
    mem[2*s]+=x;
    mem[2*s+1]+=x;
    mem[s]=0;
}
void update(int s,int l,int r,int u,int v,int x)
{
    if(l>v||r<u) return;
    if(l>=u&&r<=v)
    {
        t[s]+=x;
        mem[s]+=x;
        return;
    }
    int mid=(l+r)/2;
    tran(s);
    update(2*s,l,mid,u,v,x);
    update(2*s+1,mid+1,r,u,v,x);
    t[s]=max(t[2*s],t[2*s+1]);
}
int get(int s,int l,int r,int u)
{
    if(l>u||r<u) return 0;
    if(l==r) return t[s];
    tran(s);
    int mid=(l+r)/2;
    return max(get(2*s,l,mid,u),get(2*s+1,mid+1,r,u));
}
struct oo {int l,a,r;} a[N];
vector<int> I[N],O[N];
pii ans;
int main()
{
    //freopen("377D.inp","r",stdin);
    n=in;
    forinc(i,1,n)
    {
        a[i]={in,in,in};
        I[a[i].l].pb(i);
        O[a[i].a+1].pb(i);
    }
    forinc(i,1,300000)
    {
        forv(j,I[i]) update(1,1,3e5,a[j].a,a[j].r,1);
        forv(j,O[i]) update(1,1,3e5,a[j].a,a[j].r,-1);
        if(t[1]>ans.fi) ans={t[1],i};
    }
    cout<<ans.fi<<"\n";
    reset(t,0);reset(mem,0);
    vector<int> e;
    forinc(i,1,n)
    {
        if(a[i].l<=ans.se&&a[i].a>=ans.se)
        {
             update(1,1,3e5,a[i].a,a[i].r,1);
             e.pb(i);
        }
    }
    forinc(i,1,300000) if(get(1,1,3e5,i)==ans.fi)
    {
        forv(j,e) if(a[j].a<=i&&a[j].r>=i) cout<<j<<" ";
        return 0;
    }
}