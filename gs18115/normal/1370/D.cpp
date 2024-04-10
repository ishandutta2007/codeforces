#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18+7;
inline bool able(vector<int>&v,int c,int k)
{
    int n=v.size();
    vector<int>dp(n+1,inf),pm(n+1,inf);
    dp[0]=0;
    pm[0]=pm[1]=0;
    int mn=n;
    for(int i=0;i++<n;)
    {
        pm[i]=min(pm[i],pm[i-1]+1);
        if(v[i-1]>c)
            continue;
        dp[i]=pm[i-1];
        if(i<n)
            pm[i+1]=dp[i];
        mn=min(mn,dp[i]+max(n-i-1,0));
    }
    return mn<=n-k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int&t:v)
        cin>>t;
    int s=0;
    int e=inf;
    while(s<e)
    {
        int m=(s+e)/2;
        if(able(v,m,k))
            e=m;
        else
            s=m+1;
    }
    cout<<s<<endl;
    return 0;
}