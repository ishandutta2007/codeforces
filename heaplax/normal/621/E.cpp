#include<stdio.h>  
#include<algorithm>   
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<cstdio>
#define sc(x) scanf("%I64d",&x)
#define pr(x) printf("%I64d",x)
#define prr(x) printf("%I64d\n",x);
#define prrr(x) printf("%I64d ",x);
void quick(long long  k,long long n);
void juz(int k);
void chu();
const long long E=1e9+7;
typedef long long ll;
ll aa[20];
ll ju[200][200];
ll bb[200];
ll vv[200];
ll we[200];
ll mm[200][200];
ll rm[200][200];
using namespace std;
int main(void)
{
    ll i,j,k,p,q,n,m;
    while(scanf("%I64d %I64d %I64d %I64d",&k,&p,&q,&n)!=EOF)
    {
        memset(aa,0,sizeof(aa));
        memset(ju,0,sizeof(ju));
        memset(we,0,sizeof(we));
        memset(bb,0,sizeof(bb));
        memset(vv,0,sizeof(vv));
        for(i=0; i<k; i++)
        {
            scanf("%I64d",&m);
            aa[m]++;
        }
        for(i=0; i<10; i++)
        {
            bb[i%n]=(aa[i]+bb[i%n])%E;
        }
        memset(rm,0,sizeof(rm));
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(i==j)
                {if(bb[i]!=0)
                  rm[i][j]=1;
                  vv[i]=1;
                }
            }
        }
        if(p==1)
        {
            prr(bb[q]);
        }
        else
        {
            juz(n);
            quick(p,n);

            we[0]=1;
            prr(mm[0][q]);
        }
    }
    return 0;

}

void juz(int k)
{
    int i,j,p,q;
    ll dd[200];
    memset(dd,0,sizeof(dd));
    dd[0]=1;
    memset(ju,0,sizeof(ju));
    for(i=0; i<=k-1; i++)
    for(j=0; j<=k-1; j++)
    for(p=0; p<=k-1; p++)
    if((10*j+p)%k==i)
    {ju[j][i]=(ju[j][i]+bb[p])%E;
    }
}

void quick(ll k,ll n)
{
   int i,j,p,q;
   ll nn[200][200];
   memset(mm,0,sizeof(mm));

   chu();
   while(k)
   {memset(nn,0,sizeof(nn));
    if(k&1)
    {
    for(i=0;i<=n-1;i++)
    for(j=0;j<=n-1;j++)
    for(int s=0;s<=n-1;s++)
    nn[i][j]=(((ju[i][s]%E)*(mm[s][j]%E))%E+nn[i][j])%E;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    mm[i][j]=nn[i][j];
    }memset(nn,0,sizeof(nn));
    for(i=0;i<=n-1;i++)
    for(j=0;j<=n-1;j++)
    for(int s=0;s<=n-1;s++)
    nn[i][j]=(((ju[i][s]%E)*(ju[s][j]%E))%E+nn[i][j])%E;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    ju[i][j]=nn[i][j];
    k/=2;
   }
}
void chu()
{int i,j,k,p,q;
for(i=0;i<=200;i++)
for(j=0;j<=200;j++)
    if(i==j)
    mm[i][j]=1;
}