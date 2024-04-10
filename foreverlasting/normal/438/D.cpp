//2018.10.24 by ljz
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
const int N=1e5+10;
namespace MAIN{
    int n,m;
    LL sum[N<<2];
    int mx[N<<2];
    inline void pushup(const res &rt){
        sum[rt]=sum[rt<<1]+sum[rt<<1|1];
        mx[rt]=_max(mx[rt<<1],mx[rt<<1|1]);
    }
    void build(const res &rt,const res &l,const res &r){
        if(l==r){mx[rt]=sum[rt]=read();return;}
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    void modify(const res &rt,const res &l,const res &r,const res &L,const res &R,const res &kcz){
        if(mx[rt]<kcz)return;
        if(l==r){sum[rt]%=kcz,mx[rt]%=kcz;return;}
        res mid=(l+r)>>1;
        if(L<=mid)modify(rt<<1,l,mid,L,R,kcz);
        if(R>mid)modify(rt<<1|1,mid+1,r,L,R,kcz);
        pushup(rt);
    }
    LL query(const res &rt,const res &l,const res &r,const res &L,const res &R){
        if(L<=l&&r<=R)return sum[rt];
        res mid=(l+r)>>1;
        LL ret=0;
        if(L<=mid)ret+=query(rt<<1,l,mid,L,R);
        if(R>mid)ret+=query(rt<<1|1,mid+1,r,L,R);
        return ret;
    }
    void update(const res &rt,const res &l,const res &r,const res &p,const res &va){
        if(l==r){sum[rt]=mx[rt]=va;return;}
        res mid=(l+r)>>1;
        if(p<=mid)update(rt<<1,l,mid,p,va);
        else update(rt<<1|1,mid+1,r,p,va);
        pushup(rt);
    }
    inline void MAIN(){
        n=read(),m=read();
        build(1,1,n);
        while(m--){
            res opt=read();
            if(opt==1){
                res l=read(),r=read();
                printf("%lld\n",query(1,1,n,l,r));
            }
            else if(opt==2){
                res l=read(),r=read(),kcz=read();
                modify(1,1,n,l,r,kcz);
            }
            else {
                res k=read(),x=read();
                update(1,1,n,k,x);
            }
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}