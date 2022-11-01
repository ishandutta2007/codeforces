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
const int N=100010;
int n,m,s,ans[N];
pii a[N];
struct oo {int a,c,id;} b[N];
bool cmp(oo u,oo v) {return u.a<v.a;}
bool kt(int x)
{
    priority_queue<pii,vector<pii>,greater<pii> > h;
    int j=n,i=m,ret=0;
    while(i>0)
    {
        while(b[j].a>=a[i].fi) h.push({b[j].c,b[j].id}),--j;
        if(h.empty()) return 0;
        pii tg=h.top();h.pop();
        ret+=tg.fi;
        if(ret>s) return 0;
        int _i=max(0,i-x);
        for(;i>_i;--i) ans[a[i].se]=tg.se;
    }
    return (ret<=s);
}
int main()
{
    //freopen("377B.inp","r",stdin);
    n=in,m=in,s=in;
    forinc(i,1,m) a[i]={in,i};
    forinc(i,1,n) b[i].a=in,b[i].id=i;
    forinc(i,1,n) b[i].c=in;
    sort(a+1,a+m+1);
    sort(b+1,b+n+1,cmp);
    int l=1,r=m,kq=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(kt(mid)) kq=mid,r=mid-1;
        else l=mid+1;
    }
    if(kq==-1) return cout<<"NO\n",0;
    cout<<"YES"<<"\n";
    kt(kq);
    forinc(i,1,m) cout<<ans[i]<<" ";
}