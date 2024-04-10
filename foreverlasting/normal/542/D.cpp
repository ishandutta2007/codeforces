//2019.3.2 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
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
const int N=1e6+10;
#define RG register
namespace MAIN {
    LL A;
    LL dp[N];
    map<LL,int> mp;
    LL a[N<<1];
    int tot;
    int prim[N],Tot;
    bool vis[N];
    inline void pre(){
        res lim=int(sqrt(A));
        for(res i=2;i<=lim;i++){
            if(!vis[i])prim[++Tot]=i;
            for(res j=1;j<=Tot&&prim[j]*i<=lim;j++){
                vis[prim[j]*i]=1;
                if(i%prim[j]==0)break;
            }
        }
    }
    vector<LL> vec[N];
#define pb push_back
    inline void MAIN(){
        cin>>A,pre();
        for(res i=1;1LL*i*i<=A;i++){
            if(A%i==0){
                a[++tot]=i;
                if(A/i!=i)a[++tot]=A/i;
            }
        }
        sort(a+1,a+tot+1);
        for(res i=1;i<=tot;i++){
            mp[a[i]]=i;
            if(a[i]<=2)continue;
            RG LL tmp=a[i]-1;
            bool flag=0,Flag=0;
            for(res j=1;j<=Tot&&prim[j]<=tmp;j++){
                if(tmp%prim[j])continue;
                while(tmp%prim[j]==0)tmp/=prim[j];
                if(tmp==1)vec[j].pb(a[i]),Flag=1;
                else flag=1;
                break;
            }
            if(!flag&&!Flag)vec[Tot+1].pb(a[i]);
        }
        dp[1]=1;
        for(res i=1;i<=Tot+1;i++){
            for(res j=tot;j;j--){
                for(res k=0,sz=vec[i].size();k<sz;k++){
                    RG LL p=vec[i][k];
                    if(a[j]%p==0)dp[j]+=dp[mp[a[j]/p]];
                }
            }
        }
        printf("%lld\n",dp[tot]);
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}