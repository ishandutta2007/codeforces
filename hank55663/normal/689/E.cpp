#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL fra[200005];
LL inv[200005];
void build(){
    fra[0]=1;
    for(int i = 1;i<200005;i++){
        fra[i]=fra[i-1]*i%mod;
    }
    inv[200000]=f_pow(fra[200000],mod-2);
    for(int i = 199999;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
LL C(int n,int k){
    if(n<k)return 0;
    return fra[n]*inv[n-k]%mod*inv[k]%mod;
}
int main(){
    build();
    int n,k;
    scanf("%d %d",&n,&k);
    map<int,int> m;
    for(int i = 0;i<n;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        m[l]++;
        m[r+1]--;
    }
    int now=0;
    int last=-2e9;
    LL ans=0;
    for(auto it:m){
        ans+=(it.x-last)*C(now,k)%mod;
        now+=it.y;
        last=it.x;
    }
    printf("%lld\n",ans%mod);
}

/*

23847657 
23458792534

102334155
111111111 
111111111
*/