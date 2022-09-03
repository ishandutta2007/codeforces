
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
int mod=998244353;
LL inv(int x){
    LL res=1,temp=x;
    int b=mod-2;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    LL ans=1;
    for(int i=1;i<=n;i++)
    ans=ans*i%mod;
    LL res=ans;
    LL now=1;
    for(int i=2;i<n;i++){
        now=now*i%mod;
        res+=ans*inv(now)%mod*((now-1+mod)%mod)%mod;
        res%=mod;
    }
    printf("%lld\n",res);
}