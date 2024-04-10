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
int rd(int l,int r){return uniform_int_distribution<>(l,r)(rnd);}
void NC(ull k){cerr<<(k>>20)<<endl;}

const int mxn=2e5+3;
VI po[mxn];int n,a[mxn],ti[mxn],X,vl[mxn*2],pr[mxn],nx[mxn];
set<int>st;
int main(){
    cin>>n;for(int i=1;i<=n;++i)scanf("%d",a+i),po[a[i]].push_back(i);for(int i=1;i<=n;++i)if(po[i].size()>po[X].size())X=i;
    int P=0;for(int x:po[X])st.insert(x),pr[x]=P,nx[P]=x,P=x;nx[P]=n+1;
    memset(vl,0x3f,sizeof(vl));int da=0;
    for(int t=1;t<=n;++t)if(po[t].size()&&t!=X){
        static int e[mxn];int nn=0;for(int p:po[t]){
            e[++nn]=p;auto it=st.lower_bound(p);if(it!=st.end())e[++nn]=*it,st.erase(it);
            it=st.lower_bound(p);if(it!=st.begin())e[++nn]=*--it,st.erase(it);
        }
        sort(e+1,e+nn+1);
        for(int l=1,r,v0,v1;l<=nn;l=r+1){
            r=l;if(l!=1)assert(a[e[l]]==X);if(a[e[l]]==X)P=e[l],v0=pr[P];else P=0,v0=0;
            while(r!=nn){
                if(a[e[r+1]]!=X)++r;else if(pr[e[r+1]]!=P)break;else P=e[++r];
            }
            if(r!=nn)assert(a[e[r]]==X);if(a[e[r]]==X)v1=nx[e[r]]-1;else v1=n;
            int L=n,R=n;for(int i=l,v=n;i<=r;++i){
                vl[v]=min(vl[v],i==l?v0:e[i-1]);v+=a[e[i]]==X?1:-1;da=max(da,(i==r?v1:e[i+1]-1)-vl[v]);
                L=min(L,v),R=max(R,v);
            }
            for(int i=L;i<=R;++i)vl[i]=1e9;
        }
        for(int i=1;i<=nn;++i)if(a[e[i]]==X)st.insert(e[i]);
    }
    cout<<da<<endl;
    return 0;
}