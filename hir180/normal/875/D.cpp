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
int n,a[200005],v[200005];
struct rmq{
	int db[200005][21];
	void make(){
		for(int i=1;i<=n;i++) db[i][0] = a[i];
		for(int j=0;j<20;j++){
			for(int i=1;i<=n;i++){
				if(i + (1<<j) > n) db[i][j+1] = db[i][j];
				else db[i][j+1] = max(db[i][j],db[i+(1<<j)][j]);
			}
		}
	}
	int query(int a,int b,int k,int l,int r){
	    if(a>b) return -1009;
		int i = v[(b-a+1)];
		{
				return max(db[a][i],db[b-(1<<i)+1][i]);
		}
	}
}R;
struct rmq2{
	int db[200005][21];
	void make(){
		for(int i=1;i<=n;i++) db[i][0] = a[i];
		for(int j=0;j<20;j++){
			for(int i=1;i<=n;i++){
				if(i + (1<<j) > n) db[i][j+1] = db[i][j];
				else db[i][j+1] = (db[i][j]|db[i+(1<<j)][j]);
			}
		}
	}
	int query(int a,int b,int k,int l,int r){
	    if(a>b) return 0;
		int i = v[(b-a+1)];
		{
				return (db[a][i]|db[b-(1<<i)+1][i]);
		}
	}
}O;

int main(){
	cin>>n;
	repn(i,n){
		scanf("%d",&a[i]);
	}
	O.make(); R.make();
	for(int i=1;i<200005;i++){
		for(int j=20;j>=0;j--){
			if(i >= (1<<j)){
				v[i] = j; break;
			}
		}
	}
	ll ans = 1LL*n*(n+1)/2LL;
	repn(i,n){
		int lb = 0,ub = i;
		while(ub-lb>1){
			int mid = (lb+ub)/2;
			//[mid,i]
			int x = O.query(mid,i-1,0,0,(1<<18)-1);
			int y = R.query(mid,i-1,0,0,(1<<18)-1);
			if(y >= a[i]){
				lb = mid;
			}
			else if( (x|a[i]) != a[i]){
				lb = mid;
			}
			else{
				ub = mid;
			}
		}
		ll U = i-ub+1;
		
		lb = i,ub = n+1;
		while(ub-lb>1){
			int mid = (lb+ub)/2;
			//[i,mid]
			int x = O.query(i,mid,0,0,(1<<18)-1);
			int y = R.query(i,mid,0,0,(1<<18)-1);
			if(y > a[i]){
				ub = mid;
			}
			else if( (x|a[i]) != a[i]){
				ub = mid;
			}
			else{
				lb = mid;
			}
		}
		ll V = lb-i+1;
		
		ans -= U*V;
	//	cout<<U*V<<endl;
	}
	cout<<ans<<endl;
}