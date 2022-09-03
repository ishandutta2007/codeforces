#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define double long double
using namespace std;
LL dp[2005][2005];
vector<int> v[2005];
LL pre[2005][2005];
LL suf[2005][2005];
int mod;
int n;
void dfs(int x,int f){
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
    for(auto &it:v[x]){
        if(it==f){
            swap(it,v[x].back());
        }
    }
    if(v[x].back()==f){
        v[x].pop_back();
    }
    if(v[x].empty()){
        for(int j = 1;j<=n-1;j++){
            dp[x][j]=j;
        }
     //       printf("%d\n",x);
   // for(int j = 1;j<=n-1;j++){
   //     printf("%d ",dp[x][j]);
   // }
   // printf("\n");
        return;
    }
    for(int i = 0;i<v[x].size();i++){
        for(int j = 1;j<=n-1;j++){
            if(i==0){
                pre[i][j]=dp[v[x][i]][j];
            }
            else{
                pre[i][j]=pre[i-1][j]*dp[v[x][i]][j]%mod;
            }
        }
    }
    for(int i = v[x].size()-1;i>=0;i--){
        for(int j = 1;j<=n-1;j++){
            if(i==v[x].size()-1)suf[i][j]=dp[v[x][i]][j];
            else{
                suf[i][j]=suf[i+1][j]*dp[v[x][i]][j]%mod;
            }
        }
    }
    for(int j =1;j<=n-1;j++){
        dp[x][j]=pre[v[x].size()-1][j];
    }
    if(x==1){
       // printf("%d\n",x);
       // for(int j = 1;j<=n-1;j++){
      //      printf("%d ",dp[x][j]);
       // }
        //printf("\n");
        return;
    }
    for(int i=0;i<v[x].size();i++){
        LL sum=1;
        if(i!=0)sum*=pre[i-1][1],sum%=mod;
        if(i!=v[x].size()-1)sum*=suf[i+1][1],sum%=mod;
        for(int j=2;j<=n-1;j++){
            int a=v[x][i];
            dp[x][j]+=sum*(dp[a][j]-dp[a][j-1])%mod;
            dp[x][j]%=mod;
            dp[x][j]+=mod;
            dp[x][j]%=mod;
            LL add=1;
            if(i!=0)add*=pre[i-1][j],add%=mod;
            if(i!=v[x].size()-1)add*=suf[i+1][j],add%=mod;
            sum=(sum+add)%mod;
        }
    }
    for(int j = 2;j<=n-1;j++){
        dp[x][j]=(dp[x][j]+dp[x][j-1])%mod;
    }
   // printf("%d\n",x);
   // for(int j = 1;j<=n-1;j++){
   //     printf("%d ",dp[x][j]);
   // }
   // printf("\n");
}
LL C[2005][2005];
void build(){
    for(int i = 1;i<2005;i++){
        C[i][0]=C[i][i]=1;
        for(int j = 1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
}
void solve(){  
   //int n;
   scanf("%d %d",&n,&mod);
   for(int i = 1;i<n;i++){
       int x,y;
       scanf("%d %d",&x,&y);
       v[x].pb(y);
       v[y].pb(x);
   }
   dfs(1,0);
   /*for(int i = n-1;i>1;i--){
       dp[1][i]=(dp[1][i]+mod-dp[1][i-1])%mod;
   }*/
   build();
   for(int i = 1;i<n;i++){
    //    printf("%lld ",dp[1][i]);
       for(int j  =1;j<i;j++){
           dp[1][i]-=C[i][j]*dp[1][j];
           dp[1][i]=(dp[1][i]%mod+mod)%mod;
       }
       printf("%lld ",dp[1][i]);
   }
   printf("\n");
}
int main(){
    int t=1;
    //scanf("%d",&t);
    //printf("\"");
    while(t--){
        // cerr<<t<<endl;
        solve();
     //   cerr<<t<<endl;
    }
    
   // cerr<<cnt<<endl;
}
/*
*/