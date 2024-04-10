#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 150010
#define ll long long
using namespace std;
int q[N],ql,qr,n;
void work(ll f[],ll g[],ll d)
{
    ql=qr=1;q[ql]=0;
    for(int i=1;i<=n;i++)
    {
        if(ql!=qr && i-q[ql]>d) ql++;
        while(ql!=qr && f[q[qr-1]]<=f[i]) qr--;
        q[qr++]=i;
        g[i]=f[q[ql]];
    }
    ql=qr=1;q[ql]=0;
    for(int i=n;i>=1;i--)
    {
        if(ql!=qr && q[ql]-i>d) ql++;
        while(ql!=qr && f[q[qr-1]]<=f[i]) qr--;
        q[qr++]=i;
        g[i]=max(g[i],f[q[ql]]);
    }
}
ll f[N],g[N];
int main()
{
    int m,d;
    scanf("%d%d%d",&n,&m,&d);
    int pre=1;
    for(int i=1;i<=m;i++)
    {
        int a;
        ll b,t;
        scanf("%d%lld%lld",&a,&b,&t);
        work(f,g,(t-pre)*d);
        swap(f,g);
        for(int j=1;j<=n;j++) f[j]+=b-abs(j-a);
        pre=t;
    }
    printf("%lld\n",*max_element(f+1,f+n+1));
    return 0;
}