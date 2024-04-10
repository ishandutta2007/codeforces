#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> v[4];

long long dp[300005];
int ones[300005];
int twos[300005];

int main(){
    scanf("%d%d",&n,&m);
    int a,b;
    while (n--){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
    }

    for (int x=1;x<=3;x++) sort(v[x].begin(),v[x].end(),[](int i,int j){return i>j;});

    for (int x=0;x<=m;x++){
        if (ones[x]!=v[1].size() && dp[x+1]<dp[x]+v[1][ones[x]]){
             dp[x+1]=dp[x]+v[1][ones[x]];
             ones[x+1]=ones[x]+1;
             twos[x+1]=twos[x];
        }
        if (twos[x]!=v[2].size()){
            dp[x+2]=dp[x]+v[2][twos[x]];
            ones[x+2]=ones[x];
            twos[x+2]=twos[x]+1;
        }
    }

    for (int x=1;x<=m;x++) dp[x]=max(dp[x],dp[x-1]);

    long long best=dp[m];
    long long curr=0;

    for (int x=0;x<min((int)v[3].size(),m/3);x++){
        curr+=v[3][x];
        best=max(best,curr+dp[m-x*3-3]);
    }

    printf("%lld\n",best);
}