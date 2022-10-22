//2018.9.7 by ljz
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
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
const int N=1e5+10;
namespace MAIN {
    char str[N];
    int n, m;
    LL k;
    LL ans;

    inline void MAIN() {
        n = read(), m = read();
        scanf("%s", str + 1);
        ans = n * (m - 1);
        for (res i = 2; i <= n; i++)
            if (str[i] != str[i - 1])ans += n * (m - 1);
        k = 1;
        for (res i = 2; i <= n; i++) {
            if (k == 1) {
                if (str[i] != str[i - 1])k++;
                else continue;
            } else {
                if (str[i] == str[i - 2])k++;
                else {
                    ans -= (k - 1) * k / 2;
                    k = 1;
                    if (str[i] != str[i - 1])k = 2;
                }
            }
        }
        ans -= (k - 1) * k / 2;
        cout<<ans;
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}