#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1003;
int a[mxn],b[mxn],n;

int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d%d",a+i,b+i);
        sort(a+1,a+n+1),sort(b+1,b+n+1);
        if(n&1)puts("1");
        else{
            int t=n>>1;
            printf("%lld\n",1ll*(a[t+1]-a[t]+1)*(b[t+1]-b[t]+1));
        }
    }
    return 0;
}