//2019.2.20 by ljz
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
const int N=4e3;
const int M=2e4;
namespace MAIN {
    int n,p;
    typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
    vector<Pair> T[M+10];
#define pb push_back
    struct P{
        int dp[N+10];
    }a[N*2+10];
    int cnt;
    int L[M+10],R[M+10];
    inline void operator +=(P &a,const Pair &x){
        for(res i=N;i>=x.fi;i--)a.dp[i]=_max(a.dp[i],a.dp[i-x.fi]+x.se);
    }
    inline void MAIN(){
        n=read(),p=read();
        for(res i=1;i<=n;i++){
            res c=read(),h=read(),t=read();
            T[t].pb(mp(c,h));
        }
        for(res i=1;i<=M;i+=p){
            for(res j=0;j<p&&i+j<=M;j++){
                if(j)R[i+j]=R[i+j-1];
                if(T[i+j].size()){
                    a[++cnt]=a[R[i+j]],R[i+j]=cnt;
                    for(res k=0,sz=T[i+j].size();k<sz;k++)a[cnt]+=T[i+j][k];
                }
            }
            for(res j=1;j<p&&i-j>0;j++){
                if(j>1)L[i-j]=L[i-j+1];
                if(T[i-j].size()){
                    a[++cnt]=a[L[i-j]],L[i-j]=cnt;
                    for(res k=0,sz=T[i-j].size();k<sz;k++)a[cnt]+=T[i-j][k];
                }
            }
        }
        res Q=read();
        while(Q--){
            res A=read(),B=read(),ans=0;
            for(res i=0;i<=B;i++)ans=_max(ans,a[A-p+1>0?L[A-p+1]:0].dp[i]+a[R[A]].dp[B-i]);
            printf("%d\n",ans);
        }
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}