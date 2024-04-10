#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int x[4]={0,0,-1,1};
const int y[4]={1,-1,0,0};
const double pi=acos(-1.0)/180.0;
double Sin[5],Cos[5];
int n,i,j,k,s,vis[2005][2005],l,r,A,B;
struct Node{int x,y;}Q[4000005];
int c[2005][2005];
inline int read()
{
	    int x=0; char c;
	    while (c=getchar(),c<'0'||c>'9');
	    x=c-'0';
	    while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
	    return x;
}
bool check(int x,int y)
{
	if (x<0||y<0||x>=n||y>=n) return 0;
	return 1;
}
void bfs(int ax,int ay)
{ 
 Q[r=1].x=ax; Q[1].y=ay; vis[ax][ay]=1;
 int i;
 for (l=1;l<=r;++l)
 {
 	int axc=Q[l].x,ayc=Q[l].y;
 	for (i=0;i<4;++i)
 	  if (check(axc+x[i],ayc+y[i])&&!vis[axc+x[i]][ayc+y[i]]&&c[axc+x[i]][ayc+y[i]]==1)
 	  {
 	  	     Q[++r].x=axc+x[i];Q[r].y=ayc+y[i];
 	  	     vis[axc+x[i]][ayc+y[i]]=1;
 	  }
 }
}
int main()
{
	Sin[0]=sin(45*pi); Cos[0]=cos(45*pi);
	Sin[1]=sin(30*pi); Cos[1]=cos(30*pi);
	Sin[2]=sin(75*pi); Cos[2]=cos(75*pi);
	scanf("%d",&n);
	for (i=0;i<n;++i) 
	   for (j=0;j<n;++j) c[i][j]=read();
	for (i=0;i<n;++i)
	   for (j=0;j<n;++j)
	     if (!vis[i][j]&&c[i][j]==1)
	     {
	     	 bfs(i,j);
	     	 if (r<100) continue;
	     	 double Min=1e9,Max=-1e9;
		     for (k=1;k<=r;++k) Min=min(Min,(double)Q[k].y),Max=max(Max,(double)Q[k].y);
             double See=Max-Min,Cha=0.0;
			 for (s=0;s<3;++s)
			 {
			    Min=1e9,Max=-1e9;
				for (k=1;k<=r;++k)
				{ 
				  double R=1.0*Cos[s]*Q[k].y-1.0*Sin[s]*Q[k].x;
				 Min=min(Min,R);
				 Max=max(Max,R);
			    }
			    Cha=max(Cha,abs((Max-Min)-See));
		     }
		     if (Cha>0.07*See) A++; else B++;
		}
		printf("%d %d\n",B,A);
}