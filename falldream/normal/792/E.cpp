#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
#define INF 100000000000000LL
#define ll long long
#define MN 100000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int n,s[1005];
ll ans=INF,size;ll mn=INF;

void calc(int x)
{
    if(!x) return ;size=0;
    for(int i=1;i<=n;i++)
    {
        int mod=s[i]%x,div=s[i]/x;
        if(mod>div)return;
        size+=(s[i]+x)/(x+1);
    }
    ans=min(ans,size);
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)s[i]=read(),mn=min(mn,(ll)s[i]);
    for(int i=1,last;i<=mn;i=last+1)
    {
        last=mn/(mn/i);int ques=mn/i;
        calc(ques);calc(ques-1);
        //calc(ques+1);
    }
    cout<<ans;
    return 0;
}