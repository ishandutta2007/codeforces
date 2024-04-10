//2018.12.26 by ljz
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
    int n,m;
    int a[35+10];
    int sum0[(1<<18)+10],sum1[(1<<18)+10],s0,s1;
    inline int Add(const res &x,const res &y){
        return x+y>=m?x+y-m:x+y;
    }
    void dfs(const res &x,const res &Sum){
        if(x==n/2){sum0[++s0]=Sum;return;}
        dfs(x+1,Sum),dfs(x+1,Add(Sum,a[x+1]));
    }
    void Dfs(const res &x,const res &Sum){
        if(x==n){sum1[++s1]=Sum;return;}
        Dfs(x+1,Sum),Dfs(x+1,Add(Sum,a[x+1]));
    }
    int ans;
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=n;i++)a[i]=read()%m;
        if(n==1){printf("%d\n",a[1]);return;}
        dfs(0,0),Dfs(n/2,0);
        sort(sum0+1,sum0+s0+1),s0=unique(sum0+1,sum0+s0+1)-sum0-1;
        sort(sum1+1,sum1+s1+1),s1=unique(sum1+1,sum1+s1+1)-sum1-1;
        for(res i=1,j=s1;i<=s0;i++){
            while(sum0[i]+sum1[j]>=m)j--;
            ans=_max(sum0[i]+sum1[j],ans);
        }
        printf("%d\n",_max(ans,Add(sum0[s0],sum1[s1])));
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}