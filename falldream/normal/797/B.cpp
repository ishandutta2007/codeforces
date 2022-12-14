#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define INF 2000000000
#define ll long long
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}

int n,s[100005],ans=0,mn=INF,mx=-INF,num=0;
bool flag=false;

int main()
{
    n=read();
    for(int i=1;i<=n;i++)s[i]=read();
    for(int i=1;i<=n;i++)
    {
        if(s[i]>0)
        {
            if(!(s[i]&1)) ans+=s[i];
            else flag=true,ans+=s[i],num++,mn=min(mn,s[i]);
        }
        else if(s[i]&1) mx=max(mx,s[i]);
    }
    if(!flag) ans+=mx;
    else if(!(num&1)) ans+=max(mx,-mn);
    cout<<ans;
    return 0;
}