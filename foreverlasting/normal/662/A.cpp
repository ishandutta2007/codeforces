//2019.3.22 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
#define RG register
inline int read() {
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')w=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y) {
    x^=y^=x^=y;
}
inline int _abs(const res &x) {
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
const int N=5e5+10;
namespace MAIN {
    int n;
    LL a[N],b[N],ret;
    struct LB{
        int cnt;
        LL p[100+10];
        inline bool insert(RG LL x){
            for(res i=1;i<=cnt+1;i++)x=min(x,p[i]^x);
            if(x){p[++cnt]=x;return 1;}
            return 0;
        }
    }A;
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)scanf("%lld%lld",&a[i],&b[i]),A.insert(a[i]^b[i]),ret^=a[i];
        if(A.insert(ret))printf("%d/%d\n",1,1);
        else printf("%lld/%lld\n",(1LL<<A.cnt)-1,1LL<<A.cnt);
    }
}
int main() {
//    freopen("graph.in","r",stdin);
//    freopen("graph.out","w",stdout);
    MAIN::MAIN();
    return 0;
}