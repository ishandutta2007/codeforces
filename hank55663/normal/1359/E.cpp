#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
vector<int> v[500005];
LL fra[500005];
LL inv[500005];
LL mod=998244353;
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
    if(b>a)return 0;
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
int cnt[500005];
int main(){
    fra[0]=1;
    for(int i = 1;i<500005;i++)fra[i]=fra[i-1]*i%mod;
    inv[500000]=f_pow(fra[500000],mod-2);
    for(int i = 499999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i =1;i<=n;i++){
        for(int j=i*2;j<=n;j+=i)cnt[i]++;
    }
    LL ans=0;
    for(int i = 1;i<=n;i++){
        ans+=C(cnt[i],k-1);
      //  printf("%d\n",cnt[i]);
        ans%=mod;
    }
    printf("%lld\n",ans);
}
/*
2 11 14
9 3


000111222
001112220
*/