//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n;
string s[111];
vector<int>rev[31],ans;
bool used[30],live[30];
void failed(){cout<<"Impossible"<<endl;exit(0);}
bool vis[30];
void dfsrev(int x)
{
    vis[x]=1;
    live[x]=1;
    for(int i=0;i<rev[x].size();i++)
    {
        int u=rev[x][i];
        if(!vis[u])dfsrev(u);
        else if(live[u])failed();
    }
    live[x]=0;
    ans.PB(x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<n;i++)
    {
        int tmp=0;
        while(tmp<s[i].size()&&tmp<s[i+1].size()&&s[i][tmp]==s[i+1][tmp])tmp++;
        if(tmp==s[i].size()||tmp==s[i+1].size())if(s[i].size()>s[i+1].size())failed();else continue;
        rev[s[i+1][tmp]-'a'].PB(s[i][tmp]-'a');
        used[s[i][tmp]-'a']=used[s[i+1][tmp]-'a']=1;
    }
    for(int i=0;i<26;i++)if(used[i]&&vis[i]==0)
    {
        dfsrev(i);
    }
    for(int i=0;i<ans.size();i++)cout<<char('a'+ans[i]);
    for(int i=0;i<26;i++)if(!used[i])cout<<char('a'+i);
    return 0;
}