#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        ll m,d,w;
        scanf("%lld%lld%lld",&m,&d,&w);
        if(d==1){puts("0");continue;}
        m=min(m,d);
        w=w/gcd(w,d-1);
        ll q=m/w,r=m%w;
        printf("%lld\n",w*q*(q-1)/2+r*q);
    }
    return 0;
}