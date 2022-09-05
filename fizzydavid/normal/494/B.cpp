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
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const ll mod=1e9+7;
ll dp[100111],pre[100111],pre2[100111];
int Next[100111];
bool match[100111];
string s,t;
ll sum(int x)
{
    if(x<0)return 0;
    else return pre2[x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>s>>t;
    int lolp=0;            
    Next[1]=0;
    for(int i=2;i<=t.size();i++)
    {
        while(lolp>0&&(t[lolp]!=t[i-1]))lolp=Next[lolp];
        if(t[lolp]==t[i-1])lolp++;
        Next[i]=lolp;
    }
    int nocm=0;
    for(int i=0;i<s.size();i++)
    {
        while(nocm>0&&t[nocm]!=s[i])nocm=Next[nocm];
        if(t[nocm]==s[i])nocm++;
        if(nocm==t.size())
        {
            match[i+1]=1;
            nocm=Next[nocm];
        }
    }
    for(int i=1;i<=s.size();i++)
    {
        if(match[i]==0)dp[i]=dp[i-1];
        else
        {
            dp[i]=(sum(i-t.size())+i-t.size()+1)%mod;
        }
        pre[i]=(pre[i-1]+dp[i])%mod;
        pre2[i]=(pre2[i-1]+pre[i])%mod;
    }
    cout<<pre[s.size()]<<endl;
    return 0;
}