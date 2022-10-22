#include <bits/stdc++.h>
#define N 1005
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,a[N],dp[10][N];
bool has[3][N];
string s;
int tonum(int x)
{
    int a=has[0][x],b=has[1][x],c=has[2][x];
    return 4*a+2*b+c;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<10;i++)
        for(int j=0;j<N;j++)
            dp[i][j]=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s;
        for(int j=0;j<s.size();j++){
            if(s[j]=='A') has[0][i]=1;
            if(s[j]=='B') has[1][i]=1;
            if(s[j]=='C') has[2][i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(i==1){
            dp[tonum(i)][i]=a[i];
            continue;
        }
        for(int j=0;j<10;j++)
            dp[j][i]=dp[j][i-1];
        int to=tonum(i);
        dp[to][i]=min(dp[to][i],a[i]);
        int j=i-1;
        for(int k=0;k<8;k++)
            dp[k|to][i]=min(dp[k|to][i],dp[k][j]+a[i]);
    }
    if(dp[7][n]==1e9) dp[7][n]=-1;
    cout<<dp[7][n];
    return 0;
}