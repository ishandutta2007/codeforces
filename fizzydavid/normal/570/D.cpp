//by yjz
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
vector<int>pre[500111][26];
int n,q,p[500111],ti,l[500111],r[500111],dis[500111];
char s[500111];
vector<int>con[500111];
void dfs(int x)
{
    dis[x]=dis[p[x]]+1;
    l[x]=++ti;
    pre[dis[x]][s[x]-'a'].PB(l[x]);
    for(int i=0;i<con[x].size();i++)
    {
        dfs(con[x][i]);
    }
    r[x]=ti;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)scanf("%d",&p[i]),con[p[i]].PB(i);
    scanf("%s",s+1);
    dfs(1);
    for(int i=1;i<=q;i++)
    {
        int x,h;
        scanf("%d%d",&x,&h);
        bool odd=0,ok=1;
        for(int i=0;i<26;i++)
        {
            int cnt=(upper_bound(pre[h][i].begin(),pre[h][i].end(),r[x])-pre[h][i].begin())-
                    (lower_bound(pre[h][i].begin(),pre[h][i].end(),l[x])-pre[h][i].begin());
            if(cnt&1)
            {
                if(odd)
                {
                    ok=0;
                    break;
                }
                odd=1;
            }
        }
        if(ok)puts("Yes");else puts("No");
    }
    return 0;
}