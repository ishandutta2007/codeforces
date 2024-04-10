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
//#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
ll a[300005],b[300005];
ll suma[300005],sumb[300005];
ll ans[300005];
vector<pair<ll,int> >vec;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
		vec.pb(mp(a[i]-b[i],i));
	}
	SORT(vec);
	for(int i=0;i<n;i++){
		suma[i] = a[vec[i].sc];
		sumb[i] = b[vec[i].sc];
		if(i){
			suma[i] += suma[i-1];
			sumb[i] += sumb[i-1];
		}
	}
	for(int i=0;i<n;i++){
		ans[vec[i].sc] = 1LL*i*b[vec[i].sc]+1LL*(n-1-i)*a[vec[i].sc];
		if(i) ans[vec[i].sc] += suma[i-1];
		ans[vec[i].sc] += sumb[n-1]-sumb[i];
	}
	rep(i,m){
		int aa,ab; scanf("%d%d",&aa,&ab);
		aa--; ab--;
		ll mn = min(a[aa]+b[ab],a[ab]+b[aa]);
		ans[aa]-=mn;
		ans[ab]-=mn;
	}
	rep(i,n) printf("%lld ",ans[i]);
	puts("");
}