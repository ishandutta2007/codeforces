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
int n,a[2005];
int main(){
	cin>>n;
	repn(i,n) cin>>a[i];
	vector<int>vec;
	for(int i=n;i>=1;i--){
		int x = (a[i])%(n+1);
		int need = i-x;
		while(need < 0) need += (n+1);
		repn(j,i) a[j] += need;
		vec.pb(need);
	}
	reverse(vec.begin(),vec.end());
	cout<<n+1<<endl;
	rep(i,n) cout<<1<<" "<<i+1<<" "<<vec[i]<<endl;
	cout<<2<<" "<<n<<" "<<n+1<<endl;
}