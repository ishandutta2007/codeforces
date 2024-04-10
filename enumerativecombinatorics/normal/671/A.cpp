#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000010007;
const long long inf=mod*mod;
double x[3];
double y[3];
double X[110000];
double Y[110000];
double dist(double dx,double dy){
	return sqrt(dx*dx+dy*dy);
}
pair<double,int> ta[110000];
pair<double,int> tb[110000];
int main(){
	for(int i=0;i<3;i++){
		scanf("%lf%lf",x+i,y+i);
	}
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%lf%lf",X+i,Y+i);
	}
	if(a==1){
		printf("%.12f\n",min(dist(X[0]-x[0],Y[0]-y[0]),dist(X[0]-x[1],Y[0]-y[1]))+dist(X[0]-x[2],Y[0]-y[2]));
		return 0;
	}
	double ret=0;
	for(int i=0;i<a;i++){
		ret+=dist(X[i]-x[2],Y[i]-y[2])*2;
		ta[i]=make_pair(dist(X[i]-x[0],Y[i]-y[0])-dist(X[i]-x[2],Y[i]-y[2]),i);
		tb[i]=make_pair(dist(X[i]-x[1],Y[i]-y[1])-dist(X[i]-x[2],Y[i]-y[2]),i);
	}
	double ad=99999999999999.9;
	std::sort(ta,ta+a);
	std::sort(tb,tb+a);
	for(int i=0;i<2;i++)for(int j=0;j<2;j++){
		if(ta[i].second==tb[j].second)continue;
		ad=min(ta[i].first+tb[j].first,ad);
	}
	ad=min(ad,min(ta[0].first,tb[0].first));
	printf("%.12f\n",ret+ad);
}