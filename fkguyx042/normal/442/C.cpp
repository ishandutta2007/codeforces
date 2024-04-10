#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 500005

using namespace std;
int Q[N],l[N],r[N],a[N],vis[N],i,n;
long long ans;
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) l[i]=i-1,r[i]=i+1,scanf("%d",&a[i]); r[n]=0;
	 for (i=1;i;)
	  if (!l[i]||!r[i]) i=r[i];
	  else 
	  {
	     if (a[l[i]]>=a[i]&&a[r[i]]>=a[i]) 
		 {
		    ans+=min(a[l[i]],a[r[i]]);
		    r[l[i]]=r[i]; l[r[i]]=l[i];
		    vis[i]=1;
		    i=l[i];
		}
		else i=r[i];
	 }
	 for (i=1;i<=n;++i) if (!vis[i]) Q[++Q[0]]=a[i];
	 sort(Q+1,Q+Q[0]+1);
	 for (i=1;i<=Q[0]-2;++i) ans+=Q[i];
	 printf("%I64d\n",ans);
}