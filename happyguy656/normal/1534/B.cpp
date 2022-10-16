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
 
const int mxn=4e5+3;
int n,a[mxn];
 
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",a+i);a[n+1]=0;
        ll re=a[1]+a[n];for(int i=2;i<=n;++i)re+=abs(a[i]-a[i-1]);
        for(int i=1;i<=n;++i)if(a[i]>a[i-1]&&a[i]>a[i+1])re-=a[i]-max(a[i-1],a[i+1]);
        printf("%lld\n",re);
    }
    return 0;
}