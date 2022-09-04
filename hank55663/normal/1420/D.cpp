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
    for(int i = 1;i<300005;i++)fra[i]=fra[i-1]*i%mod;
    inv[300000]=f_pow(fra[300000],mod-2);
    for(int i = 299999;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
LL C(int a,int b){
    if(a<b)return 0;
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(){   
    int n,k;
    scanf("%d %d",&n,&k);
    LL ans=0;
    vector<pii> v;
    int sum=0;
    build();
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v.pb(mp(x,1));
        v.pb(mp(y+1,-1));
    }
    sort(v.begin(),v.end());
    for(auto it:v){
       
        if(it.y>0){
            ans+=C(sum,k-1);
        }
        sum+=it.y;
    }
    printf("%lld\n",ans%mod);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*


*/