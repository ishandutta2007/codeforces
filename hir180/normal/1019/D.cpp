#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
const ll mod = 1000000007;

int n;
ll S;
int x[2005],y[2005];
int p[2005],rev[2005];
bool cmp(const int &a,const int &b){
	return mp(x[a],y[a]) < mp(x[b],y[b]);
}
vector<P2>query;
bool cmp2(const P2&a,const P2&b){
	ll ccw = 1LL*a.fi.fi*b.fi.sc - 1LL*a.fi.sc*b.fi.fi;
	return ccw > 0;
}
ll calc(int a,int b,int c){
	int A = x[b]-x[a];
	int B = y[b]-y[a];
	int C = x[c]-x[a];
	int D = y[c]-y[a];
	return abs(1LL*A*D-1LL*B*C);
}
void answer(int a,int b,int c){
	puts("Yes");
	printf("%d %d\n",x[a],y[a]);
	printf("%d %d\n",x[b],y[b]);
	printf("%d %d\n",x[c],y[c]);
	exit(0);
}
void solve(int a,int b,int k){
	//[0,k-1]
	int lb = 0, ub = k;
	while(ub - lb > 1){
		int mid = (lb+ub)/2;
		ll C = calc(a,b,p[mid]);
		if(C == S){
			answer(a,b,p[mid]);
		}
		else if(C > S){
			lb = mid;
		}
		else ub = mid;
	}
	if(calc(a,b,p[lb]) == S) answer(a,b,p[lb]);
	//[k+1,n-1]
	lb = k, ub = n-1;
	while(ub - lb > 1){
		int mid = (lb+ub)/2;
		ll C = calc(a,b,p[mid]);
		if(C == S){
			answer(a,b,p[mid]);
		}
		else if(C < S){
			lb = mid;
		}
		else ub = mid;
	}
	if(calc(a,b,p[ub]) == S) answer(a,b,p[ub]);
}
int main(){
	scanf("%d%lld",&n,&S); S*=2;
	rep(i,n) scanf("%d%d",&x[i],&y[i]);
	rep(i,n) p[i] = i;
	sort(p,p+n,cmp);
	rep(i,n) rev[p[i]] = i;
	rep(i,n) for(int j=i+1;j<n;j++){
		int a = p[i], b = p[j];
		int X = x[b]-x[a];
		int Y = y[b]-y[a];
		query.pb(mp(mp(X,Y),mp(a,b)));
	}
	sort(query.begin(),query.end(),cmp2);
	
	rep(i,query.size()){
		int a = query[i].sc.fi;
		int b = query[i].sc.sc;
		assert(abs(rev[a]-rev[b]) == 1);
		solve(a,b,min(rev[a],rev[b]));
		swap(p[rev[a]],p[rev[b]]);
		swap(rev[a],rev[b]);
	}
	puts("No");
	return 0;
}