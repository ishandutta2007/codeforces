#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 200000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pr;
int n;pr a[N];ll x,y,ans;multiset<ll>s;
int main(){
	scanf("%d%lld%lld",&n,&x,&y);
	rep(i,1,n)scanf("%lld%lld",&a[i].fr,&a[i].sc);
	sort(a+1,a+n+1);
	rep(i,1,n){
		auto t=s.lower_bound(a[i].fr);
		if(t!=s.begin()&&(a[i].fr-(*--t))*y<x){
			ans=(ans+(a[i].fr-(*t))*y)%mo;s.erase(t);
		}else ans=(ans+x)%mo;
		ans=(ans+y*(a[i].sc-a[i].fr))%mo;s.insert(a[i].sc);
	}
	printf("%lld\n",ans);
}