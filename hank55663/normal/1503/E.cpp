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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
//const int mod=1e9+7;
LL C[5005][5005];
const int mod=998244353;
void build(){
    for(int i = 0;i<5005;i++){
        C[i][0]=C[i][i]=1;
        for(int j = 1;j<i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}
void solve(){
    build();
    int n,m;
    scanf("%d %d",&n,&m);
    LL ans=0;
    for(int i = 1;i<n;i++){
        LL sum=0;
        for(int j =1;j<m;j++){
            ans+=sum*C[n-i-1+j][n-i-1]%mod*C[n-i+m-j-1][n-i];
            sum+=C[i+j-1][i]*C[m-j+i-1][i-1];
            sum%=mod;
            ans%=mod;
       //     C[i-1]
        }
    }
    swap(n,m);
    for(int i = 1;i<n;i++){
        LL sum=0;
        for(int j =1;j<m;j++){
            ans+=sum*C[n-i-1+j][n-i-1]%mod*C[n-i+m-j-1][n-i];
            sum+=C[i+j-1][i]*C[m-j+i-1][i-1];
            sum%=mod;
            ans%=mod;
       //     C[i-1]
        }
    }
    for(int i = 1;i<n;i++){
        for(int j =1;j<m;j++){
            ans+=C[i+j-1][j]*C[i+m-j-1][i]%mod*C[n-i+j-1][n-i]%mod*C[n-i+m-j-1][n-i-1];
            ans%=mod;
        }
    }
    ans=ans*2%mod;
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}