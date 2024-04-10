#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>

#define seed 233
#define Seed 2666667
#define Mo 998244353
#define N 25
using namespace std;
map<int,int>mp;
int hash[N],Ans[N],pow[N],i,j,sum,ansx,ansy,ans,flag,n,m,k,l,a,b,Q[10];
char c[N][N];
int main()
{
  scanf("%d%d",&n,&m);
  ansx=n,ansy=m;
  for (i=0;i<n;++i)
    scanf("%s",c[i]);
  for (i=1;i<=n;++i)
    if (n%i==0)
     for (j=1;j<=m;++j)
       if (m%j==0)
       {
       	   mp.clear(); flag=0;
       	     for (k=0;k<n;k+=i)
       	     if (!flag)
       	         for (l=0;l<m;l+=j)
       	         if (!flag)
       	           {
       	           	  int sum=0;
       	               for (a=k;a<k+i;++a)
       	               {
       	                  for (b=l;b<l+j;++b)
       	                      sum=(1ll*sum*seed%Mo+c[a][b])%Mo;
       	                      sum=1ll*sum*Seed%Mo;
       	               }
       	                Q[1]=sum; sum=0;
       	               for (a=k+i-1;a>=k;--a)
       	               {
       	                  for (b=l+j-1;b>=l;--b)
       	                      sum=(1ll*sum*seed%Mo+c[a][b])%Mo;
       	                      sum=1ll*sum*Seed%Mo;
       	               }
       	                Q[2]=sum; sum=0;
       	                for (b=l+j-1;b>=l;--b)
       	                {
       	                   for (a=k;a<k+i;++a)
       	                      sum=(1ll*sum*seed%Mo+c[a][b])%Mo;
       	                   sum=1ll*sum*Seed%Mo;
       	                }
       	                Q[3]=sum; sum=0;
       	                for (b=l;b<l+j;++b)
       	                {
       	                 for (a=k+i-1;a>=k;--a)
       	                      sum=(1ll*sum*seed%Mo+c[a][b])%Mo;
       	                      sum=1ll*sum*Seed%Mo;
       	                }
       	                Q[4]=sum; sum=0;
       	                sort(Q+1,Q+5);
       	                Q[0]=unique(Q+1,Q+5)-(Q+1);
       	                for (a=1;a<=Q[0];++a)
       	                    if (!mp[Q[a]])
       	                  {
       	                  	  mp[Q[a]]=1;
       	                  }
       	                  else flag=1;
       	           }
       	    if (!flag) 
       	    {
       	    	 ans++;
       	    	 if (i*j<ansx*ansy||i*j==ansx*ansy&&i<ansx) ansx=i,ansy=j;
       	    }
       }
       printf("%d\n",ans);
       printf("%d %d\n",ansx,ansy);
}