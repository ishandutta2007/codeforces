#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll mo=998244353;
ll a[N],b[N];
int main(){int n;ll ans=0;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%lld",&a[i]);a[i]*=1ll*i*(n-i+1);
	}
	sort(a+1,a+n+1);
	rep(i,1,n)scanf("%lld",&b[i]);
	sort(b+1,b+n+1);
	rep(i,1,n)ans=(ans+a[i]%mo*b[n-i+1])%mo;
	printf("%lld\n",ans);
}