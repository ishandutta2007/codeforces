#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define uu unsigned
#define scanf(x...) assert(~scanf(x))
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cerr<<(k>>20)<<endl;}

const int mxn=2e5+3;
int n,a[mxn],jg[mxn],cc[mxn],da[mxn];
struct cmp1{bool operator()(int x,int y){return cc[x]!=cc[y]?cc[x]<cc[y]:x<y;}};
set<int,cmp1>st;
VI po[mxn];

void slv(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);
//    n=2e5;for(int i=1;i<=n;++i)a[i]=rd(1,100);
    st.clear();
    for(int i=1;i<=n;++i)cc[i]=0,po[i].clear();for(int i=1;i<=n;++i)++cc[a[i]],po[a[i]].push_back(i);
    for(int i=1;i<=n;++i)if(po[i].size())st.insert(i);
    int S=po[*--st.end()].back();
    for(int T=1,x=S;T<=n;++T){
        if(T==n){jg[x]=S;break;}
        int e=a[x];po[e].pop_back();
        st.erase(e),--cc[e];
        int c=e;if(st.size())c=*--st.end();if(cc[e])st.insert(e);
        jg[x]=po[c].back(),x=jg[x];
    }
    for(int i=1;i<=n;++i)da[jg[i]]=a[i];
    for(int i=1;i<=n;++i)printf("%d ",da[i]);puts("");
}

int main(){
//rnd.seed(555);slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();slv();return 0;
    int ca;cin>>ca;while(ca--)slv();
    return 0;
}