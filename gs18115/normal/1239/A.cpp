#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
const ll mod=1e9+7;
int n,m,i;
ll dp[100010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0]=dp[1]=1;
    cin>>n>>m;
    for(i=2;i<=n||i<=m;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=mod;
    }
    cout<<2*(dp[n]+dp[m]-1)%mod<<endl;
    return 0;
}