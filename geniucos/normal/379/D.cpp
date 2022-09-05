#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int i,n,m,fib,cate,s[4][4];
long long lima,limb,sta,stb,X,Y,D,ce,c1,c2,A,B,a[54],b[54],c[54],d[54],e[54],f[54],g[54],h[54];
int mod(int a)
{
    if(a<0) return -a;
    return a;
}
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int Lim(int c1,int c2,int l)
{
    if(l==1) return 0;
    if(l%2==0)
    {
        if(c1==0&&c2==1) return l/2;
        return l/2-1;
    }
    if(c1==0||c2==1) return l/2;
    return l/2-1;
}
long long gcd(long long a,long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long cd,x0,y0,d=gcd(b,a%b,x0,y0);
    x=y0;
    y=(long long)x0-(1LL*y0*(a/b));
    return d;
}
void af(int a1)
{
    if(a1==0) printf("A");
    else
    if(a1==1) printf("C");
    else printf("D");
}
void afis(int n,int ap1,int a1,int b1)
{
    if(n==2*ap1)
    {
        for(i=1;i<=n/2;i++)
            printf("AC");
        printf("\n");
        return ;
    }
    if(n%2==0)
    {
        af(a1);
        for(i=1;i<=ap1;i++)
            printf("AC");
        for(i=n-2-2*ap1;i>=1;i--)
            printf("D");
        af(b1);
        printf("\n");
        return ;
    }
    if(ap1==n/2)
    {
        if(a1==0)
        {
            for(i=1;i<=ap1;i++)
                printf("AC");
            af(b1);
        }
        else
        {
            af(a1);
            for(i=1;i<=ap1;i++)
                printf("AC");
        }
        printf("\n");
        return ;
    }
    af(a1);
    for(i=1;i<=ap1;i++)
        printf("AC");
    for(i=n-2*ap1-2;i>=1;i--)
        printf("D");
    af(b1);
    printf("\n");
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&fib);
scanf("%d",&cate);
scanf("%d",&n);
scanf("%d",&m);
f[1]=f[2]=1;
for(i=3;i<=fib;i++)
    f[i]=f[i-1]+f[i-2];
a[1]=1;
b[1]=0;
c[1]=d[1]=0;
e[1]=f[1]=1;

a[2]=0;
b[2]=1;
c[2]=d[2]=0;
e[2]=f[2]=2;
for(i=3;i<=fib;i++)
{
    a[i]=a[i-1]+a[i-2];
    b[i]=b[i-1]+b[i-2];
    c[i]=c[i-1]+c[i-2]+(f[i-2]==1&&e[i-1]==2);
    d[i]=d[i-1]+d[i-2]+(f[i-2]==2&&e[i-1]==1);
    e[i]=e[i-2];
    f[i]=f[i-1];
    g[i]=g[i-1]+g[i-2]+(f[i-2]==1&&e[i-1]==1);
    h[i]=h[i-1]+h[i-2]+(f[i-2]==2&&e[i-1]==2);
}
for(s[1][1]=0;s[1][1]<=2;s[1][1]++)
    for(s[1][2]=0;s[1][2]<=2;s[1][2]++)
        for(s[2][1]=0;s[2][1]<=2;s[2][1]++)
            for(s[2][2]=0;s[2][2]<=2;s[2][2]++)
            {
                if(s[1][1]==s[1][2]&&s[1][1]==2&&s[2][1]==1&&s[2][2]==0)
                    h[0]=0;
                if(n==1&&s[1][1]!=s[1][2]) continue;
                if(m==1&&s[2][1]!=s[2][2]) continue;
                lima=Lim(s[1][1],s[1][2],n);
                limb=Lim(s[2][1],s[2][2],m);
                sta=stb=0;
                if(n==2&&s[1][1]==0&&s[1][2]==1) sta=1;
                if(m==2&&s[2][1]==0&&s[2][2]==1) stb=1;
                ce=(long long)cate-1LL*c[fib]*(s[1][2]==0&&s[2][1]==1)-1LL*d[fib]*(s[2][2]==0&&s[1][1]==1)-
                                   1LL*g[fib]*(s[1][2]==0&&s[1][1]==1)-1LL*h[fib]*(s[2][2]==0&&s[2][1]==1);
                if(ce<0) continue;
                A=a[fib];
                B=b[fib];
                for(c1=sta;c1<=lima;c1++)
                    for(c2=stb;c2<=limb;c2++)
                        if(1LL*c1*A+1LL*c2*B==ce)
                        {
                            afis(n,c1,s[1][1],s[1][2]);
                            afis(m,c2,s[2][1],s[2][2]);
                            return 0;
                        }
            }
printf("Happy new year!\n");
return 0;
}