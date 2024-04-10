#include<iostream>
#include<cstdio>
#include<cstring>
#define N 300010
#define ll long long
using namespace std;
const int B=383,BL=N/B+2;
int n,M;
struct block{
    ll bl[BL],f[BL][B+2];
    void add(int v,int w=1)
    {
        int p=v/B;
        // if(p>=BL){cerr<<v<<endl;throw;}
        for(int i=0;i<p;i++) bl[i]+=w;
        for(int i=0;i<=v%B;i++) f[p][i]+=w;
    }
    ll qry(int v)
    {
        int p=v/B;
        // if(p>=BL){cerr<<v<<endl;throw;}
        return bl[p]+f[p][v%B];
    }
}b1,b2;
int p[N];
ll f[B+1],g[B+1];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]),M=max(M,p[i]);
    ll sum=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        ll res=0;int m=M/p[i];
        if(p[i]<B) res=f[p[i]];
        else
        {
            res=sum;
            for(int j=0;j<=M;j+=p[i])
            res-=1ll*p[i]*(j/p[i])*(b1.qry(j)-b1.qry(min(j+p[i],M+1)));
            // printf("%d,%d : %lld %lld\n",j,j+p[i],b1.qry(j),b1.qry(j+p[i]));
        }
        b1.add(p[i]);
        ll res2=0;
        if(p[i]<B) res2=g[p[i]];
        else
        {
            res2=1ll*(i-1)*p[i];
            for(int l=1,r=0;l<=p[i];l=r+1)
            {
                r=p[i]/(p[i]/l);
                res2-=(p[i]/l)*(b2.qry(l)-b2.qry(r+1));
                // printf("%d,%d : %lld %lld\n",l,r+1,b2.qry(l),b2.qry(r+1));
            }
        }
        b2.add(p[i],p[i]);
        printf("%lld ",ans+=res+res2);
        for(int j=1;j<B;j++) f[j]+=p[i]%j;
        for(int j=1;j<B;j++) g[j]+=j%p[i];
        sum+=p[i];
    }
    return 0;
}