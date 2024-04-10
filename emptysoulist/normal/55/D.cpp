#include <bits/stdc++.h>
#define ll long long
using namespace std;
int digit[20],mp[2521],cnt;
ll dp[20][2521][50];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

ll dfs(int len,int pre,int mod,int limit){
    if(!len) return pre%mod==0;
    if(!limit&&dp[len][pre][mp[mod]]!=-1) return dp[len][pre][mp[mod]];
    ll ret=0;int ed=limit?digit[len]:9;
    for(int i=0;i<=ed;i++)
        ret+=dfs(len-1,(pre*10+i)%2520,i==0?mod:mod*i/gcd(mod,i),limit&&i==ed);
    if(!limit) dp[len][pre][mp[mod]]=ret;
    return ret;
}

ll calc(ll n){
    int len=0;
    while(n){
        digit[++len]=n%10;
        n/=10;
    }
    return dfs(len,0,1,1);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=2520;i++)
        if(2520%i==0) mp[i]=++cnt;
    int T;ll l,r;
    cin>>T;
    while(T--){
        cin>>l>>r;
        cout<<calc(r)-calc(l-1)<<endl;
    }
    return 0;
}