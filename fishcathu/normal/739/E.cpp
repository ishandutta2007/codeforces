#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=2010;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
const double eps=1E-8;
int n,cnta,cntb;
double a[N],b[N],c[N];
double dp;
void check(double u,double v)
{
    dp=cnta=cntb=0;
    for(int i=1;i<=n;++i)
    {
        double t=0;
        int op=0;
        if(c[i]-u-v>t)
        {
            t=c[i]-u-v;
            op=3;
        }
        if(a[i]-u>t)
        {
            t=a[i]-u;
            op=1;
        }
        if(b[i]-v>t)
        {
            t=b[i]-v;
            op=2;
        }
        dp+=t;
        if(op&1)++cnta;
        if(op&2)++cntb;
    }
}
int main()
{
    n=read();
    int u=read(),v=read();
    for(int i=1;i<=n;++i)scanf("%lf",a+i);
    for(int i=1;i<=n;++i)scanf("%lf",b+i);
    for(int i=1;i<=n;++i)c[i]=a[i]+b[i]-a[i]*b[i];
    double ma,mb;
    for(double la=0,ra=1;ra-la>eps;)
    {
        ma=(la+ra)/2;
        for(double lb=0,rb=1;rb-lb>eps;)
        {
            mb=(lb+rb)/2;
            check(ma,mb);
            if(cntb==v)break;
            (cntb<v?rb:lb)=mb;
        }
        if(cnta==u)break;
        (cnta<u?ra:la)=ma;
    }
    printf("%.5f\n",dp+u*ma+v*mb);
}