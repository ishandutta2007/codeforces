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
int n,a[100005],_a[100005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		_a[i] = a[i];
		a[i]++;
	}
	for(int j=n-2;j>=0;j--){
		a[j] = max(a[j],a[j+1]-1);
	}
	for(int j=1;j<n;j++){
		a[j] = max(a[j],a[j-1]);
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		ans += (a[i]-_a[i]-1);
	}
	cout<<ans<<endl;
}