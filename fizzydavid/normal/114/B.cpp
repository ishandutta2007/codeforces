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
int n,m;
map<string,int>mp;
bool ban[20][20];
string name[20];
set<string>tmp;
set<string>ans;
void dfs(int x)
{
    if(x==n)
    {
        if(tmp.size()>ans.size())ans=tmp;
        return;
    }
    set<string>::iterator it;
    for(it=tmp.begin();it!=tmp.end();it++)
    {
        if(ban[mp[*it]][x])break;
    }
    if(it==tmp.end())
    {
        tmp.insert(name[x]);
        dfs(x+1);
        tmp.erase(name[x]);
    }
    dfs(x+1);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){cin>>name[i];mp[name[i]]=i;}
    for(int i=0;i<m;i++)
    {
        string a,b;cin>>a>>b;
        ban[mp[a]][mp[b]]=1;ban[mp[b]][mp[a]]=1;
    }
    dfs(0);
    cout<<ans.size()<<endl;
    set<string>::iterator it;
    for(it=ans.begin();it!=ans.end();it++)cout<<*it<<endl;
//  system("pause");
    return 0;
}