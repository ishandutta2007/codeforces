#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
//#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll dif[1000005],a[1000005],val[1000005];; int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		//i,i+1,...n,1,...i-1
		if(i<=a[i] && a[i]<=n){
			//1,....,a[i]-i -> -1
			//a[i]-i+1...,n-i -> 1
			//n-i+1 -> abs(1-a[i]) - abs(n-a[i])
			//n-i+2,....,n-1 -> -1
			dif[1] --;
			dif[a[i]-i+1] ++;
			dif[a[i]-i+1] ++;
			dif[n-i+1] --;
			dif[n-i+1] += abs(1-a[i]) - abs(n-a[i]);
			dif[n-i+2] -= abs(1-a[i]) - abs(n-a[i]);
			dif[n-i+2] --;
			dif[n] ++;
		}
		else{
			//1,....,n-i -> 1
			//n-i+1 -> abs(1-a[i]) - abs(n-a[i])
			//n-i+2,....,n-i+a[i] -> -1
			//n-i+1+a[i],...,n-1 -> 1
			dif[1] ++;
			dif[n-i+1] --;
			dif[n-i+1] += abs(1-a[i]) - abs(n-a[i]);
			dif[n-i+2] -= abs(1-a[i]) - abs(n-a[i]);
			dif[n-i+2] --;
			dif[n-i+a[i]+1] ++;
			dif[n-i+a[i]+1] ++;
			dif[n] --;
		}
	}
	for(int i=2;i<n;i++) dif[i] += dif[i-1];
	for(int i=2;i<=n;i++) val[i] += val[i-1]+dif[i-1];
	pair<ll,int>p = mp(1e18,INF);
	for(int i=1;i<=n;i++){
		p = min(p,mp(val[i],i));
	}
	int x = p.sc-1; ll ans = 0;
	for(int i=1;i<=n;i++){
		x++;
		if(x == n+1) x = 1;
		ans += abs(x-a[i]);
	}
	cout<<ans<<" "<<--p.sc<<endl;
}