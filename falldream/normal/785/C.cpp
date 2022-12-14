#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#include<cmath>
#define ll unsigned long long
#define double long double
#define INF 2000000000
#define eps 1e-8
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

ll n,m,size;

int main()
{
    n=read();m=read();
    if(n<=m)cout<<n;
    else
    {
        double mm=sqrt((double)n*2.0-(double)m*2.00+0.25)-0.5;
        m+=(ll)ceil(mm);
        cout<<m;
    }
    return 0;
}