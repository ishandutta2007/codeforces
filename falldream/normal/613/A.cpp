#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MN 100000
const double pi=acos(-1);
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,x,y,X[MN+5],Y[MN+5];
double mx=0,mn=1e18;
inline long long Abs(long long x){return x<0?-x:x;}
int main()
{
    n=read();x=read();y=read();
    for(int i=1;i<=n;++i)
    {
        X[i]=read();Y[i]=read();
        long long d=1LL*(X[i]-x)*(X[i]-x)+1LL*(Y[i]-y)*(Y[i]-y);
        mn=min(mn,sqrt(d));mx=max(mx,sqrt(d));
    }
    X[0]=X[n];Y[0]=Y[n];
    for(int i=0;i<n;++i)
    {
        if(1LL*(X[i+1]-X[i])*(x-X[i])+1LL*(Y[i+1]-Y[i])*(y-Y[i])>=0&&
           1LL*(X[i]-X[i+1])*(x-X[i+1])+1LL*(Y[i]-Y[i+1])*(y-Y[i+1])>=0)
        {
            long long S=Abs(1LL*(X[i]-x)*(Y[i+1]-y)-1LL*(X[i+1]-x)*(Y[i]-y));
            mn=min(mn,S/sqrt(1LL*(X[i]-X[i+1])*(X[i]-X[i+1])+1LL*(Y[i]-Y[i+1])*(Y[i]-Y[i+1])));
        }
    }
    printf("%.10lf\n",pi*(mx*mx-mn*mn));
    return 0;
}