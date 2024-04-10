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
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v;
    char c[55];
    scanf("%s",c);
    for(int i = 0;i<n;i++){
        if(c[i]=='*')v.pb(i);
    }
    int dp[55];
    dp[0]=1;
    for(int i = 1;i<v.size();i++){
        dp[i]=1e9;
        for(int j = i-1;j>=0;j--){
            if(v[i]-v[j]<=k){
                dp[i]=min(dp[j]+1,dp[i]);
            }
        }
    }
    printf("%d\n",dp[v.size()-1]);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
*/