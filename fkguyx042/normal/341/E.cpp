#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005
using namespace std;
int ansx[N],ansy[N],ans,a[N],n,i,j,p,k,id[N],A[N],tot;
inline bool cmp(int A,int B) { return a[A]<a[B]; }
void solve()
{
	  sort(A+1,A+4,cmp);
	  for (;a[A[1]]>0;)
	{
		     int x=a[A[2]]/a[A[1]];
		     for (;x;x>>=1)
		         if (x&1) ++tot,ansx[tot]=A[1],ansy[tot]=A[2],
				 a[A[2]]-=a[A[1]],a[A[1]]*=2;
		         else ++tot,ansx[tot]=A[1],ansy[tot]=A[3],
		         a[A[3]]-=a[A[1]],a[A[1]]*=2;
		     sort(A+1,A+4,cmp);
	}
}
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]);
     for (i=1;i<=n;++i) 
       if (a[i]) id[++id[0]]=i;
     if (id[0]<2) { printf("-1\n"); exit(0); }
     for(;id[0]>2;)
    {
    	  A[1]=id[1]; A[2]=id[2]; A[3]=id[3];
    	  solve();
    	  id[0]=0; for (i=1;i<=n;++i) if (a[i]) id[++id[0]]=i;
    }
    printf("%d\n",tot);
    for(i=1;i<=tot;++i) printf("%d %d\n",ansx[i],ansy[i]);
}