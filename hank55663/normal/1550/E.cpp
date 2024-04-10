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
#define last Last
#define MXN 200005
int cnt[200005][17];
int dp[200005];
vector<int> v[27];
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[200005];
    scanf("%s",c+1);
    for(int i = 1;c[i]!=0;i++){
        for(int j = 0;j<k;j++){
            if(c[i]=='?'||c[i]-'a'==j)
            cnt[i][j]=cnt[i-1][j]+1;
            else cnt[i][j]=0;
        }
    }
    int Min=0,Max=n+1;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        dp[0]=-mid;
        for(int j = 0;j<k;j++)v[j].clear();
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<k;j++){
                if(cnt[i][j]>=mid)v[j].pb(i);
            }
        }
        for(int i = 1;i<(1<<k);i++)dp[i]=1e9;
        for(int i = 1;i<(1<<k);i++){
            for(int j = 0;j<k;j++){
                if(i&(1<<j)){
                    auto it=lower_bound(v[j].begin(),v[j].end(),dp[i-(1<<j)]+mid);
                    if(it!=v[j].end())dp[i]=min(dp[i],*it);
                }
            }
        }
        if(dp[(1<<k)-1]!=1e9)Min=mid;
        else Max=mid;
    }
    printf("%d\n",Min);
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}