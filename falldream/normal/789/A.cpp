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

ll n,k;
ll ans=0;

int main()
{
    n=read();k=read();
    for(int i=1;i<=n;i++)
    {
        ll x=read();
        ans+=(x+k-1)/k;
    }
    cout<<(ans+1)/2;
    return 0;
}