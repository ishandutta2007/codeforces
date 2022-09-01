#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
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
int q;
int n,x[100005],y[100005],a[100005][4];
int main(){
	scanf("%d",&q);
	while(q--){
		int n; scanf("%d",&n);
		int xa=-100000,xb=100000;
		int ya=-100000,yb=100000;

		rep(i,n){
			scanf("%d%d",&x[i],&y[i]); rep(j,4) scanf("%d",&a[i][j]);
			if(a[i][0] == 0){
				xa = max(xa,x[i]);
			}
			if(a[i][1] == 0){
				yb = min(yb,y[i]);
			}
			if(a[i][2] == 0){
				xb = min(xb,x[i]);
			}
			if(a[i][3] == 0){
				ya = max(ya,y[i]);
			}
		}
		
		if(xa <= xb && ya <= yb){
			printf("1 %d %d\n",xa,ya);
		}
		else{
			puts("0");
		}}}