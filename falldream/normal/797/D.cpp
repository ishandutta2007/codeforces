#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define INF 2000000000
#define MN 100000
#define ll long long
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}

int n,L[MN+5],R[MN+5],s[MN+5],in[MN+5],ans=0;
map<int,bool> mp;

void dfs(int x,int l,int r)
{
    if(s[x]>=l&&s[x]<=r) mp[s[x]]=1;
    if(L[x]!=-1) dfs(L[x],l,min(s[x]-1,r));
    if(R[x]!=-1) dfs(R[x],max(l,s[x]+1),r);
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        s[i]=read();L[i]=read();R[i]=read();
        if(L[i]!=-1) in[L[i]]++;
        if(R[i]!=-1) in[R[i]]++;
    }
    for(int i=1;i<=n;i++)
        if(!in[i]) dfs(i,0,INF);
    for(int i=1;i<=n;i++) if(!mp[s[i]]) ans++;
    cout<<ans;
    return 0;
}