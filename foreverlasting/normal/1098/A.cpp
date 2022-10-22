//2019.1.25 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
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
const int N=1e5+10;
namespace MAIN {
    int n;
    int fa[N],sum[N];
    LL ans;
    inline void MAIN(){
        n=read();
        for(res i=2;i<=n;i++)fa[i]=read();
        for(res i=1;i<=n;i++){
            sum[i]=read();
            if(sum[i]==-1)sum[i]=inf;
        }
        for(res i=2;i<=n;i++)if(sum[i]!=inf)sum[fa[i]]=_min(sum[fa[i]],sum[i]);
        for(res i=1;i<=n;i++){
            if(sum[i]<sum[fa[i]]){puts("-1");return;}
            ans+=(sum[i]==inf?0:sum[i]-sum[fa[i]]);
        }
        printf("%lld\n",ans);
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}