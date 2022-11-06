#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
int main(){ll n,k;
	scanf("%lld%lld",&n,&k);
	ll l=0,r=n,m=(l+r)>>1;
	for(;l<r;m=(l+r)>>1){
		ll s=m*(m+1)/2-(n-m);
		if(s==k)break;
		if(s<k)l=m+1;else r=m-1;
	}
	printf("%lld\n",n-m);
}