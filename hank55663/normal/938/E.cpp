#pragma GCC optimize("Ofast") 
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
int a[1000005];
int mod=1e9+7;
LL fra[1000005];
LL f_pow(int a,LL b){
    LL res=1,temp=a;
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
    fra[0]=1;
    for(int i=1;i<=n;i++){
        fra[i]=fra[i-1]*i%mod;
    }
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    sort(a,a+n);
    int l=0;
    LL ans=0;
    for(int i=0;i<n;i++){
        while(a[l]<a[i])
        l++;
        if(a[i]!=a[n-1]){
            ans+=a[i]*fra[n]%mod*fra[n-l-1]%mod*f_pow(fra[n-l],mod-2)%mod;
            ans%=mod;
        }
    }
    printf("%lld\n",ans);
}