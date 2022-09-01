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

int n,m;
ll a[100005],b[100005];
ll mx=-1,mn=INF;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); mx = max(mx,a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]); mn = min(mn,b[i]);
	}
	sort(a+1,a+n+1);
	if(mx > mn){
		puts("-1");
	}
	else if(mx == mn){
		ll ans = 0;
		for(int i=1;i<=n;i++) ans += a[i] * 1LL * m;
		for(int i=1;i<=m;i++) ans += b[i]-mx;
		cout << ans << endl;
	}
	else{
		ll ans = 0;
		for(int i=1;i<=n;i++) ans += a[i] * 1LL * m;
		for(int i=1;i<=m;i++) ans += b[i]-mx;
		ans += a[n]-a[n-1];
		
		cout << ans << endl;
	}
}