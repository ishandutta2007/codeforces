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
#define MXN 200005
int mod=998244353;
LL dp1[2005][2005];
LL dp2[2005][2005];
int vis[2005][2005];
char c[2005];
pll DP(int l,int r){
    if(l>r)return mp(1,0);
    if(l==r){
        if(c[l]=='?')return mp(2,0);
        else return mp(1,0);
    }
    if(vis[l][r])return mp(dp1[l][r],dp2[l][r]);
    vis[l][r]=1;
    if((c[l]=='('||c[l]=='?')&&(c[r]==')'||c[r]=='?')){
        pii p=DP(l+1,r-1);
      //  dp1[l][r]+=p.x;
        dp2[l][r]+=p.y+p.x;
    }
    if(c[l]==')'||c[l]=='?'){
        pii p=DP(l+1,r);
       // dp1[l][r]+=p.x;
        dp2[l][r]+=p.y;
    }
    if(c[r]=='('||c[r]=='?'){
        pii p=DP(l,r-1);
       // dp1[l][r]+=p.x;
        dp2[l][r]+=p.y;
    }
    if((c[l]==')'||c[l]=='?')&&(c[r]=='('||c[r]=='?')){
       
        pii p=DP(l+1,r-1);
      //  dp1[l][r]-=p.x;
        dp2[l][r]-=p.y;
    }
   // dp1[l][r]=(dp1[l][r]%mod+mod)%mod;
    dp2[l][r]=(dp2[l][r]%mod+mod)%mod;
    //dp1[l][r]1
  //  printf("%d %d %lld %lld\n",l,r,dp1[l][r],dp2[l][r]);
    return mp(dp1[l][r],dp2[l][r]);
}
int cal(char *c){
    int l=0,r=strlen(c)-1;
    int ans=0;
    while(l<=r){
        if(c[l]=='('&&c[r]==')')ans++,l++,r--;
        else if(c[l]==')')l++;
        else if(c[r]=='(')r--;
    }
    return ans;
}
int main(){
    scanf("%s",c+1);
    for(int i = 1;c[i]!=0;i++){
        dp1[i][i-1]=1;
        for(int j=i;c[j]!=0;j++){
            dp1[i][j]=dp1[i][j-1];
            if(c[j]=='?')
            {
                dp1[i][j]=dp1[i][j]*2%mod;
            }
        }
    }
    printf("%lld\n",DP(1,strlen(c+1)).y);

   /* int x=strlen(c+1);
    LL tot=0;
    for(int i = 0;i<(1<<x);i++){
        for(int j =1;c[j]!=0;j++){
            if(i&(1<<(j-1))){
                c[j]='(';
            }
            else{
                c[j]=')';
            }
        }
      //  printf("%s\n",c+1);
        tot+=cal(c+1);
    }
    printf("%lld\n",tot);*/
}