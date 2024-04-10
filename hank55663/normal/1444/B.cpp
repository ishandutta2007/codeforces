#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL fra[300005];
LL inv[300005];
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void build(){
    fra[0]=1;
    for(int i = 1;i<=300000;i++)fra[i]=fra[i-1]*i%mod;
    inv[300000]=f_pow(fra[300000],mod-2);
    for(int i = 299999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
LL C(int a,int b){
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(){   
    build();
    int n;
    scanf("%d",&n);
    int a[300005];
    for(int i = 0;i<2*n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+2*n);
    LL ans=0;
    for(int i = 0;i<2*n;i++){
        if(i<n){
            ans-=C(2*n,n)%mod*a[i]%mod;
        }
        else{
            ans+=C(2*n,n)%mod*a[i]%mod;
        }
    }
    printf("%lld\n",(ans%mod+mod)%mod);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
11 4 12
1 1 1 1
AABB
.AB.
CCDD
.CD.
EEFF
.EF.
GGHH
.GH.
IIJJ
.IJ.
KKLL

12
0 0
0 -13
3 -13
3 -10
10 -10
10 10
-1 10
-1 13
-4 13
-4 10
-10 10
-10 0

*/