#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
struct element
{
    int k,pos,id;
    bool operator <(const element &other) const
    {
        return k<other.k;
    }
}q[200001];
struct node
{
    int val,pos;
    bool operator <(const node &other) const
    {
        return val^other.val? val>other.val:pos<other.pos;
    }
}a[200001];
int n,m,ans[200001],b[200001];
int root,tot,ch[100001][2],val[100001],key[100001],s[100001];
inline void push_up(int k)
{
    s[k]=s[ch[k][0]]+s[ch[k][1]]+1;
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
inline int kth(int node,int k)
{
    while(1)
    {
        if(k<=s[ch[node][0]])
            node=ch[node][0];
        else
        {
            if(k==s[ch[node][0]]+1)
                return node;
            k-=s[ch[node][0]]+1;
            node=ch[node][1];
        }
    }
}
int main()
{
    cin>>n;
    for(register int i=1;i<=n;++i)
    {
        cin>>a[i].val;
        a[i].pos=i;
        b[i]=a[i].val;
    }
    sort(a+1,a+n+1);
    cin>>m;
    for(register int i=1;i<=m;++i)
    {
        cin>>q[i].k>>q[i].pos;
        q[i].id=i;
    }
    sort(q+1,q+m+1);
    int pos=1;
    for(register int i=1;i<=m;++i)
    {
        while(tot<q[i].k)
        {
            int x=0,y=0;
            split(root,a[pos].pos,x,y);
            root=merge(x,merge(newnode(a[pos].pos),y));
            ++pos;
        }
        ans[q[i].id]=b[val[kth(root,q[i].pos)]];
    }
    for(register int i=1;i<=m;++i)
        cout<<ans[i]<<endl;
    return 0;
}