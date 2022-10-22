//2019.1.25 by ljz
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
const int N=1e5+10;
namespace MAIN {
    int n,s;
    int du[N],cnt;
    inline void MAIN(){
        n=read(),s=read();
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            du[u]++,du[v]++;
        }
        for(res i=1;i<=n;i++)if(du[i]==1)cnt++;
        printf("%.7lf\n",2.0*s/cnt);
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}