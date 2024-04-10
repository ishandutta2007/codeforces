#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
int mod=1e9+7;
char c[1000005];
LL dp[1000005];
int main(){
    scanf("%s",c);
    vector<LL> v;
    int cnt=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='0')cnt++;
        else{
            v.pb(cnt+1);
            cnt=0;
        }
    }
    v.pb(cnt+1);
    if(v.size()==1){
        printf("%d\n",v[0]-1);
    }
    else if(v.size()==2){
        printf("%lld\n",v[0]*v[1]%mod);
    }
    else{

        LL sum=v[1]+1;
        fill(dp,dp+v[1]+1,1);
      //   printf("%lld\n",sum);
        for(int i = 2;i<v.size()-1;i++){
            LL sum2=sum;
            for(int j=1;j<=v[i];j++){
                //printf("%d %d %d\n",j,dp[j],sum-dp[j]);
                 sum2+=sum-dp[j];
                dp[j]+=sum-dp[j];
               
                sum2=(sum2%mod+mod)%mod;
                dp[j]=(dp[j]%mod+mod)%mod; 
                
            }
            sum=sum2;
           // printf("%lld\n",sum);
        }

        printf("%lld\n",(sum)*v[0]%mod*v.back()%mod);
    }
}