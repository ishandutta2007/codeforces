#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL dp[3000005][3];
LL fra[3000015];
LL inv[3000015];
const int mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL C(int a,int b){
    if(a<b)return 0;
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(){
    fra[0]=1;
    for(int i = 1;i<=3000010;i++){
        fra[i]=fra[i-1]*i%mod;
    }
    inv[3000010]=f_pow(fra[3000010],mod-2);
    for(int i = 3000009;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    int n,q;
    scanf("%d %d",&n,&q);
    dp[0][0]=dp[0][1]=dp[0][2]=n;
    int inv3=f_pow(3,mod-2);
    for(int i = 1;i<=3*n;i++){
        dp[i][0]=(((C(3*n,i+1)-dp[i-1][1]-dp[i-1][0]-dp[i-1][0])%mod+mod)%mod)*inv3%mod;
        dp[i][1]=(dp[i-1][0]+dp[i][0])%mod;
        dp[i][2]=(dp[i-1][1]+dp[i][1])%mod;
    }
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%lld\n",(dp[x][0]+C(3*n,x))%mod);
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

a b c
b c
ab ac bc
*/