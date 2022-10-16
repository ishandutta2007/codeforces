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

const int mxn=1e5+3;
int n,a[mxn],b[mxn],s1[mxn],s2[mxn];
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);for(int i=1;i<=n;++i)scanf("%d",b+i);
        sort(a+1,a+n+1),sort(b+1,b+n+1);
        for(int i=1;i<=n;++i)s1[i]=s1[i-1]+a[i],s2[i]=s2[i-1]+b[i];
        int l=0,r=n*3,md;while(l<r){
            md=(l+r)>>1;
            int n1=md+n,rr=n1/4;
            if(s1[n]+100*md-s1[rr]>=s2[n]-s2[rr>=md?rr-md:0])r=md;else l=md+1;
        }
        printf("%d\n",l);
    }
    return 0;
}