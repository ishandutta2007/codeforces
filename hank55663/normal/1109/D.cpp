#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int mod=1e9+7;
LL f_pow(LL a,LL b){
    b=(b+mod-1)%(mod-1);
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL fra[1000005];
LL inv[1000005];
void build(){
    fra[0]=1;
    for(int i=1;i<=1e6;i++){
        fra[i]=fra[i-1]*i%mod;
    }
    inv[1000000]=f_pow(fra[1000000],mod-2);
    for(int i=999999;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
LL C(LL a,LL b){
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    int n,m,a,b;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    LL ans=0;
    build();
    for(int i=1;i<=n-1&&i<=m;i++){
        ans+=f_pow(m,n-1-i)
        *C(n-2,i-1)%mod*fra[i-1]%mod
        *(i+1)%mod*f_pow(n,n-i-2)%mod
        *C(m-1,i-1)%mod;
        ans%=mod;
    }
    printf("%lld\n",ans);
}
/*

i f f x f l b
*/