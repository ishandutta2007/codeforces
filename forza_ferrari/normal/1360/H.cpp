#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,m,ch[10001][2],s[10001],tot;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)|(c^48);
        c=getchar();
    }
    return x;
}
inline void insert(int x)
{
    int node=1;
    for(int i=m-1;~i;--i)
    {
        if(!ch[node][x>>i&1])
            ch[node][x>>i&1]=++tot;
        node=ch[node][x>>i&1];
    }
    ++s[node];
}
inline int query(int p)
{
    int node=1,res=0;
    for(int i=m-1;~i;--i)
    {
        if(ch[node][0])
        {
            if(p<=(1ll<<i)-s[ch[node][0]])
                node=ch[node][0];
            else
            {
                res|=1ll<<i;
                p-=(1ll<<i)-s[ch[node][0]];
                node=ch[node][1];
            }
        }
        else
        {
            if(p<=1ll<<i)
                node=ch[node][0];
            else
            {
                res|=1ll<<i;
                p-=1ll<<i;
                node=ch[node][1];
            }
        }
    }
    return res;
}
signed main()
{
    cin>>t;
    tot=1;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            insert(read());
        for(int i=tot;i;--i)
            s[i]+=s[ch[i][0]]+s[ch[i][1]];
        int res=query(((1ll<<m)-n+1)/2);
        for(int i=m-1;~i;--i)
            cout<<(res>>i&1);
        cout<<'\n';
        for(int i=1;i<=tot;++i)
            s[i]=ch[i][0]=ch[i][1]=0;
        tot=1;
    }
    return 0;
}