
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
LL fra[100005];
LL inv[100005];
const int mod=998244353;
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
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(int T){
    map<LL,int> m1,m2;
    LL sum=0;
    int n;
    LL pre=0;
    scanf("%d",&n);
    int a[100005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        pre+=a[i];
        if(i!=n)
        m1[pre]++;
    }
    pre=0;
    for(int i = n;i>=1;i--){
        pre+=a[i];
        if(i!=1)
        m2[pre]++;
    }
    if(sum%2==1){
        LL ans=1;
        for(auto it:m1){
            LL sum2=0;
            if(it.x<=sum/2){
                int a=it.y,b=m2[it.x];
                // printf("%d %d %d\n",a,b,it.x);
                for(int i = 0;i<=a&&i<=b;i++){
                     
                    sum2+=C(a,i)*C(b,i)%mod;
                    sum2%=mod;
                }
                ans=ans*sum2%mod;
            }
            else break;
        
        }
        printf("%lld\n",ans);
    }
    else{
         LL ans=1;
        for(auto it:m1){
            LL sum2=0;
            if(it.x<sum/2){
                int a=it.y,b=m2[it.x];
                for(int i = 0;i<=a&&i<=b;i++){
                  
                    sum2+=C(a,i)*C(b,i)%mod;
                    sum2%=mod;
                }
                ans=ans*sum2%mod;
            }
            else break;
        }
        LL a=m1[sum/2];
        LL sum=0;
        for(int i =0;i<=a;i++)sum+=C(a,i);
        sum%=mod;
        ans=ans*sum%mod;
        printf("%lld\n",ans);
    }

}
int main(){
    int t=1;
    scanf("%d",&t);
    fra[0]=1;
    for(int i =1;i<=100000;i++)fra[i]=fra[i-1]*i%mod;
    inv[100000]=f_pow(fra[100000],mod-2);
    for(int i = 100000;i>=1;i--)inv[i-1]=inv[i]*(i)%mod;
    for(int T=1;T<=t;T++){
       // cerr<<T<<endl;
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/