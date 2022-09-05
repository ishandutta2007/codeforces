/*
    Author  : JZdavid
    From    : 
    Problem : 
    Time    : 
    Verdict : Accepting
*/
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
int n,m,x,y,dp[2][1011],b[1011],w[1011];
int cal(int x)
{
    if(x<0)return 0;else return x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++)
    {
        cin.ignore();
        for(int j=1;j<=m;j++)
        {
            char c;cin>>c;
            b[j]+=(c=='#');
            w[j]+=(c=='.');
        }
    }
    for(int i=1;i<=m;i++)
    {
        b[i]+=b[i-1],w[i]+=w[i-1];
        dp[0][i]=dp[1][i]=INF;
//      cout<<b[i]<<" "<<w[i]<<endl;
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=x;j<=y&&i+j<=m;j++)
        {
            dp[0][i+j]=min(dp[0][i+j],dp[1][i]+w[i+j]-w[i]);
            dp[1][i+j]=min(dp[1][i+j],dp[0][i]+b[i+j]-b[i]);
        }
//      cout<<i<<":"<<dp[0][i]<<","<<dp[1][i]<<endl;
    }
    cout<<min(dp[0][m],dp[1][m])<<endl; 
 // system("pause");
    return 0;
}