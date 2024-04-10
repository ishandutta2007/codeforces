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
const int mod=1e9+7;
const int inv=(mod+1)/2;
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    LL ans=1,sub=1;
    LL sum1=0,sum2=0;
    LL tot[33];
    fill(tot,tot+33,1);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        ans=ans*2%mod;
        if(a[i]%2==0){
            for(int j = 1;j<=30;j++){
                if(a[i]%(1<<j)!=0){
                    tot[j-1]*=2;
                    tot[j-1]%=mod;
                    //printf("%d\n",j-1);
                    break;
                }
            }
            sub=sub*2%mod;
        }
    }
    ans=((ans-1-sub+1)%mod+mod)%mod;
  //  printf("%lld %lld\n",ans,sub);
    LL sum=0;
    for(int i = 1;i<=30;i++){
        sum=sum*tot[i]%mod;
        if(tot[i]!=1){
            
            tot[i]=tot[i]*inv%mod;
            //printf("%lld\n",tot[i]);
            sum=(sum+tot[i]-1)%mod;
          //  printf("%lld\n",sum);
        }
    }
   // sum=(sum-1);
   // if(sum2==0)tot1=0;
   // printf("%lld %lld\n",tot1,tot2);
    printf("%lld\n",((ans+sum)%mod+mod)%mod);
}

int main(){

    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/