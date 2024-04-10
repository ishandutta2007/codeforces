




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
#define N 100005
#define MXN 2000005
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
    LL x,n;
    scanf("%lld %lld",&x,&n);
    vector<int> v;
    for(int i = 2;i*i<=x;i++){
        if(x%i==0){
            v.pb(i);
            while(x%i==0)x/=i;
        }
    }
    if(x!=1)v.pb(x);
    LL res=1;
    for(auto it:v){
        LL tmp=n;
        while(tmp){
            LL x=tmp/it;
            res=res*f_pow(it,x)%mod;
            tmp/=it;
        }
    }
    printf("%lld\n",res);
    return 0;
}