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
#define index Index
vector<int> v[200005];
vector<int> Size[200005];
int sum[200005];
LL pw[200005];
LL ans=0;
const int mod=1e9+7;
const int rv=(mod+1)/2;
int n,k;
LL fra[200005];
LL inv[200005];
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
int dfs(int x,int f){
    sum[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            Size[x].pb(dfs(it,x));
            sum[x]+=Size[x].back();
        }
    }
    Size[x].pb(n-sum[x]);
    LL res=C(n,k);
    for(auto it:Size[x]){
        res-=C(it,k);
        res%=mod;
        res=res+mod;
        res%=mod;
    }
    ans+=res*n;
    ans%=mod;
    res=0;
    for(auto it:Size[x]){
        res+=C(it,k);
        res%=mod;
    }
    for(auto it:Size[x]){
        ans+=(C(n-it,k)-res+C(it,k))*it%mod*(n-it)%mod;
        ans%=mod;
        ans+=mod;
        ans%=mod;
    }
 //   printf("%d %lld\n",x,ans);
    return sum[x];
}
void solve(){
    scanf("%d %d",&n,&k);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    pw[0]=1;
    inv[0]=1;
    fra[0]=1;
    for(int i = 1;i<=n;i++){
       // pw[i]=pw[i-1]*2%mod;
        //inv[i]=inv[i-1]*rv%mod;
        fra[i]=fra[i-1]*i%mod;
    }
    inv[n]=f_pow(fra[n],mod-2);
    for(int i = n-1;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    
    dfs(1,0);
    printf("%lld\n",ans);
}

int main(){
    srand(time(NULL));
    int t=1;0000;
  //  scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}