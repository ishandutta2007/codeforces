#include<bits/stdc++.h>
#define pii pair<int,int>    
#define x first    
#define y second    
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))    
#define sqr(x) ((x)*(x))
#define N 100005  
typedef long long LL;  
using namespace std;   
int main(){
	double x[2],y[2],r[2];
	for(int i=0;i<2;i++)
	scanf("%lf %lf %lf",&x[i],&y[i],&r[i]);
	double unitx,unity;
	double di=sqrt(sqr(x[0]-x[1])+sqr(y[0]-y[1]));
	if(di<r[0]+r[1]&&(di+min(r[0],r[1])>max(r[0],r[1])))
	{
		printf("0\n");
		return 0;
	}
	unitx=(x[1]-x[0])/di;
	unity=(y[1]-y[0])/di;
	pair<double,double> p1[2],p2[2];
	p1[0]=mp(x[0]+unitx*r[0],y[0]+unity*r[0]);
	p1[1]=mp(x[0]-unitx*r[0],y[0]-unity*r[0]);
	p2[0]=mp(x[1]+unitx*r[1],y[1]+unity*r[1]);
	p2[1]=mp(x[1]-unitx*r[1],y[1]-unity*r[1]);
	double ans=1e18;
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	ans=min(ans,sqrt(sqr(p1[i].x-p2[j].x)+sqr(p1[i].y-p2[j].y))/2);
	printf("%.15lf",ans);
}