#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1010
#define ll long long
using namespace std;
ll tot[10];
int f[N];
int main()
{
    ll w,s=0;
    scanf("%lld",&w);
    for(int i=1;i<=8;i++) scanf("%lld",&tot[i]),s+=tot[i]*i;
    if(s<w){printf("%lld\n",s);return 0;}
    s=w;
    for(int i=1;i<=8;i++)
    if(tot[i]>10 && w>1000)
    {
        ll p=(w-1000)/i;
        if(p>=tot[i]-10) w-=(tot[i]-10)*i,tot[i]=10;
        else w-=p*i,tot[i]-=p;
    }
    f[0]=1;
    for(int i=1;i<=8;i++)
        for(int j=w;j>=0;j--)
            for(int k=1;k<=tot[i] && i*k<=j;k++)
            f[j]|=f[j-i*k];
    int a=0;
    for(int j=w;j>=0;j--)
    if(f[j]){printf("%lld\n",s-(w-j));return 0;}
    return 0;
}