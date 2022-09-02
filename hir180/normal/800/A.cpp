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
#define eps 1e-11
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
double p,a[100005],b[100005],sum;
int main(){
	scanf("%d%lf",&n,&p);
	rep(i,n){
		scanf("%lf%lf",&a[i],&b[i]);
		sum += a[i];
	}
	if(p+eps >= sum){
		puts("-1"); return 0;
	}
	double lb=0.0,ub=1e12;
	rep(q,100){
		double mid=(lb+ub)/2;
		double S = 0;
		rep(i,n){
			S += max(0.0,a[i]*mid-b[i]);
		}
		if(S <= p*mid+eps) lb = mid;
		else ub = mid;
	}
	if(lb > 1e11) puts("-1");
	else printf("%.8f\n",lb);
}