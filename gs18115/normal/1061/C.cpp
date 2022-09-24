#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MOD=1e9+7;
vector<LL>V[123456];
LL A[123456];
LL N,i,j,S;
LL dp[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        LL t=(LL)(sqrt(A[i])+1);
        for(j=1;j<=min(t,i+1);j++)
        {
            if(A[i]%j==0)
            {
                V[i].push_back(j);
                V[i].push_back(A[i]/j);
            }
        }
        sort(V[i].begin(),V[i].end());
        V[i].erase(unique(V[i].begin(),V[i].end()),V[i].end());
        V[i].erase(upper_bound(V[i].begin(),V[i].end(),i+1),V[i].end());
        sort(V[i].begin(),V[i].end(),greater<LL>());
    }
    dp[0]=1;
    for(i=0;i<N;i++)
        for(auto j:V[i])
            dp[j]=(dp[j]+dp[j-1])%MOD;
    for(i=1;i<=N;i++)
        S+=dp[i];
    cout<<S%MOD<<endl;
    return 0;
}