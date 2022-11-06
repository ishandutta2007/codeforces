#include<cstdio>
#include<cmath>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define pi acos(-1)
#define N 200000
using namespace std;
struct pr{__float128 x;int id;}p[N];
inline bool cmp(pr x,pr y){return x.x<y.x;}
int n,x,y,s;const long double o=1;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&x,&y);
		if(!x)p[i].x=0.5;else p[i].x=atan(o*y/x)/pi;
		if(x<0)p[i].x=1+p[i].x;
		else if(y<0)p[i].x=2+p[i].x;
		if(!x&&y<0)p[i].x=1.5;
	}
	rep(i,1,n)p[i].id=i;
	sort(p+1,p+n+1,cmp);p[0]=p[n];p[0].x-=2;s=1;
	rep(i,2,n)if(p[i].x-p[i-1].x<p[s].x-p[s-1].x)s=i;
	printf("%d %d\n",p[s-1].id,p[s].id);
}