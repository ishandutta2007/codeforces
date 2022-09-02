#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
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
double a[1005],b[1005];
typedef pair<double,double> Q;
double dist(Q a,Q b,Q c){
	double x = sqrt((a.fi-b.fi)*(a.fi-b.fi)+(a.sc-b.sc)*(a.sc-b.sc));
	double y = sqrt((c.fi-b.fi)*(c.fi-b.fi)+(c.sc-b.sc)*(c.sc-b.sc));
	double z = sqrt((a.fi-c.fi)*(a.fi-c.fi)+(a.sc-c.sc)*(a.sc-c.sc));
	double area = sqrt( (x+y+z)/2.0 * (-x+y+z)/2.0 * (x-y+z)/2.0 * (x+y-z)/2.0 );
	return area/x;
}
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%lf%lf",&a[i],&b[i]);
	}
	double ret = 1e18;
	rep(i,n){
		ret = min(ret,dist(mp(a[i],b[i]),mp(a[(i+2)%n],b[(i+2)%n]),mp(a[(i+1)%n],b[(i+1)%n])));
	}
	printf("%.12f\n",ret);
}