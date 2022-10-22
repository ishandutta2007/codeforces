//2018.9.27 by ljz
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
#define pi acos(-1)
#define db double
const int N=1e5+10;
namespace MAIN{
    struct P{
        db x,y;
    }pos[N],o;
    inline db get_dis(const P &a,const P &b){
        return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    }
    int n;
    inline db getdis(const P &a,const P &b,const P &c){
        db k1=get_dis(a,b),k2=get_dis(a,c),k3=get_dis(b,c);
        if(k1>=k2+k3)return k2;
        if(k2>=k1+k3)return k1;
        db d=fabs((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));
        return d*d/k3;
    }
#define INF 1.0/0.0
    db Max=0,Min=INF;
    inline void MAIN(){
        n=read();
        scanf("%lf%lf",&o.x,&o.y);
        for(res i=0;i<n;i++){
            scanf("%lf%lf",&pos[i].x,&pos[i].y);
            Max=max(Max,get_dis(o,pos[i]));
        }
        for(res i=0;i<n;i++){
            res j=(i+1)%n;
            Min=min(Min,getdis(o,pos[i],pos[j]));
        }
        printf("%.7lf\n",(Max-Min)*pi);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}