//2018.9.21 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register LL
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline LL read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline LL _abs(const res &x){
    return x>0?x:-x;
}
inline LL _max(const res &x,const res &y){
    return x>y?x:y;
}
inline LL _min(const res &x,const res &y){
    return x<y?x:y;
}
const LL N=1e5+10;
namespace MAIN{
    LL n,d,b;
    LL a[N],cnt1,cnt2;
    LL sum[N];
    inline void MAIN(){
        n=read(),d=read(),b=read();
        for(res i=1;i<=n;i++)a[i]=read(),sum[i]=sum[i-1]+a[i];
        for(res i=1;i<=n/2;i++){
            res x=sum[_min(n,i*(d+1))]-b*cnt1;
            if(x>=b)cnt1++;
            x=sum[n]-sum[_max(0,n-i*(d+1))]-b*cnt2;
            if(x>=b)cnt2++;
        }
        printf("%lld\n",n/2-_min(cnt1,cnt2));
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}