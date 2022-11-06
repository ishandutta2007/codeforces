#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const int mo=1e9+7;
ll n,k,a,b,mi=1e18,mx;
int main(){
	scanf("%lld%lld%lld%lld",&n,&k,&a,&b);
	rep(i,0,n-1){
		ll x=(i+n)*k+b+1,y=a+1;
		ll z=__gcd(x-y,n*k);
		mi=min(mi,n*k/z);mx=max(mx,n*k/z);
		x=(i+n)*k+b+1;y=1-a;
		z=__gcd(x-y,n*k);
		mi=min(mi,n*k/z);mx=max(mx,n*k/z);
		x=(i+n)*k+1-b;y=a+1;
		z=__gcd(x-(1-a),n*k);
		mi=min(mi,n*k/z);mx=max(mx,n*k/z);
		x=(i+n)*k+1-b;y=1-a;
		z=__gcd(x-(1-a),n*k);
		mi=min(mi,n*k/z);mx=max(mx,n*k/z);
	}
	printf("%lld %lld\n",mi,mx);
}