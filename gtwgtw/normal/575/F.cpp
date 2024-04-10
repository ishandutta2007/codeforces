#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define N 5005
using namespace std;
long long f[2][N*2],ans;
int i,j,m,n,p,k,now,last,x,l[N],r[N],b[N*2];
long long dis(int x,int l,int r)
{
	  if (l<=x&&x<=r) return 0;
	  return min(abs(b[x]-b[l]),abs(b[x]-b[r]));
}
int main()
{
	 scanf("%d%d",&n,&x); b[++b[0]]=x;
	 for (i=1;i<=n;++i) scanf("%d%d",&l[i],&r[i]),b[++b[0]]=l[i],b[++b[0]]=r[i];
	 sort(b+1,b+b[0]+1);
	 b[0]=unique(b+1,b+b[0]+1)-(b+1);
	 memset(f,60,sizeof(f));
	 f[0][lower_bound(b+1,b+b[0]+1,x)-b]=0;
	 for (i=1;i<=n;++i)
	 {
	 	  now^=1; last=now^1;
	 	  memset(f[now],60,sizeof(f[now]));
	 	  int L=lower_bound(b+1,b+b[0]+1,l[i])-b,R=lower_bound(b+1,b+b[0]+1,r[i])-b;
	 	  long long Maxc=(long long)1e18;
	 	  for (j=1;j<=b[0];++j)
	 	  {
	 	  	   Maxc=min(Maxc,f[last][j]-b[j]);
	 	  	   f[now][j]=min(f[now][j],Maxc+b[j]);
 		  }
 		  Maxc=(long long)1e18;
 		  for (j=b[0];j;--j)
	 	  {
	 	  	  Maxc=min(Maxc,f[last][j]+b[j]);
	 	  	  f[now][j]=min(f[now][j],Maxc-b[j]);
		  }
		  for (j=1;j<=b[0];++j) f[now][j]+=dis(j,L,R);
	 }
	 ans=(long long)1e18;
	 for (i=1;i<=b[0];++i) ans=min(ans,f[now][i]);
	 cout<<ans<<endl;
}