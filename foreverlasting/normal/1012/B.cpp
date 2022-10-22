//2018.12.10 by ljz
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
    int fa[N<<1],n,m,q;
    inline int find(res x){
        while(x!=fa[x])x=fa[x]=fa[fa[x]];
        return x;
    }
    int ans;
    inline void MAIN(){
        n=read(),m=read(),q=read();
        for(res i=1;i<=n+m;i++)fa[i]=i;
        for(res i=1;i<=q;i++){
            res x=read(),y=read()+n;
            res fx=find(x),fy=find(y);
            if(fx!=fy)fa[fx]=fy;
        }
        for(res i=1;i<=n+m;i++)if(fa[i]==i)ans++;
        printf("%d\n",ans-1);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}