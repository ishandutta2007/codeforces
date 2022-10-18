#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int n,node[500001],cnt,a[500001],pos[500001][2],tot,ls[500001*20],rs[500001*20],root[500001];
stack<int> t;
long long sum[500001*20],ans;
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
    sum[k]=sum[ls[k]]+sum[rs[k]];
}
inline void update(int node,int l,int r,int id,int p)
{
    int k=++tot;
    root[id]=k;
    stack<int> st;
    st.push(k);
    while(l<r)
    {
        ls[k]=ls[p];
        rs[k]=rs[p];
        int mid=(l+r)>>1;
        if(node<=mid)
        {
            ls[k]=++tot;
            k=ls[k];
            p=ls[p];
            st.push(k);
            r=mid;
        }
        else
        {
            rs[k]=++tot;
            k=rs[k];
            p=rs[p];
            st.push(k);
            l=mid+1;
        }
    }
    sum[k]=sum[p]+1;
    st.pop();
    while(!st.empty())
    {
        push_up(t.top());
        st.pop();
    }
}
inline int query(int node,int l,int r,int x,int y)
{
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(node<=mid)
        {
            x=ls[x];
            y=ls[y];
            r=mid;
        }
        else
        {
            x=rs[x];
            y=rs[y];
            l=mid+1;
        }
    }
    return sum[y]-sum[x];
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        node[i]=a[i]=read();
        while(!t.empty()&&a[t.top()]<a[i])
        {
            pos[t.top()][1]=i;
            t.pop();
        }
        t.push(i);
    }
    while(!t.empty())
    {
        pos[t.top()][1]=n+1;
        t.pop();
    }
    for(int i=n;i>=1;--i)
    {
        while(!t.empty()&&a[t.top()]<=a[i])
        {
            pos[t.top()][0]=i;
            t.pop();
        }
        t.push(i);
    }
    sort(node+1,node+n+1);
    cnt=unique(node+1,node+n+1)-node-1;
    for(int i=1;i<=n;++i)
        a[i]=lower_bound(node+1,node+cnt+1,a[i])-node;
    for(int i=1;i<=n;++i)
        update(a[i],1,cnt,i,root[i-1]);
    for(int i=1;i<=n;++i)
        if(i-pos[i][0]<pos[i][1]-i)
            for(int j=pos[i][0]+1;j<=i;++j)
            {
                int val=lower_bound(node+1,node+cnt+1,node[a[i]]-node[a[j]])-node;
                if(node[val]==node[a[i]]-node[a[j]])
                    ans+=query(val,1,cnt,root[i-1],root[pos[i][1]-1]);
            }
        else
            for(int j=i;j<pos[i][1];++j)
            {
                int val=lower_bound(node+1,node+cnt+1,node[a[i]]-node[a[j]])-node;
                if(node[val]==node[a[i]]-node[a[j]])
                    ans+=query(val,1,cnt,root[pos[i][0]],root[i]);
            }
    cout<<ans<<'\n';
    return 0;
}