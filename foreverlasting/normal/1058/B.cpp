//2018.9.23 by ljz
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
namespace MAIN{
    int n,d,m;
    struct P{
        int x,y;
        P() {}
        P(res x,res y):x(x),y(y) {}
    }p[4];
    inline int dis(P a,P b,P c){
        return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
    }
    inline bool cmp(P a){
        return dis(p[0],p[1],a)*dis(p[2],p[3],a)>=0&&dis(p[1],p[2],a)*dis(p[3],p[0],a)>=0;
    }
    inline void MAIN(){
        n=read(),d=read(),m=read();
        p[0]=P(0,d),p[1]=P(d,0),p[2]=P(n,n-d),p[3]=P(n-d,n);
        while(m--){
            res x=read(),y=read();
            if(cmp(P(x,y)))puts("YES");
            else puts("NO");
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}