#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct edge
{
    int nxt,to;
    bool tag;
}e[300001<<1];
int n,ans[300001][2],tot=1,cur[600001];
char mp[2][300001][2];
vector<int> node;
bool vis[600001];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void add(int x,int y)
{
    e[++tot].nxt=cur[x];
    cur[x]=tot;
    e[tot].to=y;
}
inline void dfs(int k)
{
    node.emplace_back(k);
    if(vis[k])
        return;
    vis[k]=1;
    for(int i=cur[k];i;i=cur[k])
    {
        cur[k]=e[i].nxt;
        if(e[i].tag)
            continue;
        e[i].tag=e[i^1].tag=1;
        dfs(e[i].to);
        node.emplace_back(k);
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    int pos=0;
    for(int i=1;i<=n+n;++i)
    {
        if(vis[i])
            continue;
        node.clear();
        dfs(i);
        node.pop_back();
        if(node.empty())
            continue;
        if(node.size()==2)
        {
            cout<<"-1\n";
            return 0;
        }
        int len=node.size()>>1;
        for(int j=0;j<len;++j)
            ans[pos+j+1][0]=node[j];
        for(int j=len;j<node.size();++j)
            ans[pos+len-(j-len)][1]=node[j];
        if(len&1)
            for(int j=0;j<len;++j)
            {
                if(j==0)
                {
                    mp[0][pos+j+1][0]='U';
                    mp[0][pos+j+1][1]='D';
                }
                else
                    mp[0][pos+j+1][0]=mp[0][pos+j+1][1]=(j&1? 'L':'R');
                if(j==len-1)
                {
                    mp[1][pos+j+1][0]='U';
                    mp[1][pos+j+1][1]='D';
                }
                else
                    mp[1][pos+j+1][0]=mp[1][pos+j+1][1]=(j&1? 'R':'L');
            }
        else
            for(int j=0;j<len;++j)
            {
                if(j==0||j==len-1)
                {
                    mp[0][pos+j+1][0]='U';
                    mp[0][pos+j+1][1]='D';
                }
                else
                    mp[0][pos+j+1][0]=mp[0][pos+j+1][1]=(j&1? 'L':'R');
                mp[1][pos+j+1][0]=mp[1][pos+j+1][1]=(j&1? 'R':'L');
            }
        pos+=len;
    }
    cout<<"2 "<<n<<"\n\n";
    for(int i=1;i<=n;++i)
        cout<<ans[i][0]<<" ";
    cout<<'\n';
    for(int i=1;i<=n;++i)
        cout<<ans[i][1]<<" ";
    cout<<"\n\n";
    for(int i=1;i<=n;++i)
        cout<<mp[0][i][0];
    cout<<'\n';
    for(int i=1;i<=n;++i)
        cout<<mp[0][i][1];
    cout<<"\n\n";
    for(int i=1;i<=n;++i)
        cout<<mp[1][i][0];
    cout<<'\n';
    for(int i=1;i<=n;++i)
        cout<<mp[1][i][1];
    cout<<'\n';
    return 0;
}