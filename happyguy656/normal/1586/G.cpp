#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=4e5+3,mod=1e9+7;
pii ee[mxn];
int n,v1[mxn],v2[mxn],px[mxn],m,v0[mxn],xp[mxn];
bool vs[mxn];
bool cmp1(int x,int y){return v1[x]<v1[y];}
struct arrrr{ll a[mxn];void add(int x,int y){for(;x<=n;x+=x&-x)a[x]+=y;}ll ask(int x){ll r=0;for(;x;x&=x-1)r+=a[x],r%=mod;return r;}}ar;
set<int>st;

int main(){
    cin>>n;for(int i=1;i<=n;++i)scanf("%d%d",v1+i,v2+i),ee[i].first=v2[i],ee[i].second=v1[i];sort(ee+1,ee+n+1);
    cin>>m;for(int i=1;i<=m;++i)scanf("%d",v0+i),v0[i]=v1[v0[i]];
    for(int i=1;i<=n;++i)v1[i]=ee[i].second,v2[i]=ee[i].first,px[i]=i;
    sort(px+1,px+n+1,cmp1);
    for(int i=1;i<=n;++i)xp[v1[i]]=i;for(int i=1;i<=m;++i)st.insert(xp[v0[i]]);
    for(int t=1;t<=n&&st.size();++t)if(*--st.end()>=px[t])st.erase(px[t]),vs[px[t]]=1;
    ll ans=0;
    for(int t=n;t;--t){
        int x=px[t];ll v=ar.ask(x)+1;
        if(vs[x])ans+=v;ar.add(x,v);
    }
    ans=(ans%mod+mod)%mod;printf("%lld\n",ans);
    return 0;
}