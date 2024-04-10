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
int n;
ll a[1005],h;
int main(){
	scanf("%d%lld",&n,&h);
	rep(i,n) scanf("%d",&a[i]);
	for(int ans=n;ans>=1;ans--){
		vector<int>vec;
		for(int i=0;i<ans;i++) vec.pb(a[i]);
		SORT(vec);
		reverse(vec.begin(),vec.end());
		ll sum = 0 ;
		for(int i=0;i<vec.size();i+=2){
			sum += vec[i];
		}
		if(sum <= h){
			cout << ans << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}