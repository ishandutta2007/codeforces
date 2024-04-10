//while(true)rp++;
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
string s;
int TestNums,dp[5111][5111];
bool is[5111][5111];
int main()
{
    ios::sync_with_stdio(false);
    cin>>s>>TestNums;
    int n=s.length();
    for(int i=n-1;i>=0;i--)s[i+1]=s[i];
    for(int i=1;i<=n;i++)dp[i][i]=is[i][i]=1;
    for(int len=1;len<=n/2;len++)
    {
        for(int j=len;j<=n-len;j++)
        {
            int head=j-len+1,end=j+len;
            if(((len>1&&is[head+1][end-1])||(len==1))&&s[head]==s[end])is[head][end]=1;
            dp[head][end]=is[head][end]+dp[head+1][end]+dp[head][end-1]-dp[head+1][end-1];
        }
        for(int j=len+1;j<=n-len;j++)
        {
            int head=j-len,end=j+len;
            if(is[head+1][end-1]&&s[head]==s[end])is[head][end]=1;
            dp[head][end]=is[head][end]+dp[head+1][end]+dp[head][end-1]-dp[head+1][end-1];
        }
    }
    int l,r;
    while(TestNums--)
    {
        cin>>l>>r;
        cout<<dp[l][r]<<endl;
    }
    return 0;
}