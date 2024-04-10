#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
using namespace std;
pdd operator+(const pdd &a,const pdd &b){
	return {a.x+b.x,a.y+b.y};
}
pdd operator-(const pdd &a,const pdd &b){
	return {a.x-b.x,a.y-b.y};
}
double cross(const pdd &a,const pdd &b){
	return a.x*b.y-a.y*b.x;
}
long double mymod(long double x){
	return x-floor(x/pi2)*pi2;
}
pdd cal(pdd q,pdd mid,long double angle){
	q.y+=angle;
//	printf("%lf %lf\n",q.x,q.y/pi*180);
	q.y=mymod(q.y);
//	printf("%lf %lf\n",q.x,q.y/pi*180);
	return mp(cos(q.y)*q.x,sin(q.y)*q.x)+mid;
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	pdd p[10005];
	pdd b[10005];
	pdd mid=mp(0,0);
	double s=0;
	for(int i =1;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i]=mp(x,y);
		//mid= mid+p[i];
	}
	for(int i = 2;i<n;i++){
		pdd cen= p[1]+p[i]+p[i+1];
		cen.x/=3;
		cen.y/=3;
		double ss=cross(p[i]-p[1],p[i+1]-p[1]);
		s+=ss;
		cen.x*=ss;
		cen.y*=ss;
		mid = mid +cen;
	}
	mid.x/=s;
	mid.y/=s;
	//mid.x/=n;
	//mid.y/=n;
	for(int i = 1;i<=n;i++){
		p[i]=p[i]-mid;
		b[i].x=sqrt(p[i].x*p[i].x+p[i].y*p[i].y);
		b[i].y=mymod(atan2(p[i].y,p[i].x));
		//printf("%lf %lf %lf %lf %lf %lf\n",b[i].x,b[i].y/pi*180,mid.x,mid.y,cos(b[i].y)*b[i].x,sin(b[i].y)*b[i].x);
	}
	int pin[2]={1,2};
	long double angle=0;
	while(q--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x,y;
			scanf("%d %d",&x,&y);
			if(pin[1]==x)swap(pin[0],pin[1]);
			assert(pin[0]==x);
			pdd temp =cal(b[pin[1]],mid,angle);
			mid = mp(temp.x,temp.y-b[pin[1]].x);
			//printf("%d\n",pin[1]);
			//printf("%lf %lf %lf %lf %lf\n",mid.x,mid.y,temp.x,temp.y,b[pin[1]].x);
			angle = mymod(pi/2-b[pin[1]].y);
			pin[0]=y;
		}
		else{
			int x;
			scanf("%d",&x);
			pdd ans=cal(b[x],mid,angle);
			printf("%.12lf %.12lf\n",(double)ans.x,(double)ans.y);
		}
	}
}