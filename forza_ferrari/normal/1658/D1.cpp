#include<iostream>//
#include<cstdio>
using namespace std;
int t,l,r,a[1<<18],tot,ch[1<<18][2];
inline void insert(int x)
{
    int node=0;
    for(int i=17;~i;--i)
    {
        if(!ch[node][x>>i&1])
            ch[node][x>>i&1]=++tot;
        node=ch[node][x>>i&1];
    }
}
inline int query1(int x)
{
    int node=0,res=0;
    for(int i=17;~i;--i)
        if(ch[node][x>>i&1])
            node=ch[node][x>>i&1];
        else
        {
            res|=1<<i;
            node=ch[node][x>>i&1^1];
        }
    return res;
}
inline int query2(int x)
{
    int node=0,res=0;
    for(int i=17;~i;--i)
        if(ch[node][x>>i&1^1])
        {
            node=ch[node][x>>i&1^1];
            res|=1<<i;
        }
        else
            node=ch[node][x>>i&1];
    return res;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        for(int i=1;i<=r-l+1;++i)
        {
            cin>>a[i];
            insert(a[i]);
        }
        for(int i=1;i<=r-l+1;++i)
            if(query1(a[i]^l)==l&&query2(a[i]^l)==r)
            {
                cout<<(a[i]^l)<<'\n';
                break;
            }
        for(int i=0;i<=tot;++i)
            ch[i][0]=ch[i][1]=0;
        tot=0;
    }
    return 0;
}