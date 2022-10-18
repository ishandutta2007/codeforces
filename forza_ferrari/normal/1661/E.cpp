#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
string s;
int n,m,a[500001][3],lst,sum[500001],ans[500001];
vector<pair<int,int> > v[500001];
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
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int val)
{
    for(;x<=n;x+=lowbit(x))
        sum[x]+=val;
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x];
    return res;
}
int main()
{
    n=read();
    for(int i=0;i<3;++i)
    {
        cin>>s;
        s=" "+s;
        for(int j=1;j<=n;++j)
            a[j][i]=s[j]-'0';
    }
    m=read();
    for(int i=1;i<=m;++i)
    {
        int l=read(),r=read();
        v[r].emplace_back(l,i);
    }
    for(int i=1;i<=n;++i)
    {
        if(!a[i][0]&&!a[i][1]&&!a[i][2])
            lst=0;
        if(a[i][0]&&!a[i][1]&&!a[i][2])
        {
            update(i,1);
            update(i+1,-1);
            if(!a[i-1][0])
            {
                lst=0;
                update(1,1);
                update(i,-1);
            }
        }
        if(!a[i][0]&&a[i][1]&&!a[i][2])
        {
            update(i,1);
            update(i+1,-1);
            if(!a[i-1][1])
            {
                lst=0;
                update(1,1);
                update(i,-1);
            }
        }
        if(!a[i][0]&&!a[i][1]&&a[i][2])
        {
            update(i,1);
            update(i+1,-1);
            if(!a[i-1][2])
            {
                lst=0;
                update(1,1);
                update(i,-1);
            }
        }
        if(a[i][0]&&a[i][1]&&!a[i][2])
        {
            update(i,1);
            update(i+1,-1);
            if(!a[i-1][0]&&!a[i-1][1])
            {
                lst=0;
                update(1,1);
                update(i,-1);
            }
        }
        if(a[i][0]&&!a[i][1]&&a[i][2])
        {
            update(i,2);
            update(i+1,-2);
            if(!a[i-1][0])
            {
                lst=0;
                update(1,1);
                update(i,-1);
            }
            if(!a[i-1][2])
            {
                lst=0;
                update(1,1);
                update(i,-1);
            }
        }
        if(!a[i][0]&&a[i][1]&&a[i][2])
        {
            update(i,1);
            update(i+1,-1);
            if(!a[i-1][1]&&!a[i-1][2])
            {
                lst=0;
                update(1,1);
                update(i,-1);
            }
        }
        if(a[i][0]&&a[i][1]&&a[i][2])
        {
            update(i,1);
            update(i+1,-1);
            if(!a[i-1][0]&&!a[i-1][1]&&!a[i-1][2])
            {
                update(1,1);
                update(i,-1);
            }
            else if(a[i-1][0]&&!a[i-1][1]&&a[i-1][2])
            {
                update(lst+1,-1);
                update(i,1);
            }
            lst=i;
        }
        for(auto j:v[i])
            ans[j.second]=query(j.first);
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
    return 0;
}