#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<double,null_type,less<double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
#define MXN 3000
int inv[100005];
int prime[100005];
int mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=(a%mod+mod)%mod;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    fill(prime,prime+100005,1);
    fill(inv,inv+100005,-1);
    for(int i = 2;i<100005;i++){
        if(prime[i])
        for(int j = i;j<100005;j+=i){
            prime[j]=0;
          
            if(j/i%i==0){
            inv[j]=0;
            }
            else
            {
                inv[j]*=-1;
            }
        }
    }
    LL m;
    scanf("%lld",&m);
    LL ans = f_pow(m,mod-2);
    for(int i = 2;i<=m;i++){
        LL x=m/i*f_pow(m,mod-2)%mod;
      //  printf("%lld %lld\n",ans,x);
        ans += (x+x*f_pow(1-x,mod-2)%mod)*inv[i];
      //  printf("%d\n",i);
      //  printf("%lld\n",ans);
        ans = (ans %mod+mod)%mod;
    }
    
    printf("%lld\n",ans);
}