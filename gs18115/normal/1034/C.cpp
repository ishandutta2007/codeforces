#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL MAXV=1e6+10;
LL gcd(LL X,LL Y)
{
    return Y>0?gcd(Y,X%Y):X;
}
vector<LL>adj[MAXV];
LL S[MAXV];
void dfs(LL X)
{
    for(LL i=0;i<adj[X].size();i++)
    {
        dfs(adj[X][i]);
        S[X]+=S[adj[X][i]];
    }
    return;
}
LL N,P,sum,t;
LL i,j;
LL cnt[MAXV],dp[MAXV];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>S[i];
    for(i=1;i<N;i++)
    {
        cin>>P;
        adj[P-1].push_back(i);
    }
    dfs(0);
    for(i=0;i<N;i++)
    {
        t=S[0]/gcd(S[0],S[i]);
        if(t<=N)
            cnt[t]++;
    }
    for(i=N;i>0;i--)
        for(j=i<<1;j<=N;j+=i)
            cnt[j]+=cnt[i];
    dp[1]=1;
    for(i=1;i<=N;i++)
    {
        if(cnt[i]>=i)
        {
            sum+=dp[i];
            for(j=i<<1;j<=N;j+=i)
                dp[j]+=dp[i];
        }
    }
    cout<<sum%MOD<<endl;
    return 0;
}