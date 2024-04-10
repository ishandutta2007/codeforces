#include<iostream>
#include<cstdio>
#include<vector>//
#include<string>
using namespace std;
int n,m,ch[200001][2],pos[200001];
string s;
vector<int> v;
bool vis[200001],tag[200001];
inline void dfs1(int k)
{
    if(ch[k][0])
        dfs1(ch[k][0]);
    v.emplace_back(k);
    if(ch[k][1])
        dfs1(ch[k][1]);
}
inline void dfs2(int k,int val)
{
    if(!k||val>m)
        return;
    dfs2(ch[k][0],val+1);
    if(vis[ch[k][0]])
        vis[k]=1;
    else if(tag[k])
    {
        vis[k]=1;
        m-=val;
    }
    if(vis[k])
        dfs2(ch[k][1],1);
}
int main()
{
    cin>>n>>m>>s;
    s=" "+s;
    for(int i=1;i<=n;++i)
        cin>>ch[i][0]>>ch[i][1];
    dfs1(1);
    char lst=s[v.back()];
    for(int i=n-2;i>=0;--i)
    {
        if(s[v[i]]!=s[v[i+1]])
            lst=s[v[i+1]];
        tag[v[i]]=s[v[i]]<lst;
    }
    dfs2(1,1);
    for(int i:v)
    {
        cout<<s[i];
        if(vis[i])
            cout<<s[i];
    }
    cout<<'\n';
    return 0;
}