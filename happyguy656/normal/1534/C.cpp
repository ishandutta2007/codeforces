#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mod=1e9+7,mxn=4e5+3;
int a[mxn],b[mxn],n,pos[mxn],vs[mxn];
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);for(int i=1;i<=n;++i)scanf("%d",b+i),pos[b[i]]=i,vs[i]=0;
        ll h=1;
        for(int i=1;i<=n;++i)if(!vs[a[i]]){
            int x=i;while(!vs[a[x]])vs[a[x]]=1,x=pos[a[x]];
            h=h*2%mod;
        }
        printf("%lld\n",h);
    }
    return 0;
}