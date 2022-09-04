//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	pll p[100005];
	for(int i=0;i<n;i++)
	scanf("%I64d %I64d",&p[i].x,&p[i].y);
	double ans=1e18;
	for(int i=1;i<n-1;i++){
		if(p[i-1].y==p[i+1].y){
			ans=min(ans,(double)abs(p[i].y-p[i+1].y));
		}
		else{
			double b=(double)(p[i+1].x-p[i-1].x)/(p[i-1].y-p[i+1].y);
			double c=(double)(-p[i-1].y*p[i+1].x+p[i-1].x*p[i+1].y)/(p[i-1].y-p[i+1].y);
			ans=min(ans,abs(p[i].x+b*p[i].y+c)/sqrt(1+sqr(b)));
		}
	}
	double b=(double)(p[1].x-p[n-1].x)/(p[n-1].y-p[1].y);
	double c=(double)(-p[n-1].y*p[1].x+p[n-1].x*p[1].y)/(p[n-1].y-p[1].y);
	if(p[n-1].y==p[1].y)
	ans=min(ans,(double)(abs(p[0].y-p[1].y)));
	else
	ans=min(ans,abs(p[0].x+b*p[0].y+c)/sqrt(1+sqr(b)));
	b=(double)(p[0].x-p[n-2].x)/(p[n-2].y-p[0].y);
	c=(double)(-p[n-2].y*p[0].x+p[n-2].x*p[0].y)/(p[n-2].y-p[0].y);
	//printf("%.8lf %.8lf",b,c,abs(p[n-1].x+b*p[n-1].y+c)/sqrt(1+sqr(b)));
	if(p[0].y==p[n-2].y)
	ans=min(ans,(double)abs(p[n-1].y-p[0].y));
	else
	ans=min(ans,abs(p[n-1].x+b*p[n-1].y+c)/sqrt(1+sqr(b)));
	printf("%.8lf",ans/2);
}

/*90 110
180 220
270 330
360 440
450 550
540 660
630 770
388908729
*/