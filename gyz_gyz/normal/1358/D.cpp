#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
ll a[N];
int main(){int n;ll m;
	scanf("%d%lld",&n,&m);
	rep(i,1,n)scanf("%lld",&a[i]);
	int x=1;ll nw=0,tot=0,ans=0;
	rep(i,1,n){
		while(nw+a[x]<m){
			tot+=(a[x]+1)*a[x]/2;
			nw+=a[x];x=x%n+1;
		}
		ll r=m-nw;r=(1+r)*r/2;
		ans=max(ans,tot+r);
		nw-=a[i];tot-=(a[i]+1)*a[i]/2;
	}
	x=n;nw=0,tot=0,ans=0;
	dep(i,n,1){
		while(nw+a[x]<m){
			tot+=(a[x]+1)*a[x]/2;
			nw+=a[x];x=x>1?x-1:n;
		}
		ll r=m-nw;r=(a[x]+a[x]-r+1)*r/2;
		ans=max(ans,tot+r);
		nw-=a[i];tot-=(a[i]+1)*a[i]/2;
	}
	printf("%lld\n",ans);
}