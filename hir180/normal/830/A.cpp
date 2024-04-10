#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
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
int n,k;
ll p,a[1005],b[2005];
int main(){
	cin>>n>>k>>p;
	repn(i,n)cin>>a[i]; sort(a+1,a+n+1);
	repn(i,k)cin>>b[i]; sort(b+1,b+k+1);
	ll lb = -1,ub = 2e9;
	while(ub-lb>1){
		ll mid = (lb+ub)/2;
		bool ok = 1;
		int L[1005],R[1005];
		repn(i,n){
			int mn=INF,mx=-INF;
			repn(j,k){
				if(abs(a[i]-b[j])+abs(b[j]-p) <= mid){
					mn=min(mn,j);
					mx=max(mx,j);
				}
			}
			if(mn==INF) ok=0;
			L[i] = mn; R[i] = mx;
		}
		if(ok==0){
			lb = mid; continue;
		}
		bool used[2005]={};
		repn(i,n){
			bool can = 0;
			for(int j=L[i];j<=R[i];j++){
				if(!used[j]){
					used[j] = 1; can = 1; break;
				}
			}
			if(can==0) ok=0;
		}
		if(ok==0){
			lb = mid; continue;
		}
		ub=mid; continue;
	}
	cout<<ub<<endl;
}