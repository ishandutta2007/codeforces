#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define MXN 200005
int mod=1e9+7;
LL f_pow(LL a,LL b){
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
    int a[10005];
    int inv[10005];
    for(int i = 1;i<n;i++){
        scanf("%d",&a[i]);
    //    a[i]=rand();
        inv[i]=f_pow(a[i],mod-2)%mod;
    }
    LL ans[10005];
    LL pre[10005];
    pre[0]=1;
    for(int i = 1;i<n;i++){
        pre[i]=pre[i-1]*a[i]%mod;
    }
    LL temp[10005];
    fill(ans,ans+10005,0);
    fill(temp,temp+10005,0);
    //temp[0]=1;
    for(int i = n-1;i>=0;i--){
        LL sum=1;
        LL add[10005];
        fill(add,add+10005,0);
        for(int j=0;j<=2*n-2;j++){
            add[j]+=temp[j]*inv[i+1]%mod*(a[i+1]-1)%mod;
        }
        for(int j=0;j+i<n;j++){
            temp[j]=(temp[j]+sum)%mod;
            add[j]+=sum;
            sum*=a[i+j+1];
            sum%=mod;
        }
        for(int j = 0;j<=2*n-2;j++){
            
           // printf("%lld ",add[j]);
            ans[j]+=add[j]*pre[i]%mod;
            ans[j]%=mod;
        }
       // printf("\n");
        for(int j =2*n-2;j>=2;j--){
            temp[j]=temp[j-2]*a[i]%mod*a[i]%mod;
        }
        temp[0]=temp[1]=0;
    }
    for(int i = 0;i<n;i++){
        LL sum=1;
        for(int j = i+1;j<n;j++){
            ans[(j-i)*2]-=sum*sum%mod*a[i+1]%mod*(a[i+1]-1)%mod*((mod+1)/2)%mod*pre[i]%mod;
            sum*=a[j+1];
            sum%=mod;
            ans[(j-i)*2]=(ans[(j-i)*2]%mod+mod)%mod;
        }
    }
    for(int i = 1;i<=2*n-2;i++)
        printf("%lld ",ans[i]);
    printf("\n");
}