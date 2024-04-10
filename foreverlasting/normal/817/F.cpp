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
    struct Q{
        LL l,r;
        int opt;
        Q() {}
        Q(LL l,LL r,res opt):l(l),r(r),opt(opt) {}
    }q[N];
    int ner[N<<4][2],rev[N<<4],L[N<<4],laz[N<<4];
    inline void pushup(const res &rt){
        ner[rt][0]=_min(ner[rt<<1][0],ner[rt<<1|1][0]);
        ner[rt][1]=_min(ner[rt<<1][1],ner[rt<<1|1][1]);
    }
    void build(const res &rt,const res &l,const res &r){
        L[rt]=l,laz[rt]=-1;
        if(l==r){ner[rt][0]=l,ner[rt][1]=inf;return;}
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    inline void change(const res &rt,const res &va,const res &flag){
        if(!flag)ner[rt][va]=L[rt],ner[rt][va^1]=inf,laz[rt]=va,rev[rt]=0;
        else _swap(ner[rt][0],ner[rt][1]),rev[rt]^=1;
    }
    inline void pushdown(const res &rt){
        if(laz[rt]!=-1)change(rt<<1,laz[rt],0),change(rt<<1|1,laz[rt],0),laz[rt]=-1;
        if(rev[rt])change(rt<<1,0,1),change(rt<<1|1,0,1),rev[rt]=0;
    }
    void update(const res &rt,const res &l,const res &r,const res &L,const res &R,const res &va){
        if(L<=l&&r<=R){change(rt,va,0);return;}
        pushdown(rt);
        res mid=(l+r)>>1;
        if(L<=mid)update(rt<<1,l,mid,L,R,va);
        if(R>mid)update(rt<<1|1,mid+1,r,L,R,va);
        pushup(rt);
    }
    void reversed(const res &rt,const res &l,const res &r,const res &L,const res &R){
        if(L<=l&&r<=R){change(rt,0,1);return;}
        pushdown(rt);
        res mid=(l+r)>>1;
        if(L<=mid)reversed(rt<<1,l,mid,L,R);
        if(R>mid)reversed(rt<<1|1,mid+1,r,L,R);
        pushup(rt);
    }
    int Max;
    LL b[N<<2];
    int bx;
    int n;
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++){
        	res opt=read();
        	LL l,r;
        	scanf("%lld%lld",&l,&r);
        	q[i]=Q(l,r,opt);
        	if(l>1)b[++bx]=l-1;
        	b[++bx]=l,b[++bx]=r,b[++bx]=r+1;
        }
        b[++bx]=1;
        sort(b+1,b+bx+1);
        Max=unique(b+1,b+bx+1)-b-1;
        for(res i=1;i<=n;i++)q[i].l=lower_bound(b+1,b+Max+1,q[i].l)-b,q[i].r=lower_bound(b+1,b+Max+1,q[i].r)-b;
    	build(1,1,Max);
    	for(res i=1;i<=n;i++){
    		if(q[i].opt==1){
    			update(1,1,Max,q[i].l,q[i].r,1);
    			printf("%lld\n",b[ner[1][0]]);
            }
            else if(q[i].opt==2){
                update(1,1,Max,q[i].l,q[i].r,0);
                printf("%lld\n",b[ner[1][0]]);
            }
            else {
                reversed(1,1,Max,q[i].l,q[i].r);
                printf("%lld\n",b[ner[1][0]]);
            }
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}