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
const int N=5e5+10;
namespace MAIN{
    int n;
    int a[N];
    struct LB{
        int a[20+10],p[20+10];
        LB() {for(res i=0;i<=20;i++)a[i]=0,p[i]=inf;}
        inline void insert(res x,res id){
            for(res i=20;~i;i--){
                if(x&(1<<i)){
                    if(!a[i]){a[i]=x,p[i]=id;return;}
                    if(p[i]<id)_swap(p[i],id),_swap(a[i],x);
                    x^=a[i];
                }
            }
        }
        inline int query(const res &id){
            res ret=0;
            for(res i=20;~i;i--)if(p[i]>=id)ret=_max(ret,ret^a[i]);
            return ret;
        }
    }T;
    struct Que{
        int l,r,id;
        Que() {}
        Que(res l,res r,res id):l(l),r(r),id(id) {}
        inline bool operator < (const Que &b) const {
            return r<b.r;
        }
    }que[N];
    int ans[N];
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)a[i]=read();
        res q=read();
        for(res i=1;i<=q;i++){
            res l=read(),r=read();
            que[i]=Que(l,r,i);
        }
        sort(que+1,que+q+1);
        for(res i=1,r=1;i<=q;i++){
            while(que[i].r>=r)T.insert(a[r],r),r++;
            ans[que[i].id]=T.query(que[i].l);
        }
        for(res i=1;i<=q;i++)printf("%d\n",ans[i]);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}