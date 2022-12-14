#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int b1,q,l,m;
map<int,bool> mp;

inline int abs(int x){return x<0?-x:x;}

int main()
{
    b1=read();q=read();l=read();m=read();
    if(abs(b1)>l) return 0*puts("0");
    for(int i=1;i<=m;i++)mp[read()]=1;
    if(b1==0)
    {
        if(mp[0])return 0*puts("0");
        else return 0*puts("inf");
    }
    if(q==0)
    {
        if(!mp[0])return 0*puts("inf");
        if(abs(b1)<=l&&!mp[b1]) return 0*puts("1");
        puts("0");
        return 0;
    }
    if(q==1)
    {
        if(abs(b1)<=l&&!mp[b1])return 0*puts("inf");
        else return 0*puts("0");
    }
    if(q==-1)
    {
        int ans=0;
        if(abs(b1)<=l&&!mp[b1])ans++;
        if(abs(b1)<=l&&!mp[-b1]) ans++;
        if(ans) return 0*puts("inf");
        else return 0*puts("0");
    }
    else
    {
        int ans=(abs(b1)>l||mp[b1])?0:1;
        while(1LL*abs(q)*abs(b1)<=(ll)l)
        {
            b1*=q;
            if(abs(b1)<=l&&!mp[b1])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}