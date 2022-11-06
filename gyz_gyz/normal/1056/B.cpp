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
int m;ll ans,n,a[N];
int main(){
	scanf("%lld%d",&n,&m);
	rep(i,0,m-1){
		ll s=n/m;if(i&&i<=n%m)s++;
		a[i*i%m]+=s;
	}
	rep(i,1,m-1)ans+=a[i]*a[m-i];
	printf("%lld\n",ans+a[0]*a[0]);
}