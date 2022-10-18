#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<queue>
using namespace std;
struct element
{
    int c,q;
    bool operator <(const element &other) const
    {
        return q^other.q? q>other.q:c<other.c;
    }
}a[200001];
int root,n,m,tot,ch[200001][2],val[200001],key[200001],s[200001],tag[200001][2],ans[200001];
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
inline void push_up(int k)
{
    s[k]=s[ch[k][0]]+s[ch[k][1]]+1;
}
inline void push_down(int k)
{
    if(tag[k][0])
    {
        if(ch[k][0])
        {
            val[ch[k][0]]-=tag[k][0];
            tag[ch[k][0]][0]+=tag[k][0];
        }
        if(ch[k][1])
        {
            val[ch[k][1]]-=tag[k][0];
            tag[ch[k][1]][0]+=tag[k][0];
        }
        tag[k][0]=0;
    }
    if(tag[k][1])
    {
        if(ch[k][0])
        {
            ans[ch[k][0]]+=tag[k][1];
            tag[ch[k][0]][1]+=tag[k][1];
        }
        if(ch[k][1])
        {
            ans[ch[k][1]]+=tag[k][1];
            tag[ch[k][1]][1]+=tag[k][1];
        }
        tag[k][1]=0;
    }
}
inline int newnode(int w)
{
    s[++tot]=1;
    val[tot]=w;
    key[tot]=rand();
    return tot;
}
int merge(int x,int y)
{
    if(!x||!y)
        return x+y;
    push_down(x);
    push_down(y);
    if(key[x]<key[y])
    {
        ch[x][1]=merge(ch[x][1],y);
        push_up(x);
        return x;
    }
    ch[y][0]=merge(x,ch[y][0]);
    push_up(y);
    return y;
}
void split(int node,int k,int &x,int &y)
{
    if(!node)
    {
        x=y=0;
        return;
    }
    push_down(node);
    if(val[node]<=k)
    {
        x=node;
        split(ch[node][1],k,ch[node][1],y);
    }
    else
    {
        y=node;
        split(ch[node][0],k,x,ch[node][0]);
    }
    push_up(node);
}
void dfs(int k)
{
    if(!k)
        return;
    push_down(k);
    dfs(ch[k][0]);
    dfs(ch[k][1]);
}
int main()
{
    srand((unsigned)time(NULL));
    n=read();
    for(int i=1;i<=n;++i)
        a[i].c=read(),a[i].q=read();
    sort(a+1,a+n+1);
    m=read();
    for(int i=1;i<=m;++i)
    {
        int val=read(),x,y;
        split(root,val,x,y);
        root=merge(merge(x,newnode(val)),y);
    }
    for(int i=1;i<=n;++i)
    {
        int x,y,z,tmp;
        split(root,a[i].c-1,x,y);
        split(y,(a[i].c<<1)-1,y,z);
        tag[z][0]+=a[i].c;
        val[z]-=a[i].c;
        ++tag[z][1];
        ++ans[z];
        queue<int> q;
        q.push(y);
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            push_down(k);
            if(ch[k][0])
                q.push(ch[k][0]);
            if(ch[k][1])
                q.push(ch[k][1]);
            val[k]-=a[i].c;
            tag[k][0]=tag[k][1]=ch[k][0]=ch[k][1]=0;
            s[k]=1;
            ++ans[k];
            split(x,val[k],x,tmp);
            x=merge(merge(x,k),tmp);
        }
        root=merge(x,z);
    }
    dfs(root);
    for(int i=1;i<=m;++i)
        printf("%d ",ans[i]);
    puts("");
    return 0;
}