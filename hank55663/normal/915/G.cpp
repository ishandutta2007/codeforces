#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int mobe[2000005];
int isprime[2000005];
LL mod = 1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL res[3000005];
LL S[3000005];
int main(){
    fill(mobe,mobe+2000005,1);
    fill(isprime,isprime+2000005,1);
    for(int i = 2;i<2000005;i++){
        if(isprime[i]){
            for(int j = i;j<2000005;j+=i){
                isprime[j]=0;
                if(j/i%i==0){
                    mobe[j]=0;
                }
                mobe[j]*=-1;
            }
        }
    }
    mobe[0]=0;
    /*vector<int> mymobe;
    for(int i =1;i<2000005;i++)
        if(mobe[i]){
            mymobe.pb(i);
        }*/
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=k;i++)
        res[i]=f_pow(i,n);
    LL out=0;
    for(int i = 1;i<=k;i++){
        if(mobe[i])
        for(int j = i;j<=k;j+=i){
            S[j]+=mobe[i]*res[j/i];
            S[j]=(S[j]%mod+mod)%mod;
            S[j+i]+=mod-mobe[i]*res[j/i];
            S[j+i]=(S[j+i]%mod+mod)%mod;
        }
    }
    LL temp = 0;
    for(int i = 1;i<=k;i++){
        temp += S[i];
        LL ans = temp;
        ans=(ans%mod+mod)%mod;
        ans^=i;
        out+=ans;
        out%=mod;
        //printf("%lld\n",ans);
    }
    printf("%lld\n",out);
   // printf("%d\n",mymobe.size());
}
/*

262143999937856
*/