#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 400000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<double,double> pr;
double a,b,c,x1,y1,x2,y2,x[9],y[9],d[9][9];
double dis(int i,int j){
	if(i>4&&j>4)return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int main(){
	scanf("%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&x1,&y1,&x2,&y2);
	if(a==0||b==0||x1==x2||y1==y2){
		printf("%.10lf\n",abs(x1-x2)+abs(y1-y2));return 0;
	}
	x[1]=x1;y[1]=y1;x[2]=x1;y[2]=y2;
	x[3]=x2;y[3]=y1;x[4]=x2;y[4]=y2;
	x[5]=x1;y[5]=(c+a*x1)/-b;x[6]=(c+b*y1)/-a;y[6]=y1;
	x[7]=x2;y[7]=(c+a*x2)/-b;x[8]=(c+b*y2)/-a;y[8]=y2;
	rep(i,1,8)rep(j,1,8)d[i][j]=dis(i,j);
	rep(k,1,8)rep(i,1,8)rep(j,1,8)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	printf("%.10lf\n",d[1][4]);
}