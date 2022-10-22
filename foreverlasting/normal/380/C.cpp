//2019.4.8 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
#define RG register
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void swap(res &x,res &y){
    x^=y^=x^=y;
}
const int N=1e6+10;
namespace MAIN{
    char str[N];
    int q,n;
    struct P{
        int sum,ln,rn;
        P() {}
        P(res sum,res ln,res rn):sum(sum),ln(ln),rn(rn) {}
    }tr[N<<2];
    inline P operator + (P x,P y){
        RG P ret=P(0,0,0);
        res lim=min(x.ln,y.rn);
        x.ln-=lim,y.rn-=lim,ret.sum=x.sum+y.sum+lim,ret.ln=x.ln+y.ln,ret.rn=x.rn+y.rn;
        return ret;
    }
    void build(res rt,res l,res r){
        if(l==r){str[l]=='('?tr[rt].ln++:tr[rt].rn++;return;}
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
        tr[rt]=tr[rt<<1]+tr[rt<<1|1];
    }
    P query(res rt,res l,res r,res L,res R){
        if(L<=l&&r<=R)return tr[rt];
        res mid=(l+r)>>1;
        RG P ret=P(0,0,0);
        if(L<=mid)ret=query(rt<<1,l,mid,L,R);
        if(R>mid)ret=ret+query(rt<<1|1,mid+1,r,L,R);
        return ret;
    }
    inline void MAIN(){
        scanf("%s",str+1),q=read(),n=int(strlen(str+1)),build(1,1,n);
        while(q--){
            res l=read(),r=read();
            printf("%d\n",query(1,1,n,l,r).sum<<1);
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}