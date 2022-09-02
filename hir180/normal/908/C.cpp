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
int n;
double r,x[1005],ans[1005];
int main(){
	scanf("%d%lf",&n,&r);
	rep(i,n){
		scanf("%lf",&x[i]);
		double cur = r;
		rep(j,i){
			//(x[j],ans[j])-2*r and x=x[i]
			double dif = abs(x[j]-x[i]);
			if(dif > 2.0*r+1e-11) continue;
			double h = sqrt(4.0*r*r-dif*dif);
			double ub = ans[j]+h;
			if(ub > cur) cur = ub;
		}
		ans[i] = cur;
	}
	rep(i,n) printf("%.12f ",ans[i]);
	puts("");
}