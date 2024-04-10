#include<cstdio>
#include<iostream>
#define LL long long
LL exp(int a,int b,int c)
{ 
    if (b==1) return a%c;
    LL d=exp(a,b/2,c);
    d=d*d%c;
    if (b&1) d=d*a%c;
    return d;
}
inline int check(int n,int k)
{
    int m=n-1;
    while (m%2==0) m/=2;
    LL p=exp(k,m,n);
    while (m<n-1&&p!=1&&p!=n-1)
    {
        m*=2;p=p*p%n;
    }
    return (p==1||p==n-1);
}
inline int isprime(int n)
{
    if (n==2||n==3||n==5||n==7||n==61) return 1;
    if (!check(n,2)) return 0;
    if (!check(n,3)) return 0;
    if (!check(n,5)) return 0;
    if (!check(n,7)) return 0;
    if (!check(n,61)) return 0;
    return 1;
}
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
int main()
{
    int tt;
    scanf("%d",&tt);    
    while (tt--)
    {
        int n;
        scanf("%d",&n);
        int p=n,q=n+1;
        while (!isprime(p)) p--;
        while (!isprime(q)) q++;
        LL a=2LL*(n-p-q+1)+1LL*p*q;
        LL b=2LL*p*q;
        LL c=gcd(a,b);
        a/=c;b/=c;
        printf("%I64d/%I64d\n",a,b);
    }
    return 0;
}