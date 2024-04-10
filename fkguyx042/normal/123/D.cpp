#include<cstdio>
#include<cstring>
using namespace std;
const int maxlen=500000;
int i,j,m,n,p,k,len,H[100005],Q[100005],r;
char c[500002];
long long ans;
int sa[3000001],rank[3000001],sum[500001],Trk[3000001],Orz[3000001],high[3000001];
void Sort(int j)
{  memset(sum,0,sizeof(sum));
   for (i=1;i<=len;i++) sum[rank[i+j]]++;
   for (i=1;i<=maxlen;i++) sum[i]+=sum[i-1];
   for (i=len;i;i--)
     Orz[sum[rank[i+j]]--]=i;
   memset(sum,0,sizeof(sum));
   for (i=1;i<=len;i++) sum[rank[i]]++;
   for (i=1;i<=maxlen;i++) sum[i]+=sum[i-1];
   for (i=len;i;i--)
   sa[sum[rank[Orz[i]]]--]=Orz[i];
} 
void get_High()
{  int i,j;
   for (i=1,j=0;i<=len;i++)
   {  if (rank[i]==1) continue;
      while (c[i+j-1]==c[sa[rank[i]-1]+j-1]) j++;
      high[rank[i]]=j; if (j>0) j--;
}
}
void get_SA()
{  int i,j,p,k;
   for (i=1;i<=len;i++) Trk[i]=c[i-1];
   for (i=1;i<=len;i++) sum[Trk[i]]++;
   for (i=1;i<=maxlen;i++) sum[i]+=sum[i-1];
   for (i=len;i;i--) sa[sum[Trk[i]]--]=i; 
   rank[sa[1]]=1;
   for (i=2,p=1;i<=len;i++) 
   {  if (Trk[sa[i]]!=Trk[sa[i-1]]) p++;
        rank[sa[i]]=p;
   }
   for (j=1;j<=len;j*=2) {
     Sort(j);
    Trk[sa[1]]=1;
    for (i=2,p=1;i<=len;i++)
    {  if (rank[sa[i]]!=rank[sa[i-1]]||rank[sa[i]+j]!=rank[sa[i-1]+j]) p++;
       Trk[sa[i]]=p;
    }
    for (i=1;i<=len;i++) rank[i]=Trk[i];
    j++;j--;
}
}
long long sqr(int x) { return 1ll*x*x; }
int main()
{ 
   scanf("%s",&c);
   len=strlen(c);
   get_SA();
   get_High(); 
   H[1]=0; Q[1]=1;
   H[2]=len-sa[1]+1; Q[2]=1; r=2; ans=1ll*len*(len+1)/2;
   for (i=2;i<=len;++i)
   {
         while (H[r]>high[i])
         {
             if (H[r-1]<high[i]) 
             {
                 ans+=1ll*(H[r]-high[i])*sqr(i-Q[r]);
                 H[r]=high[i]; 
             }
             else 
             {
                 ans+=1ll*(H[r]-H[r-1])*sqr(i-Q[r]);
                 --r;
             }
         } 
         if (H[r]!=len-sa[i]+1) ++r,H[r]=len-sa[i]+1,Q[r]=i;
   }
   for (;r>1;)
   {
    ans+=1ll*(H[r]-H[r-1])*sqr(len+1-Q[r]);
    --r;
   }
   printf("%I64d\n",ans/2);
 //  for (;;);
}