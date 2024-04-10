#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,i,j,x;
LL dp[5012][5012];
vector<LL>V1,V2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    cin>>x;
    V1.push_back(x);
    for(i=1;i<N;i++)
    {
        cin>>x;
        if(x!=V1.back())
            V1.push_back(x);
    }
    V2=V1;
    reverse(V1.begin(),V1.end());
    for(i=0;i<V1.size();i++)
    {
        for(j=0;j<V2.size();j++)
        {
            if(V1[i]==V2[j])
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i+1][j]);
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j+1]);
        }
    }
    cout<<V1.size()-(dp[V1.size()][V2.size()]+1>>1)<<endl;
    return 0;
}