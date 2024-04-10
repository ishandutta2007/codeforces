#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
double a,b,c;
double x[2],y[2];
double dd(double a,double b,double c,double d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main(){
	scanf("%lf%lf%lf",&a,&b,&c);
	rep(i,2) scanf("%lf%lf",&x[i],&y[i]);
	double ans = abs(x[0]-x[1])+abs(y[0]-y[1]);
	vector<pair<double,double> >zero,one;
	if(abs(b) > 1e-8){
		double D = -(a*x[0]+c) / b;
		zero.pb(mp(x[0],D));
		D = -(a*x[1]+c) / b;
		one.pb(mp(x[1],D));
	}
	if(abs(a) > 1e-8){
		double D = -(b*y[0]+c) / a;
		zero.pb(mp(D,y[0]));
		D = -(b*y[1]+c) / a;
		one.pb(mp(D,y[1]));
	}
	rep(i,zero.size()) rep(j,one.size()){
		double cur = 0.0;
		cur+=dd(x[0],y[0],zero[i].fi,zero[i].sc);
		cur+=dd(zero[i].fi,zero[i].sc,one[j].fi,one[j].sc);
		cur+=dd(one[j].fi,one[j].sc,x[1],y[1]);
		ans=min(ans,cur);
	}
	printf("%.8f\n",ans);
}