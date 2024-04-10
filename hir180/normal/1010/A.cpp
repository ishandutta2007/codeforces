#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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
long double m,a[1005],b[1005];
int main(){
	scanf("%d",&n);
	scanf("%Lf",&m);
	for(int i=1;i<=n;i++){
		scanf("%Lf",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%Lf",&b[i]);
	}
	long double lb = 0.0,ub = 2e9;
	rep(q,205){
		long double mid = (lb+ub)/2;
		long double cur = m+mid;
		for(int i=1;i<=2*n;i++){
			long double val;
			if(i%2 == 1){
				val = a[(i+1)/2];
			}
			else if(i == 2*n){
				val = b[1];
			}
			else{
				val = b[i/2+1];
			}
			cur -= cur/val;
			if(cur<m) goto fail;
		}
		ub = mid; continue;
		fail:; lb = mid;
	}
	if(ub > 1e9+8e8){
		puts("-1");
	}
	else{
		printf("%.12Lf\n",ub);
	}
}