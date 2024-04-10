#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 3005

using namespace std;
int i,j,m,n,p,k,sum[N][N],a[N][N],b[N][N],Q[100005];
struct Node{int sx,sy,ex,ey;}A[100005];
int getsum(int sx,int sy,int ex,int ey)
{
	 int Sum=sum[ex][ey];
	 Sum-=sum[sx-1][ey];
	 Sum-=sum[ex][sy-1];
	 Sum+=sum[sx-1][sy-1];
	 return Sum;
}
void pt(int sx,int sy,int ex,int ey)
{
	int i;
	for (i=1;i<=n;++i)
	  if (A[i].sx>=sx&&A[i].ex<=ex&&A[i].sy>=sy&&A[i].ey<=ey) Q[++Q[0]]=i;
	printf("YES %d\n",Q[0]);
	for (i=1;i<=Q[0];++i) printf("%d ",Q[i]);
	exit(0);
}
inline int read()
{
	int x; char c;
	while (c=getchar(),c<'0'||c>'9');
	x=c-'0';
	while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
	return x;
}
int main()
{
   scanf("%d",&n);
   for (i=1;i<=n;++i)
   {
   	  A[i].sx=read();A[i].sy=read();A[i].ex=read(); A[i].ey=read();
   	  A[i].sx++; A[i].sy++;
   	  for  (j=A[i].sx;j<=A[i].ex;++j)
   	     for (k=A[i].sy;k<=A[i].ey;++k)
   	        sum[j][k]++;
   	  for (j=A[i].sx;j<A[i].ex;++j)
   	    for (k=A[i].sy;k<=A[i].ey;++k)
   	      a[j][k]++;
   	 //heng 
   	  for (j=A[i].sx;j<=A[i].ex;++j)
   	    for (k=A[i].sy;k<A[i].ey;++k)
   	      b[j][k]++;
   	//shu
  }
  for (i=1;i<=3000;++i)
    for (j=1;j<=3000;++j)
      {
      	  	  sum[i][j]+=sum[i-1][j],b[i][j]+=b[i-1][j];
      	  	  sum[i][j]+=sum[i][j-1],a[i][j]+=a[i][j-1];
      	      sum[i][j]-=sum[i-1][j-1];
      }
   for (i=n;i;--i)
   { 
      int Max=max(A[i].sx,A[i].sy);
     for (j=max(A[i].ex-A[i].sx+1,A[i].ey-A[i].sy+1);j+Max-1<=3000;++j)
     {
     	    int sx=A[i].sx,sy=A[i].sy,ex=A[i].sx+j-1,ey=A[i].sy+j-1;
     	    if (b[ex][sy-1]-b[sx-1][sy-1]>0) break;
     	    if (a[sx-1][ey]-a[sx-1][sy-1]>0) break;
     	  	if (getsum(sx,sy,ex,ey)!=j*j) break;
     	  	if (a[ex][ey]-a[ex][sy-1]>0) continue;
     	  	if (b[ex][ey]-b[sx-1][ey]>0) continue;
     	  	pt(sx,sy,ex,ey);
     }
   }
  printf("NO\n");
}