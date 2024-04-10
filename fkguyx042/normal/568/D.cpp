#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath> 
#include<ctime>

#define N 100005
#define lim 30

using namespace std;
const double eps=1e-7;
struct Point{double x,y;};
struct Line{double x,y,z; int id;}A[N];
int i,j,m,n,p,k,vis[N],l,Ansx[N],Ansy[N];
int Judge(double x)
{
	  if (abs(x)<eps) return 1;
	  return 0;
}
Point mk(double a,double b)
{
	  Point x; x.x=a; x.y=b;
	  return x;
}
int ran(){
	return (rand()<<15)+rand();
}
Point get(Line a,Line b)
{
	  if (!b.x) swap(a,b);
	  if (!a.y) swap(a,b);
	  if (!a.x&&!b.y) return mk(-b.z/b.x,-a.z/a.y);
	  if (!a.x) return mk((-b.z-b.y*(-a.z/a.y))/b.x,-a.z/a.y);
	  if (!b.y) return mk(-b.z/b.x,(-a.z-a.x*(-b.z/b.x))/a.y);
	  return mk((-a.z+b.z*a.y/b.y)/(a.x-b.x*a.y/b.y),(-a.z+b.z*a.x/b.x)/(a.y-b.y*a.x/b.x));
}
void change(int x,int y)
{
	  memset(vis,0,sizeof(vis));
	  if (x==y) vis[x]=1;
	  else 
	  {
	  	   Point R=get(A[x],A[y]);
		  	  	  for (l=1;l<=n;++l)
		  	  	      if (Judge(A[l].x*R.x+A[l].y*R.y+A[l].z)) vis[l]=1;
	  }
	  int Nc=0;
	  for (l=1;l<=n;++l) if (!vis[l]) A[++Nc]=A[l];
	  n=Nc;
}
int main()
{
	  scanf("%d%d",&n,&k);
//	  srand(233);
      srand((int)time(0));
	  for (i=1;i<=n;++i) scanf("%lf%lf%lf",&A[i].x,&A[i].y,&A[i].z),A[i].id=i;
	  for (i=1;i<=k&&n;++i)
	{
		  int Max=0,Ai,Bi;
		  for (j=1;j<=lim;++j)
		  {
		  	  int x=ran()%n+1,y=ran()%n+1,sum;
		  	  while (((!A[x].x&&!A[y].x)||(!A[x].y&&!A[y].y)||(A[x].x&&A[y].x&&A[x].y&&A[y].y&&A[x].y*A[y].x==A[y].y*A[x].x))&&x!=y) x=ran()%n+1,y=ran()%n+1;
		  	  if (x==y) sum=1;
		  	  else 
		  	  {
		  	  	  Point R=get(A[x],A[y]); sum=0;
		  	  	  for (l=1;l<=n;++l)
		  	  	      if (Judge(A[l].x*R.x+A[l].y*R.y+A[l].z)) ++sum;
		  	  }
		  	  if (sum>Max) Max=sum,Ai=x,Bi=y;
		  }
		  Ansx[i]=A[Ai].id;Ansy[i]=A[Bi].id;
		  change(Ai,Bi);
	}
	 if (n) printf("NO\n");
	 else 
	 {
	 	printf("YES\n");
	 	printf("%d\n",i-1);
	 	for (j=1;j<i;++j) 
	 	  if (Ansx[j]==Ansy[j]) printf("%d -1\n",Ansx[j]);
	 	  else printf("%d %d\n",Ansx[j],Ansy[j]);
	 }
}