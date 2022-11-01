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
const int N=200010;
int n,v,a[N],b[N],ans;
struct bit {
    vector<int> sv,e[N],t[N];
    void make() {
        forinc(i,0,n) sv.pb(a[i]);
        sort(all(sv));
        sv.erase(unique(all(sv)),sv.end());
    }
    void addl(int i,int x) {
        i=lower_bound(all(sv),i)-sv.begin()+1;
        for(;i<=sv.size();i+=i&-i) e[i].pb(x);
    }
    void addr(int i,int x) {
        i=lower_bound(all(sv),i)-sv.begin()+1;
        for(;i;i-=i&-i) e[i].pb(x);
    }
    void build(int o) {
        forinc(i,0,n) {
            if(!o) addl(a[i],a[i]-b[i]);
            else addr(a[i],a[i]+b[i]);
        }
        forinc(i,1,sv.size()) {
            sort(all(e[i]));
            e[i].erase(unique(all(e[i])),e[i].end());
            t[i].resize(e[i].size()+1);
        }
    }
    void upl(int i,int x,int c) {
        i=lower_bound(all(sv),i)-sv.begin()+1;
        for(;i<=sv.size();i+=i&-i) {
            int j=lower_bound(all(e[i]),x)-e[i].begin()+1;
            for(;j;j-=j&-j) t[i][j]=max(t[i][j],c);
        }
    }
    void upr(int i,int x,int c) {
        i=lower_bound(all(sv),i)-sv.begin()+1;
        for(;i;i-=i&-i) {
            int j=lower_bound(all(e[i]),x)-e[i].begin()+1;
            for(;j<=e[i].size();j+=j&-j) t[i][j]=max(t[i][j],c);
        }
    }
    int getr(int i,int x) {
        int ret=0;
        i=lower_bound(all(sv),i)-sv.begin()+1;
        for(;i<=sv.size();i+=i&-i) {
            int j=upper_bound(all(e[i]),x)-e[i].begin();
            for(;j;j-=j&-j) ret=max(ret,t[i][j]);
        }
        return ret;
    }
    int getl(int i,int x) {
        int ret=0;
        i=lower_bound(all(sv),i)-sv.begin()+1;
        for(;i;i-=i&-i) {
            int j=lower_bound(all(e[i]),x)-e[i].begin()+1;
            for(;j<=e[i].size();j+=j&-j) ret=max(ret,t[i][j]);
        }
        return ret;
    }
} L,R;
main() {
    //freopen("1662L.inp","r",stdin);
    n=in,v=in;
    forinc(i,1,n) b[i]=in*v;
    forinc(i,1,n) a[i]=in;
    L.make();L.build(0);
    R.make();R.build(1);
    forinc(i,0,n) {
        int f=max(L.getl(a[i],a[i]-b[i]),R.getr(a[i],a[i]+b[i]))+1;
        if(!i||f>1) {
            ans=max(ans,f-1);
            L.upl(a[i],a[i]-b[i],f);
            R.upr(a[i],a[i]+b[i],f);
        }
    }
    cout<<ans<<"\n";
}