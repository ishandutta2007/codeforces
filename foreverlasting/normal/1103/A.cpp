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
const int N=1e3+10;
namespace MAIN {
    char str[N];
    bool f1,f2;
    inline void MAIN(){
        scanf("%s",str+1);
        for(res i=1,sz=strlen(str+1);i<=sz;i++){
            if(str[i]=='0'){
                if(!f1)puts("1 1"),f1=1;
                else puts("3 1"),f1=0;
            }
            else {
                if(!f2)puts("4 3"),f2=1;
                else puts("4 1"),f2=0;
            }
        }
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}