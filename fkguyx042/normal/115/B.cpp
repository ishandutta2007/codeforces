#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 255

using namespace std;
int n,m,i,l[N],r[N],j,ans;
char c[N][N];
int main()
{
	 scanf("%d%d",&n,&m);
	 for (i=0;i<n;++i)
	 {
	   scanf("%s",c[i]);
	   l[i]=m+1,r[i]=-1;
	   for (j=0;j<m;++j)
	     if (c[i][j]=='W') l[i]=min(l[i],j),r[i]=max(r[i],j);
	 }
	 while (n>1&&l[n-1]==m+1) --n;
	 l[n]=m+1; r[i]=-1;
	 int now=0;
	 for (i=0;i<n;++i)
	  if (i&1)
	  {
	  	 int next=min(now,min(l[i],l[i+1]));
	  	 ans+=(now-next+1);
	  	 now=next;
	  }
	  else
	  {
	  	 int next=max(now,max(r[i],r[i+1]));
	  	 ans+=(next-now+1);
	  	 now=next;
	  }
	  printf("%d\n",ans-1);
}