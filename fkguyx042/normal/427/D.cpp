#include<cstdio>
#include<algorithm>
#include<cstring>
#define Maxn 100000
using namespace std;
int i,j,m,n,p,k,L,len,Len;
int sa[100005],rank[100005],Orz[100005],tri[100005],G[100005],high[100005];
char s[50005],c[50005],final[50005];
void Sort(int j)
{ 
     int i;
     memset(Orz,0,sizeof(Orz));
     for (i=1;i<=L;i++) Orz[rank[i+j]]++;
     for (i=1;i<=Maxn;i++) Orz[i]+=Orz[i-1];
	 for (i=L;i;i--) G[Orz[rank[i+j]]--]=i;
	 memset(Orz,0,sizeof(Orz));
	 for (i=1;i<=L;i++) Orz[rank[i]]++;
	 for (i=1;i<=Maxn;i++) Orz[i]+=Orz[i-1];
	 for (i=L;i;i--) sa[Orz[rank[G[i]]]--]=G[i];
}
void get_SA()
{
	   for (i=1;i<=L;i++) tri[i]=final[i];
	   for (i=1;i<=L;i++) Orz[tri[i]]++;
	   for (i=1;i<=Maxn;i++) Orz[i]+=Orz[i-1];
	   for (i=L;i;i--) sa[Orz[tri[i]]--]=i;
	   rank[sa[1]]=1;
	   for (i=2,p=1;i<=L;i++)
	   {
	   	   if (tri[sa[i]]!=tri[sa[i-1]]) ++p;
	   	   rank[sa[i]]=p;
	   }
	   for (j=1;j<=L;j*=2)
	   {
	   	  Sort(j);
	   	  tri[sa[1]]=1;
	   	  for (i=2,p=1;i<=L;i++) {
			   if (rank[sa[i]]!=rank[sa[i-1]]||rank[sa[i]+j]!=rank[sa[i-1]+j]) p++;
	   	      tri[sa[i]]=p;
	       }
	       memcpy(rank,tri,sizeof(tri));
	}
}
void get_High()
{
	  int i,j;
	  for (i=1,j=0;i<=L;i++)
	{ 
	    if (rank[i]==1) continue;
	    while (final[i+j]==final[sa[rank[i]-1]+j]) j++;
	    high[rank[i]]=j; if (j) j--;
    }
}

int main()
{ 
   scanf("%s",&c);
   scanf("%s",&s);
   len=strlen(c);
   Len=strlen(s); 
   for (i=0;i<len;i++) final[++L]=c[i];
   final[++L]='$';
   for (i=0;i<Len;i++) final[++L]=s[i];
   get_SA();
   get_High();
//high[L+1]=high[L]-1;
  int ans=100000;
  for (i=2;i<=L;i++)
  if (sa[i]<=len&&sa[i-1]>len+1||sa[i]>len+1&&sa[i-1]<=len)
  {
  	      if (high[i]>high[i-1]&&high[i]>high[i+1])
  	         ans=min(ans,max(high[i-1],high[i+1])+1);
  }
  if (ans==100000) printf("-1\n");
  else printf("%d\n",ans);
}