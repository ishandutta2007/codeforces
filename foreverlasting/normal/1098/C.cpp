//2019.1.26 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register LL
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
inline LL read() {
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
inline LL _abs(const res &x) {
    return x>0?x:-x;
}
inline LL _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline LL _min(const res &x,const res &y) {
    return x<y?x:y;
}
const LL N=1e6+10;
namespace MAIN {
    LL n;
    LL s;
    LL cnt[N],dep[N];
    inline bool check(const res &lim){
        memset(dep,0,sizeof(dep)),memset(cnt,0,sizeof(cnt));
        res depx=1;
        LL t=lim,num=s-n;
        for(res i=2;i<=n;depx++,t*=lim)
            for(res j=1;j<=t&&i<=n;i++,j++)cnt[depx]++,dep[i]=depx,num-=depx;
        return num>=0;
    }
    inline void MAIN(){
        n=read(),scanf("%lld",&s);
        if(1LL*n*(n+1)/2<s||2*n-1>s){puts("No");return;}
        puts("Yes");
        res l=1,r=n,ret=0;
        while(l<=r){
            res mid=(l+r)>>1;
            if(check(mid))r=mid-1,ret=mid;
            else l=mid+1;
        }
        memset(dep,0,sizeof(dep)),memset(cnt,0,sizeof(cnt));
        res depx=1;
        LL t=ret,num=s-n;
        for(res i=2;i<=n;depx++,t*=ret)
            for(res j=1;j<=t&&i<=n;i++,j++)cnt[depx]++,dep[i]=depx,num-=depx;
//        for(res i=1;i<=n;i++)printf("%lld ",dep[i]);
//        puts("");
        res pos=n;
        depx--;
        while(num){
            while(cnt[dep[pos]]==1)pos--;
            depx++;
            res tmp=_min(num,depx-dep[pos]);
            cnt[dep[pos]]--,dep[pos]+=tmp,cnt[dep[pos]]++,num-=tmp,pos--;;
        }
        sort(dep+2,dep+n+1);
//        for(res i=1;i<=n;i++)printf("%lld ",dep[i]);
//        puts("");
        memset(cnt,0,sizeof(cnt));
        pos=1;
        for(res i=2;i<=n;i++) {
            while(dep[pos]!=dep[i]-1||cnt[pos]==ret)pos++;
            printf("%lld ",pos),cnt[pos]++;
        }
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}