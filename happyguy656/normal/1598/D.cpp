#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,ll>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=2e5+3;
int n,c1[mxn],c2[mxn],a[mxn],b[mxn];

int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d%d",a+i,b+i),++c1[a[i]],++c2[b[i]];
        ll ans=1ll*n*(n-1)*(n-2)/6;for(int i=1;i<=n;++i)ans-=1ll*(c1[a[i]]-1)*(c2[b[i]]-1);
        printf("%lld\n",ans);
        for(int i=1;i<=n;++i)c1[i]=c2[i]=0;
    }
    return 0;
}