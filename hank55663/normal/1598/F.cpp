#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 500005
int Min[20],val[20];
int m[20][1000005];
int m2[20][1000005];
char c[20][400005];
int val2[1<<20];
int dp[1<<20];
int vis[1<<20];
int n;
int DP(int x){
    if(vis[x])return dp[x];
    if(x==0)return 0;
    dp[x]=-1e9;
    vis[x]=1;
    for(int i = 0;i<n;i++){
        if(x&(1<<i)){
            int mask=x-(1<<i);
            if(val2[mask]+Min[i]>=0){
                dp[x]=max(dp[x],DP(mask)+m[i][-val2[mask]+500000]);
            }
        }
    }
    return dp[x];
}
void solve(){
    //int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
        int sum=0;
        Min[i]=1e9;
        for(int j = 0;c[i][j]!=0;j++){
            if(c[i][j]=='(')sum++;
            else sum--;
            Min[i]=min(Min[i],sum);
            m[i][sum+500000]++;
            if(sum==Min[i])m2[i][sum+500000]++;
        }
        val[i]=sum;
    }
    for(int i = 1;i<(1<<n);i++){
        int x=i&-i;
        int j=__builtin_popcount(x-1);
        val2[i]=val2[i-x]+val[j];
    }
    int ans=0;
    for(int i = 0;i<(1<<n);i++){
        int res=DP(i);
        int Max=0;
        for(int j = 0;j<n;j++){
            if(i&(1<<j));
            else{
                Max=max(Max,m2[j][-val2[i]+500000]);
            }
        }
        ans=max(ans,res+Max);
    }
    printf("%d\n",ans);
}
int main(){

    int t=1;0000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
*/