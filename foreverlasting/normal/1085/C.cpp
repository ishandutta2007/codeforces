//2019.1.26 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
inline int read() {
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')w=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y) {
    x^=y^=x^=y;
}
inline int _abs(const res &x) {
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
namespace MAIN {
    struct P{
        int x,y;
        P() {}
        P(res x,res y):x(x),y(y) {}
        inline bool operator < (const P &b) const {
            return x!=b.x?x<b.x:y<b.y;
        }
    }a[4];
    bool vis[1000+10][1000+10];
    vector<P> vec;
#define pb push_back
    inline void MAIN(){
        for(res i=1;i<=3;i++)a[i].x=read(),a[i].y=read();
        sort(a+1,a+3+1);
        for(res i=a[1].x;i<=a[2].x;i++)vis[i][a[1].y]=1;
        for(res i=_min(a[1].y,a[2].y);i<=_max(a[1].y,a[2].y);i++)vis[a[2].x][i]=1;
        for(res i=a[2].x;i<=a[3].x;i++)vis[i][a[3].y]=1;
        for(res i=_min(a[2].y,a[3].y);i<=_max(a[2].y,a[3].y);i++)vis[a[2].x][i]=1;
        for(res i=0;i<=1000;i++)
            for(res j=0;j<=1000;j++)if(vis[i][j])vec.pb(P(i,j));
        printf("%d\n",vec.size());
        for(res i=0,sz=vec.size();i<sz;i++)printf("%d %d\n",vec[i].x,vec[i].y);
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}