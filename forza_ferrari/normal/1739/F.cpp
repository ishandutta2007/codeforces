#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,d[21],tot,ch[4001][12],fail[4001],val[4001],dp[1<<12][4001],ans;
pair<int,int> pre[1<<12][4001];
bool vis[21][21];
vector<int> v;
inline void dfs(int k,int f)
{
    v.emplace_back(k);
    for(int i=0;i<12;++i)
        if(i!=f&&vis[k][i])
            dfs(i,k);
}
inline void insert(int w)
{
    int node=0;
    for(int i:v)
    {
        if(!ch[node][i])
            ch[node][i]=++tot;
        node=ch[node][i];
    }
    val[node]+=w;
}
inline void getfail()
{
    queue<int> q;
    for(int i=0;i<12;++i)
        if(ch[0][i])
            q.emplace(ch[0][i]);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        for(int i=0;i<12;++i)
            if(ch[k][i])
            {
                fail[ch[k][i]]=ch[fail[k]][i];
                val[ch[k][i]]+=val[ch[fail[k]][i]];
                q.emplace(ch[k][i]);
            }
            else
                ch[k][i]=ch[fail[k]][i];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int w;
        string s;
        v.clear();
        cin>>w>>s;
        if(s.length()==1)
        {
            v.emplace_back(s[0]-'a');
            insert(w);
            continue;
        }
        for(int i=0;i<12;++i)
        {
            d[i]=0;
            for(int j=0;j<12;++j)
                vis[i][j]=0;
        }
        for(int i=1;i<(int)s.length();++i)
            vis[s[i-1]-'a'][s[i]-'a']=vis[s[i]-'a'][s[i-1]-'a']=1;
        bool flag=1;
        int pos=-1;
        for(int i=0;i<12;++i)
        {
            for(int j=0;j<12;++j)
                d[i]+=vis[i][j];
            if(d[i]>2)
            {
                flag=0;
                break;
            }
            if(d[i]==1)
                pos=i;
        }
        if(flag&&pos!=-1)
        {
            dfs(pos,-1);
            insert(w);
            reverse(v.begin(),v.end());
            insert(w);
        }
    }
    getfail();
    for(int i=0;i<1<<12;++i)
        for(int j=0;j<=tot;++j)
        {
            dp[i][j]=-1e9;
            pre[i][j]={-1,-1};
        }
    dp[0][0]=0;
    for(int s=0;s<1<<12;++s)
        for(int i=0;i<=tot;++i)
            if(dp[s][i]>=0)
                for(int j=0;j<12;++j)
                    if(!(s>>j&1))
                        if(dp[s|(1<<j)][ch[i][j]]<dp[s][i]+val[ch[i][j]])
                        {
                            dp[s|(1<<j)][ch[i][j]]=dp[s][i]+val[ch[i][j]];
                            pre[s|(1<<j)][ch[i][j]]={j,i};
                        }
    for(int i=1;i<=tot;++i)
        if(dp[(1<<12)-1][i]>dp[(1<<12)-1][ans])
            ans=i;
    //cout<<dp[(1<<12)-1][ans]<<'\n';
    for(int s=(1<<12)-1,i=ans;s;)
    {
        cout<<(char)(pre[s][i].first+'a');
        pair<int,int> tmp=pre[s][i];
        s^=1<<tmp.first;
        i=tmp.second;
    }
    cout<<'\n';
    return 0;
}