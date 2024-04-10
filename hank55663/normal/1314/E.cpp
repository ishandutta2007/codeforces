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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
//int dp[1005][1005];
LL dp[2025][2025];
int mod=998244353;
vector<int> v;
int ans;
bool check(vector<int> v,int k,int n){
    if(k==2){
        //sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        LL sum=0;
        for(int i = 0;i<v.size();i++){
          //  printf("%d ",v[i]);
            sum+=v[i]*(i+1);
        }
       // printf("!\n");
        if(sum<=n)return true;
        return false;
    }
    reverse(v.begin(),v.end());
    vector<int> tmp;
    int sum=0;
    for(int i = 0;i<v.size();i++){
        for(int j=0;j<v[i];j++){
            tmp.pb(i+1);
            sum+=i+1;
        }
    }
    if(sum>n)return false;
    return check(tmp,k-1,n);
}
void dfs(int n,int k){
    while(true){
       // for(auto it:v)printf("%d " ,it);
        //printf("%d?\n",ans);
        //getchar();
        if(check(v,k,n)){
            ans++;
        //    v.back()++;
        }
        else{
            v.pop_back();
            return ;
        }
        v.pb(v.back());
        dfs(n,k);
        v.back()++;
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(k==1){
        LL dp[2025];
        MEM(dp);
        dp[0]=1;
        for(int i = 1;i<=n;i++){
            for(int j=0;j<=n-i;j++){
                dp[j+i]+=dp[j];
                dp[j+i]%=mod;
            }
        }
        int ans=0;
        for(int i = 1;i<=n;i++){
            ans+=dp[i];
            ans%=mod;
        }
        printf("%d\n",ans);
    }
    else if(k==2){
        dp[0][0]=1;
        for(int i = n;i>=1;i--){
            for(int j=0;j+i<=n;j++){
                for(int k=0;j+(k+1)*i<=n;k++){
                    dp[j+(k+1)*i][k+1]+=dp[j][k];
                    dp[j+(k+1)*i][k+1]%=mod;
                }
            }
        }
        LL ans=0;
        for(int i = 1;i<=n;i++){
            for(int j=0;j<=n;j++){
              //  printf("%d ",dp[i][j]);
                ans+=dp[i][j];
                ans%=mod;
            }
            //printf("\n");
        }
        printf("%lld\n",ans);
    }
    else{
        v.pb(1);
        dfs(n,k);
        printf("%d\n",ans);
    }
    return 0;
}