#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int T,n,m,p,cnt,dfn[400001],low[400001],num,col[400001];
bool vis[400001],inq[400001];
stack<int> t;
vector<int> v[400001];
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
inline void tarjan(int k)
{
    low[k]=dfn[k]=++cnt;
    vis[k]=inq[k]=1;
    t.emplace(k);
    for(int i:v[k])
        if(!dfn[i])
        {
            tarjan(i);
            low[k]=min(low[k],low[i]);
        }
        else if(inq[i])
            low[k]=min(low[k],dfn[i]);
    if(low[k]==dfn[k])
    {
        col[k]=++num;
        inq[k]=0;
        while(!t.empty()&&t.top()!=k)
        {
            col[t.top()]=num;
            inq[t.top()]=0;
            t.pop();
        }
        if(!t.empty())
            t.pop();
    }
}
inline int id(int x,int y,int tag)
{
    return (x-1)*p+y+tag*n*p;
}
inline void ban(int x,int w)
{
    if(w==1)
        v[id(x,1,0)].emplace_back(id(x,2,1));
    else
        v[id(x,w,0)].emplace_back(id(x,w-1,0));
    if(w==p)
        v[id(x,p,1)].emplace_back(id(x,p-1,0));
    else
        v[id(x,w,1)].emplace_back(id(x,w+1,1));
}
int main()
{
    T=read();
    while(T--)
    {
        n=read(),m=read(),p=read();
        while(!t.empty())
            t.pop();
        num=cnt=0;
        for(int i=1;i<=2*n*p;++i)
        {
            v[i].clear();
            col[i]=dfn[i]=low[i]=vis[i]=inq[i]=0;
        }
        for(int i=1;i<=n;++i)
            for(int j=2;j<=p;++j)
            {
                v[id(i,j-1,0)].emplace_back(id(i,j,0));
                v[id(i,j,1)].emplace_back(id(i,j-1,1));
            }
        for(int i=1;i<n;++i)
            for(int j=1;j<=p;++j)
            {
                v[id(i+1,j,0)].emplace_back(id(i,j,0));
                v[id(i,j,1)].emplace_back(id(i+1,j,1));
            }
        while(m--)
        {
            int opt=read();
            if(opt==1)
            {
                int x=read(),w=read();
                ban(x,w);
            }
            if(opt==2)
            {
                int x=read(),y=read(),w=read();
                if(x>y)
                    x^=y^=x^=y;
                for(int i=1;i<=p;++i)
                    if(w-i>=1&&w-i<=p)
                    {
                        if(i<=w-i)
                            v[id(x,i,1)].emplace_back(id(y,w-i,0));
                        if(w-i<=i)
                            v[id(y,i,1)].emplace_back(id(x,w-i,0));
                    }
                    else if(w-i<1)
                    {
                        ban(x,i);
                        ban(y,i);
                    }
            }
            if(opt==3)
            {
                int x=read(),y=read(),w=read();
                if(x>y)
                    x^=y^=x^=y;
                for(int i=1;i<=p;++i)
                    if(w-i>=1&&w-i<=p)
                    {
                        if(i<=w-i)
                            v[id(x,i,0)].emplace_back(id(y,w-i,1));
                        if(w-i<=i)
                            v[id(y,i,0)].emplace_back(id(x,w-i,1));
                    }
                    else if(w-i>p)
                    {
                        ban(x,i);
                        ban(y,i);
                    }
            }
        }
        for(int i=1;i<=2*n*p;++i)
        {
            //for(auto j:v[i])
                //cout<<i<<" "<<j<<'\n';
            if(!vis[i])
                tarjan(i);
        }
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            bool tag=0;
            for(int j=1;j<p;++j)
                if(col[id(i,j,0)]==col[id(i,j+1,1)])
                {
                    flag=0;
                    break;
                }
            if(!flag)
                break;
        }
        if(!flag)
        {
            cout<<"-1\n";
            continue;
        }
        int lst=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=lst;j<=p;++j)
                if(j==p||col[id(i,j,0)]<col[id(i,j+1,1)])
                {
                    cout<<(lst=j)<<" ";
                    break;
                }
        }
        cout<<'\n';
    }
    return 0;
}//