//2019.2.24 by ljz
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
const int N=5e3+10;
namespace MAIN{
    char str[N];
    bool dp[N];
    int n,s;
    inline void MAIN(){
        scanf("%s",str+1),n=strlen(str+1),s=log2(n);
        memset(dp,1,sizeof(dp));
        for(res i=1,len=n-(1<<s)+1;i<=len;i++){
            char ch='z';
            for(res S=0;S<(1<<s);S++)
                if(dp[S])for(res k=0;k<s;k++)dp[S|(1<<k)]=1;
            for(res S=0;S<(1<<s);S++)if(dp[S])ch=min(ch,str[i+S]);
            for(res S=0;S<(1<<s);S++)dp[S]&=(str[i+S]==ch);
            putchar(ch);
        }
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}