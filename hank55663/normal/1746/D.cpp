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
using namespace std;
LL dp[200005][2];
int sc[200005];
vector<int> v[200005];
void dfs(int x,int f,LL k){
    dp[x][0]=(k-1)*sc[x];
    dp[x][1]=k*sc[x];
    if(!v[x].empty()){
        vector<int> q;
        LL sum=0;
        for(auto it:v[x]){
            dfs(it,x,(k+v[x].size()-1)/v[x].size());
            sum+=dp[it][0];
            q.pb(dp[it][1]-dp[it][0]);
        }
        sort(q.begin(),q.end());
        reverse(q.begin(),q.end());
        int need=(k-1)%v[x].size();
        dp[x][0]+=sum;
        dp[x][1]+=sum;
        for(int j = 0;j<need;j++)dp[x][0]+=q[j],dp[x][1]+=q[j];
        dp[x][1]+=q[need];
    }
  //  printf("%d %d %d %d\n",x,k,dp[x][0],dp[x][1]);
}
void solve(int T){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)v[i].clear();
    for(int i = 2;i<=n;i++){
        int p;
        scanf("%d",&p);
        v[p].pb(i);
    }
    for(int i = 1;i<=n;i++)scanf("%d",&sc[i]);
    dfs(1,0,k);
    printf("%lld\n",dp[1][1]);
}

int main(){
    int t=1;
     scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
1
2 4
3 
5
*/