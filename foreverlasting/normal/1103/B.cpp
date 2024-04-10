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
namespace MAIN {
    char str[10];
    int x,y;
    inline void MAIN(){
        while(scanf("%s",str)){
            if(str[0]=='e')break;
            if(str[0]=='m')break;
            x=0,y=1;
            while(233){
                printf("? %d %d\n",x,y),fflush(stdout);
                scanf("%s",str);
                if(str[0]!='y')break;
                x=y,y=2*y+1;
            }
            if(str[0]=='e')break;
            res l=x+1,r=y,ret=y;
            while(l<=r){
                res mid=(l+r)>>1;
                printf("? %d %d\n",x,mid),fflush(stdout);
                scanf("%s",str);
                if(str[0]=='e')break;
                if(str[0]=='x')r=mid-1,ret=mid;
                else l=mid+1;
            }
            printf("! %d\n",ret),fflush(stdout);
        }
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}