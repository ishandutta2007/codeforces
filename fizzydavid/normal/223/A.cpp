/*
    Author  : JZdavid
    From    : CF 
    Problem : div.1 223 Bracket sequences
    Time    : 
    Verdict : Accepted
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
string s;
int dp[100111];
bool cmp(pair<int,int> a,pair<int,int> b){return a.ff<b.ff;}
bool can[100111],vis[100111];
stack<pair<char,int> >q;
vector<pair<int,int> >v;
int main()
{
    ios::sync_with_stdio(false);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        dp[i]=((i==0)?0:dp[i-1]);
        if(s[i]=='[')dp[i]++;
        if(s[i]=='('||s[i]=='[')
        {
            q.push(mp(s[i],i));
        }
        else
        {
            if(!q.empty()&&(s[i]==')'&&q.top().ff=='('||s[i]==']'&&q.top().ff=='['))
            {
                    v.pb(mp(q.top().ss,i));
                    q.pop();
            }
            else
            {
                while(!q.empty())q.pop();
            }
        }
    }
    for(int i=0;i<v.size();i++)
    {
        if(i+1!=v.size()&&v[i].ff>=v[i+1].ff&&v[i].ss<=v[i+1].ss)can[i]=0;else can[i]=1;
    }
    for(int i=0;i<v.size();i++)
    {
        if(can[i])
        {
            for(int j=v[i].ff;j<=v[i].ss;j++)vis[j]=1;
        }
    }
    int ans=0,l=-1,r=-1;
    for(int i=0;i<s.size();i++)
    {
        int cnt=0;
        while(i<s.size()&&vis[i]==1)
        {
            cnt++;
            i++;
        }
        if(dp[i-1]-dp[i-cnt-1]>ans)l=i-cnt,r=i-1,ans=dp[r]-dp[l-1];
    }
    if(l==-1)cout<<"0"<<endl;
    else
    {
        cout<<ans<<endl;
        for(int i=l;i<=r;i++)cout<<s[i];
        cout<<endl;
    }
//  system("pause");
    return 0;
}