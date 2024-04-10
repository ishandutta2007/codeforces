//2019.2.15 by ljz
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
const int kcz=1e9+7;
const int INV=500000004;
const int N=20;
namespace MAIN{
    int n,ans;
    inline void add(res &x,const res &y){
        x+=y,x>=kcz?x-=kcz:1,x<0?x+=kcz:1;
    }
    inline int Add(const res &x,const res &y){
        return x+y>=kcz?x+y-kcz:x+y;
    }
    inline void FWT_xor(res *A,const res &type,const res &lim){
        for(res mid=1;mid<lim;mid<<=1)
            for(res j=0;j<lim;j+=mid<<1)
                for(res k=0;k<mid;k++){
                    res X=A[j+k],Y=A[j+mid+k];
                    A[j+k]=Add(X,Y),A[j+mid+k]=Add(X,kcz-Y);
                    if(type==-1)A[j+k]=1LL*A[j+k]*INV%kcz,A[j+mid+k]=1LL*A[j+mid+k]*INV%kcz;
                }
    }
    char str[(1<<N)+10];
    int pw[N+10],num[(1<<N)+10],a[(1<<N)+10];
    inline void MAIN(){
        n=read();
        scanf("%s",str),pw[0]=1;
        for(res i=0;i<1<<n;i++)a[i]=str[i]-'0',num[i]=num[i>>1]+(i&1);
        for(res i=1;i<=n;i++)pw[i]=pw[i-1]<<1;
        FWT_xor(a,1,1<<n);
        for(res i=0;i<1<<n;i++)a[i]=1LL*a[i]*a[i]%kcz;
        FWT_xor(a,-1,1<<n);
        for(res i=0;i<1<<n;i++)add(ans,1LL*a[i]*pw[n-num[i]]%kcz);
        printf("%lld\n",1LL*ans*3%kcz);
    }
}
int main(){
//    freopen("flow.in","r",stdin);
//    freopen("flow.out","w",stdout);
    MAIN::MAIN();
    return 0;
}