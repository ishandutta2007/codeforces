#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long
#define ULL unsigned long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<pii> v[100005];
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
pll dfs(int x,int f){
    pll p=mp(0,0);
    if(v[x].size()==1)return p;
    for(auto it:v[x]){
        if(it.x!=f){
            pll pp=dfs(it.x,x);
            p.x+=pp.x;
            p.y+=pp.y;
        }
        p.y+=it.y;
    }
    p.x%=mod;
    p.y%=mod;
    p.x=p.x*f_pow(v[x].size(),mod-2)%mod;
    p.y=p.y*f_pow(v[x].size(),mod-2)%mod;
    pll res=mp(f_pow(v[x].size(),mod-2),p.y);
    if(x==0){
        res.x=p.x;
        return res;
    }
   // printf("%d %d %d\n",x,p.x,p.y);
    LL val=f_pow((1-p.x+mod)%mod,mod-2);
  //  printf("%lld %lld %lld %lld\n",val,p.x,p.y,f_pow(v[x].size(),mod-2));
    res.x=res.x*val%mod;
    res.y=res.y*val%mod;
    //if(x==0)res.x=p.x;
   // printf("%d %d\n",res.x,res.y);
    return res;
}
int main(){ 
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        v[x].pb(mp(y,c));
        v[y].pb(mp(x,c));
    }
    pii p=dfs(0,0);
    printf("%lld\n",f_pow((1-p.x+mod)%mod,mod-2)*p.y%mod);
}
/*

5
AACCMMAA
A
AA
MM
ACA
ACMAA


5
0 9 7 1 100
-1 0 -1 -1 91
-1 5 0 -1 96
-1 8 9 0 99
-1 -1 -1 -1 0
3 4
3 5
5 6
5 7
3 or 4
3 or 5
5 or 6
5 or 7

dp[x]=max(dp[x-w_i*j]+j*t_i-delta t_i*j*(j-1)/2)
dp[x]=max(dp[j]+x*t_i-j*t_i-delta t_i*(x-j)*(x-j-1)/2)
dp[x]=max(dp[j]-j*t_i-delta t_i *(j^2/2+j/2) - 
        delta t_i * xj + x*t_i + delta t_i * (x^2/2-x/2))
dp[x]=max(dp[j] + g(j) - delta t_i *xj + w(i) )
g(j)= dp[j]-j*t_i-delta t_i *(j^2/2+j/2)
w(i)=  x*t_i + delta t_i * (x^2/2-x/2)
x^2/2 -xj -x/2  +j^2/2 +j/2
*/

/*
 

*/