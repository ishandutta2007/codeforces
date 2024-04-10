#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<bitset>

#define N 1000005

using namespace std;
int f[N],n,ans,i;
struct Node{int x,y;}a[N];
inline bool cmp(Node a,Node b)
{
	 return a.x<b.x;
}
int main()
{
	 scanf("%d",&n); ans=n;
	 for (i=1;i<=n;++i) scanf("%d%d",&a[i].x,&a[i].y);
	 sort(a+1,a+n+1,cmp);
	 for (i=1;i<=n;++i)
	 {
	 		  int l=1,r=i,mid=0;
	 		  while ((l+r)>>1!=mid)
	 		  {
	 		  	 mid=(l+r)>>1;
	 		  	 if (a[i].x-a[mid].x<=a[i].y) r=mid;
	 		  	 else l=mid;
	 		  }
	 		  f[i]=f[r-1]+(i-r);
	 		  ans=min(ans,f[i]+n-i);
	}
	printf("%d\n",ans);
}