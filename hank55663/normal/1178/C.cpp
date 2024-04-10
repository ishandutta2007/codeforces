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
int mod=998244353;
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
    int h,w;
    scanf("%d %d",&h,&w);
    LL ans=4*f_pow(2,h-1)%mod*f_pow(2,w-1)%mod;
    printf("%lld\n",ans);
}
/*
1 
2 6 
3 5 
4
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

if(c[n-(r-l+1)]==)
dp[l][r]
dp[]
1 3 4 2
*/