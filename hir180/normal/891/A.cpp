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
int n,a[2005],x;
int main(){
	cin>>n;
	repn(i,n) cin>>a[i];
	repn(i,n) if(a[i]==1) x++;
	if(x){
		cout<<n-x<<endl; return 0;
	}
	int ans = INF;
	repn(i,n){
		int t = INF;
		int pre = a[i];
		for(int j=i+1;j<=n;j++){
			int x = __gcd(pre,a[j]);
			if(x == 1){
				t = j-i; break;
			}
			else{
				pre = x;
			}
		}
		if(t == INF) continue;
		ans = min(ans,n+t-1);
	}
	repn(i,n){
		int t = INF;
		int pre = a[i];
		for(int j=i-1;j>=1;j--){
			int x = __gcd(pre,a[j]);
			if(x == 1){
				t = i-j; break;
			}
			else{
				pre = x;
			}
		}
		if(t == INF) continue;
		ans = min(ans,n+t-1);
	}
	if(ans > 1e8) ans = -1;
	cout<<ans<<endl;
}