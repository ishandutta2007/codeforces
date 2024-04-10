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
#define last Last
#define MXN 200005
LL pool[400005];
LL pool2[400005];
void solve(){
    LL *dp=pool+200000;
    LL *pre=pool2+200000;
    int n,mod;
    scanf("%d %d",&n,&mod);
    vector<int> v;
    for(int i = 1;i<=n;i++)v.pb(i);
    /*int ans=0;
    do{
        vector<int> v2=v;
        while(next_permutation(v2.begin(),v2.end())){
            int sum=0;
            for(int j = 0;j<n;j++){
                for(int k  =j+1;k<n;k++){
                    if(v[k]<v[j])sum++;
                    if(v2[k]<v2[j])sum--;
                }
            }
            if(sum>0)ans++;
        }
    }while(next_permutation(v.begin(),v.end()));
    printf("%d\n",ans);*/
    LL tot=1;
    for(int i = 1;i<=n;i++){
        for(int j = -199999;j<=200000;j++)pre[j]=(pre[j-1]+dp[j])%mod;
        LL sum=0;
        for(int j = 0;j<(n-i+1);j++){
            sum+=dp[190000-j]*(n-i+1-j)%mod;
            sum%=mod;
            // printf("%lld %lld\n",sum,dp[200000-j]);
        }
        for(int j = 1;j<(n-i+1);j++){
            sum+=dp[190000+j]*(n-i+1-j)%mod;
            sum%=mod;
        }
      //  printf("%lld\n",sum);
        for(int j = 190000;j>=-189999;j--){
            LL tmp=dp[j];
            dp[j]=sum;
            sum+=pre[j-1]-pre[j-(n-i+2)];
            sum-=pre[j+n-i]-pre[j-1];
            sum=(sum%mod+mod)%mod;
           // if(sum)printf("%d\n",j);

        }
        // for(int j = -10;j<=10;j++){
         //   printf("%3d ",dp[j]);
        //}
        //printf("\n");
        for(int j = 1;j<=n-i+1;j++){
            //printf("%d\n",j);
            for(int k = j+1;k<=n-i+1;k++){
              //  printf("%d\n",j-1-(k-1));
                dp[j-1-(k-1)]+=tot;
                dp[j-1-(k-1)]%=mod;
            }
        }
        tot=tot*(n-i+1)%mod;
       // for(int j = -10;j<=10;j++){
         //   printf("%3d ",dp[j]);
       // }
       // printf("\n");
    }
    LL sum=0;
    for(int j = 1;j<=200000;j++)sum+=dp[j];
    printf("%lld\n",sum%mod);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}