//2019.2.27 by ljz
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
const int N=3e5+10;
const int kcz=1e9+9;
namespace MAIN{
    int n,m;
    int fib[N],pre[N],suf[N];
    inline int Add(const res &x,const res &y){
        return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
    }
    inline void add(res &x,const res &y){
        x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
    }
    inline int mul(const res &x,const res &y){
        return 1LL*x*y%kcz;
    }
    inline void init(){
        fib[1]=fib[2]=pre[1]=suf[1]=1,pre[2]=2,suf[2]=kcz-1;
        for(res i=3;i<=n+1;i++)fib[i]=Add(fib[i-1],fib[i-2]),pre[i]=Add(pre[i-1],fib[i]),suf[i]=(i&1?fib[i]:kcz-fib[i]);
    }
    int sum[N<<2],laz[N<<2],tag[N<<2],ls[N<<2],rs[N<<2];
    inline void pushup(const res &rt){
        sum[rt]=Add(sum[rt<<1],sum[rt<<1|1]);
    }
    void build(const res &rt,const res &l,const res &r){
        ls[rt]=l,rs[rt]=r;
        if(l==r){sum[rt]=read();return;}
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    inline void change(const res &rt,const res &va,const res &Va){
        add(laz[rt],va),add(tag[rt],Va),add(sum[rt],Add(mul(Add(pre[rs[rt]+1],-pre[ls[rt]]),va),mul(Add(pre[rs[rt]],-pre[ls[rt]-1]),Va)));
    }
    inline void pushdown(const res &rt){
        change(rt<<1,laz[rt],tag[rt]),change(rt<<1|1,laz[rt],tag[rt]),laz[rt]=tag[rt]=0;
    }
    void modify(const res &rt,const res &l,const res &r,const res &L,const res &R,const res &va,const res &Va){
        if(L<=l&&r<=R){change(rt,va,Va);return;}
        pushdown(rt);
        res mid=(l+r)>>1;
        if(L<=mid)modify(rt<<1,l,mid,L,R,va,Va);
        if(R>mid)modify(rt<<1|1,mid+1,r,L,R,va,Va);
        pushup(rt);
    }
    int query(const res &rt,const res &l,const res &r,const res &L,const res &R){
        if(L<=l&&r<=R)return sum[rt];
        pushdown(rt);
        res mid=(l+r)>>1,ret=0;
        if(L<=mid)add(ret,query(rt<<1,l,mid,L,R));
        if(R>mid)add(ret,query(rt<<1|1,mid+1,r,L,R));
        return ret;
    }
    inline void MAIN(){
        n=read(),m=read(),init(),build(1,1,n);
        while(m--){
            res opt=read(),l=read(),r=read();
            if(opt==1)modify(1,1,n,l,r,suf[l-1],suf[l]);
            else printf("%d\n",query(1,1,n,l,r));
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}