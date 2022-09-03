#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define N 200005
#define rank Rank
#define index Index
LL cnt[55][55];
int mod=1e9+7;
LL Cnt(int x,int y){
    if(cnt[x][y]!=-1)return cnt[x][y];
    cnt[x][y]=0;
    if(y!=0){
        cnt[x][y]=0;
        if(x>=2)
        cnt[x][y]+=Cnt(x-2,y-1)*x*(x-1)/2%mod;
        if(x!=0&&y>=2)
        cnt[x][y]+=Cnt(x,y-2)*x*(y-1)%mod;
        if(y>=3)
        cnt[x][y]+=Cnt(x+2,y-3)*(y-1)*(y-2)/2%mod;
        cnt[x][y]%=mod;
    }
    else{
        cnt[x][y]=Cnt(x-2,y)*(x-1)%mod;
    }
    return cnt[x][y];
}
LL dp[55][55];
int n;
int d[55];
LL C[55][55];
LL fra[55];
LL pow2[55];
LL invpow2[55];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void build(){
    for(int i = 0;i<55;i++){
        C[i][i]=C[i][0]=1;
        for(int j =1;j<i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    fra[0]=1;
    for(int i = 1;i<55;i++)
        fra[i]=fra[i-1]*i%mod;
    pow2[0]=1;
    for(int i = 1;i<55;i++){
        pow2[i]=pow2[i-1]*2%mod;
        invpow2[i]=f_pow(pow2[i],mod-2);
    }
    invpow2[0]=1;
    
}
LL DP(int l,int r){
    if(l==n&&r==n-1)return 1;
    if(l>r)return 0;
    if(r>=n)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int tot[3]={0,0,0};
    int sum=0;
    for(int i=l;i<=r;i++){
        tot[d[i]-1]++;
        sum+=d[i]-1;
    }
    dp[l][r]=0;
    for(int i = sum;i>=0;i-=2){
        for(int j = 0;j<=tot[2];j++){
            for(int k =0;j+k<=tot[2];k++){
                int need2=j+k,need1=i-j*2-k;
                if(need1>tot[1])
                continue;
                if(need1<0)
                continue;
                dp[l][r]+=C[tot[2]][need2]*C[need2][j]%mod
                         *C[tot[1]][need1]%mod*fra[i]%mod*invpow2[j]%mod*Cnt(tot[1]-need1+k,tot[2]-need2)%mod*DP(r+1,r+i)%mod;
                dp[l][r]%=mod;
            }
        }
    }
  //  printf("%d %d %lld\n",l,r,dp[l][r]);
    return dp[l][r];
}
int main(){
    scanf("%d",&n);
    for(int i =0;i<n;i++)
        scanf("%d",&d[i]);
    MEMS(dp);

    MEMS(cnt);
    cnt[0][0]=1;
    build();
    printf("%lld\n",DP(1,d[0]));
    return 0;
}