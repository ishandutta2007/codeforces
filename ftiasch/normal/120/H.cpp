#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define maxn 205
#define maxm (205*400+5)

int head[maxn],next[maxm],vtx[maxm],totE;
map<string,int> hash;
int tot;
vector<string> v;
char str[1000];
int vis[maxm],Link[maxm],stamp;
string bak[maxm];
int n,ans[maxn];

inline int getId(string s)
{
    if (hash.count(s)) return hash[s];
    bak[tot]=s;
    return hash[s]=tot++;
}

inline void Add(int a,int b)
{
    vtx[totE]=b;
    next[totE]=head[a];
    head[a]=totE++;
}

inline void dfs(int i,string s)
{
    if (s.size()>4) return;
    if (s!="") v.push_back(s);
    if (!str[i]) return;
    
    dfs(i+1,s);
    dfs(i+1,s+str[i]);
}

inline bool Find(int u)
{
    for (int p=head[u];p;p=next[p]){
        int v=vtx[p];
        if (vis[v]==stamp) continue;
        vis[v]=stamp;
        if (Link[v]==-1 || Find(Link[v])){
            Link[v]=u;
            return true;
        }
    }
    return false;
}

inline bool match()
{
    memset(Link,-1,sizeof(Link));
    memset(vis,-1,sizeof(vis));
    stamp=0;
    for (int i=0;i<n;++i){
        ++stamp;
        if (!Find(i)) return false;
    }
    return true;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    hash.clear();
    tot=0;
    scanf("%d",&n);
    memset(head,0,sizeof(head));
    totE=2;
    for (int i=0;i<n;++i){
        scanf("%s",str);
        v.clear();
        dfs(0,"");
        sort(v.begin(),v.end());
        for (int j=0;j<v.size();++j)
        if (j==0 || v[j]!=v[j-1]){
            Add(i,getId(v[j]));
        }
    }
    
    if (!match()) puts("-1");
    else{
        for (int i=0;i<tot;++i)
        if (Link[i]!=-1){
            ans[Link[i]]=i;
        }
        
        for (int i=0;i<n;++i)
            printf("%s\n",bak[ans[i]].c_str());
    }
    return 0;
}