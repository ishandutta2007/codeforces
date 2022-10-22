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
const int N=1e2+10;
namespace MAIN{
    int n;
    int a[N],sum;
    char str[N];
    inline void MAIN(){
        n=read();
        scanf("%s",str+1);
        for(res i=1;i<=n;i++)a[i]=str[i]-'0',sum+=a[i];
        a[n+1]=inf;
        if(!sum){puts("YES");return;}
        for(res i=1;i<=sum/2;i++){
            if(sum%i)continue;
            bool jud=0;
            for(res j=1;j<=n;){
                res ret=0;
                while(ret+a[j]<=i&&j<=n)ret+=a[j++];
                if(ret!=i){jud=1;break;}
            }
            if(!jud){puts("YES");return;}
        }
        puts("NO");
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}