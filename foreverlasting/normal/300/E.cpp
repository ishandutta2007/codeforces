//2019.3.4 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
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
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int N=1e6+10;
const int A=1e7+10;
#define RG register
namespace MAIN{
    int k;
    int a[N];
    int prim[A/10],tot,mn[A];
    LL buc[A];
    inline void pre(){
        mn[1]=1;
        for(res i=2;i<=A-10;i++){
            if(!mn[i])prim[++tot]=i,mn[i]=i;
            for(res j=1;j<=tot&&prim[j]*i<=A-10;j++){
                mn[prim[j]*i]=prim[j];
                if(i%prim[j]==0)break;
            }
        }
    }
    int mxa;
    inline bool check(RG LL lim,const RG LL &num,const res &p){
        RG LL ret=0;
        while(lim){
            ret+=lim/p,lim/=p;
            if(ret>=num)return 1;
        }
        return 0;
    }
    LL sum;
    inline void MAIN(){
        pre(),k=read();
        for(res i=1;i<=k;i++)a[i]=read(),mxa=_max(mxa,a[i]),buc[a[i]]++,sum+=a[i];
        for(res i=mxa-1;i>1;i--)buc[i]+=buc[i+1];
        for(res i=mxa;i>1;i--){
            if(mn[i]==i)continue;
            RG LL op=buc[i];
            buc[i]=0,buc[mn[i]]+=op,buc[i/mn[i]]+=op;
        }
        RG LL ans=1;
        for(res j=1;j<=tot;j++){
            if(!buc[prim[j]])continue;
            RG LL l=1,r=sum,ret=-1;
            while(l<=r){
                RG LL mid=(l+r)>>1;
                if(check(mid,buc[prim[j]],prim[j]))r=mid-1,ret=mid;
                else l=mid+1;
            }
            ans=max(ans,ret);
        }
        printf("%lld\n",ans);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}