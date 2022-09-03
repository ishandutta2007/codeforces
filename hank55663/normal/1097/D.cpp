
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
int mod=1e9+7;
LL f_pow(int a,int b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    LL n,K;
    scanf("%lld %lld",&n,&K);
    vector<LL> v;
    LL inv[60];
    for(int i=1;i<60;i++){
        inv[i]=f_pow(i,mod-2);
    }
    LL cnt[60][60];
    for(int i=1;i<60;i++){
        MEM(cnt[i]);
        cnt[i][i]=1;
        for(int j=0;j<K;j++){
            int temp[60];
            for(int k=0;k<=i;k++)
            temp[k]=cnt[i][k];
            MEM(cnt[i]);
            LL tot=0;
            for(int k=i;k>=0;k--){
                tot+=inv[k+1]*temp[k]%mod;
                tot%=mod;
                cnt[i][k]=tot;
            }
        }
    }
    LL ans=1;
    for(LL i=2;i*i<=n;i++){
        int tot=0;
        while(n%i==0){
            n/=i;
            tot++;
        }
        if(tot){
            LL now=1;
            LL sum=0;
            for(int j=0;j<=tot;j++){
                sum+=now*cnt[tot][j]%mod;
                sum%=mod;
                now*=i;
                now%=mod;
            }
           // printf("%lld\n",sum);
            ans*=sum;
            ans%=mod;
        }
    }
    if(n){
        LL now=1,sum=0;
        int tot=1;
        for(int j=0;j<=tot;j++){
                sum+=now*cnt[tot][j]%mod;
                sum%=mod;
                now*=n;
                now%=mod;
            }
           // printf("%lld\n",sum);
            ans*=sum;
            ans%=mod;
    }
    printf("%lld\n",ans);
}