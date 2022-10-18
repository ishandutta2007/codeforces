#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;
struct edge
{
    int nxt,to;
}e[101<<1];
int n,len[101],tot,h[101],dep[101],d[101],deep;
string s[101];
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void topo()
{
    queue<int> q;
    for(register int i=0;i<26;++i)
        if(!d[i])
        {
            q.push(i);
            dep[i]=1;
        }
    deep=1;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        for(register int i=h[k];i;i=e[i].nxt)
            if(!--d[e[i].to])
            {
                q.push(e[i].to);
                dep[e[i].to]=dep[k]+1;
                deep=max(deep,dep[e[i].to]);
            }
    }
}
int main()
{
    cin>>n;
    for(register int i=1;i<=n;++i)
    {
        cin>>s[i];
        len[i]=s[i].length();
    }
    for(register int i=1;i<n;++i)
    {
        int maxn=min(len[i],len[i+1]);
        bool flag=0;
        for(register int j=0;j<maxn;++j)
            if(s[i][j]^s[i+1][j])
            {
                add(s[i][j]-'a',s[i+1][j]-'a');
                ++d[s[i+1][j]-'a'];
                flag=1;
                break;
            }
        if(!flag)
            if(len[i]>len[i+1])
            {
                puts("Impossible");
                return 0;
            }
    }
    topo();
    for(register int i=0;i<26;++i)
        if(!dep[i])
        {
            puts("Impossible");
            return 0;
        }
    for(register int i=1;i<=deep;++i)
        for(register int j=0;j<26;++j)
            if(dep[j]==i)
                putchar(j+'a');
    puts("");
    return 0;
}