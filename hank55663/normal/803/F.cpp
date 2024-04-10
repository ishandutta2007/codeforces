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
#define less Less
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
int mobe[100005];
int isprime[100005];
vector<int> factor[100005];
int main(){
    fill(mobe,mobe+100005,1);
    fill(isprime,isprime+100005,1);
    isprime[1]=0;
    for(int i = 1;i<=100000;i++){
        if(isprime[i])
            for(int j = i;j<=100000;j+=i){
                isprime[j]=0;
                mobe[j]*=-1;
                if(j/i%i==0){
                    mobe[j]=0;
                }
            }
        for(int j =i;j<=100000;j+=i){
            factor[j].pb(i);
        }
    }
    int n;
    scanf("%d",&n);
    int cnt[100005];
    MEM(cnt);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(auto it:factor[x]){
            cnt[it]++;
        }
    }
    LL ans=0;
    for(int i = 1;i<=100000;i++){
        ans+=mobe[i]*(f_pow(2,cnt[i])-1);
    }
    printf("%lld\n",(ans%mod+mod)%mod);
}