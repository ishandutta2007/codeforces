/*
    Author  : JZdavid
    From    : Hao Ba Test(Lesson 7)
    Problem : The Great Julya Calender
    Time    : 2014/8/6
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
#include<ctime>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
int n,dp[1001111];
bool ok(int x,int d)
{
    int t=x;
    while(t>0)
    {
        if(t%10==d)return 1;
        t=t/10;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<=n;i++)dp[i]=INF;
    dp[0]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<10;j++)
        {
            if(ok(i+j,j))dp[i+j]=min(dp[i+j],dp[i]+1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}