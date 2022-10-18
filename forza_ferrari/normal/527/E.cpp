#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct edge
{
    int nxt,to;
    bool vis;
}e[200001<<2];
int n,m,tot=1,d[100001],cnt[100001][2],h[100001],cur[100001],lst;
vector<int> ans;
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
inline void print(int x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void dfs(int k)
{
    for(int i=cur[k];i;i=cur[k])
    {
        cur[k]=e[i].nxt;
        if(!e[i].vis)
        {
            e[i].vis=e[i^1].vis=1;
            dfs(e[i].to);
        }
    }
    ans.emplace_back(k);
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        ++d[x];
        ++d[y];
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;++i)
        if(d[i]&1)
            if(lst)
            {
                add(lst,i);
                add(i,lst);
                ++m;
                lst=0;
            }
            else
                lst=i;
    for(int i=1;i<=n;++i)
        cur[i]=h[i];
    dfs(1);
    for(int i=1;i<(int)ans.size();++i)
        if(i&1)
        {
            ++cnt[ans[i-1]][0];
            ++cnt[ans[i]][1];
        }
        else
        {
            ++cnt[ans[i-1]][1];
            ++cnt[ans[i]][0];
        }
    for(int i=1;i<=n;++i)
        if(cnt[i][0]&1)
            ++m;
    cout<<m<<'\n';
    for(int i=1;i<(int)ans.size();++i)
        if(i&1)
        {
            print(ans[i-1]);
            putchar(' ');
            print(ans[i]);
            putchar('\n');
        }
        else
        {
            print(ans[i]);
            putchar(' ');
            print(ans[i-1]);
            putchar('\n');
        }
    for(int i=1;i<=n;++i)
        if(cnt[i][0]&1)
        {
            print(i);
            putchar(' ');
            print(i);
            putchar('\n');
        }
    return 0;
}