//2018.10.28 by ljz
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
const int N=2e5+10;
namespace MAIN{
    struct P{
        int u,v,w;
        P() {}
        P(res u,res v,res w):u(u),v(v),w(w) {}
        inline bool operator < (const P &b) const {
            return w>b.w;
        }
    }a[N];
    int fa[N],sz[N];
    inline int find(res x){
        while(x!=fa[x])x=fa[x]=fa[fa[x]];
        return x;
    }
    int n,m;
    int ans;
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=m;i++){
            res u=read(),v=read(),w=read();
            a[i]=P(u,v,w);
        }
        sort(a+1,a+m+1);
        for(res i=1;i<=n;i++)fa[i]=i,sz[i]=1;
        for(res i=1;i<=m;i++){
            res fu=find(a[i].u),fv=find(a[i].v);
            if(fu!=fv&&(sz[fu]||sz[fv]))ans+=a[i].w,fa[fv]=fu,sz[fu]&=sz[fv];
            else if(fu==fv&&sz[fu])sz[fu]=0,ans+=a[i].w;
        }
        printf("%d\n",ans);
    }
}
int main(){
    srand((unsigned)time(NULL));
    MAIN::MAIN();
    return 0;
}