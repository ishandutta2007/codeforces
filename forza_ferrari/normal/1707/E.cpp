#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[100001],lg[100001];
pair<int,int> st[41][21][100001];
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
inline pair<int,int> merge(pair<int,int> x,pair<int,int> y)
{
    return {min(x.first,y.first),max(x.second,y.second)};
}
inline pair<int,int> query(int id,int l,int r)
{
    if(l>=r)
        return {n,1};
    --r;
    int k=lg[r-l+1];
    return merge(st[id][k][l],st[id][k][r-(1<<k)+1]);
}
inline void build()
{
    for(int i=0;i<=40;++i)
    {
        if(i)
            for(int j=1;j<n;++j)
                st[i][0][j]=query(i-1,st[i-1][0][j].first,st[i-1][0][j].second);
        for(int j=1;j<=20;++j)
            for(int k=1;k+(1<<j)<=n;++k)
                st[i][j][k]=merge(st[i][j-1][k],st[i][j-1][k+(1<<(j-1))]);
    }
}
int main()
{
    n=read(),m=read();
    lg[0]=-1;
    for(int i=1;i<=n;++i)
    {
        lg[i]=lg[i>>1]+1;
        a[i]=read();
        if(i>1)
            st[0][0][i-1]={min(a[i-1],a[i]),max(a[i-1],a[i])};
    }
    build();
    while(m--)
    {
        int l=read(),r=read();
        if(l==1&&r==n)
        {
            cout<<"0\n";
            continue;
        }
        if(l==r)
        {
            cout<<"-1\n";
            continue;
        }
        long long ans=0;
        for(int i=40;~i;--i)
        {
            pair<int,int> tmp=query(i,l,r);
            if(tmp!=make_pair(1,n))
            {
                l=tmp.first;
                r=tmp.second;
                ans|=1ll<<i;
            }
        }
        ++ans;
        if(query(0,l,r)==make_pair(1,n))
            cout<<ans<<'\n';
        else
            cout<<"-1\n";
    }
    return 0;
}