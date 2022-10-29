#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define fi first
#define se second
#define mk make_pair

#define N 2005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,a[N],b[N],Ans,ansy[N],ansx[N],totA,totB;
struct Node{long long sum; int x,y;}A[N*N],B[N*N];
long long sa,sb,ans;
inline bool cmp(Node a,Node b) { return a.sum<b.sum; }
void work(int x,int y)
{
	if (!y) return;
	long long Now=abs((sa-A[x].sum+B[y].sum)-(sb-B[y].sum+A[x].sum));
	if(Now<ans) ans=Now,Ans=2,ansx[1]=A[x].x,ansx[2]=A[x].y,ansy[1]=B[y].x,ansy[2]=B[y].y;
}
int main()
{
	  scanf("%d",&n); for (i=1;i<=n;++i) scanf("%d",&a[i]),sa+=a[i];
	  scanf("%d",&m); for (i=1;i<=m;++i) scanf("%d",&b[i]),sb+=b[i];
	  ans=abs(sa-sb);
	  for (i=1;i<=n;++i)
	     for (j=1;j<=m;++j)
	     {
	     	   sa-=a[i]-b[j];
	     	   sb-=b[j]-a[i];
	     	   if (abs(sa-sb)<ans) ans=abs(sa-sb),Ans=1,ansx[1]=i,ansy[1]=j;
	     	   sa+=a[i]-b[j];
	     	   sb+=b[j]-a[i];
	     }
	 long long Ch=(sa+sb)/2;
	 for (i=1;i<=n;++i)
	    for (j=i+1;j<=n;++j) 
	      A[++totA].sum=a[i]+a[j],A[totA].x=i,A[totA].y=j;
	 for (i=1;i<=m;++i)
	    for (j=i+1;j<=m;++j)
	      B[++totB].sum=b[i]+b[j],B[totB].x=i,B[totB].y=j;
	 sort(B+1,B+totB+1,cmp);
	 for (i=1;i<=totA;++i)
	 {
	 	  long long Need=min(B[totB].sum,Ch-(sa-A[i].sum));
	 	  int l=1,r=totB,mid=0;
	 	  while((l+r)>>1!=mid)
	 	  {
	 	  	 mid=(l+r)>>1;
	 	  	 if(B[mid].sum>=Need) r=mid;
	 	  	 else l=mid;
	 	  }
	 	  work(i,r);
	 	  work(i,r-1);
	 }
	 printf("%I64d\n",ans);
	 printf("%d\n",Ans);
	 for(i=1;i<=Ans;++i) printf("%d %d\n",ansx[i],ansy[i]);
}