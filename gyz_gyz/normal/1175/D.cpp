#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=1e9+7;
ll a[N];
int main(){int n,m;ll ans=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%lld",&a[i]);
	dep(i,n-1,1)a[i]+=a[i+1];
	sort(a+2,a+n+1,[](ll x,ll y){return x>y;});
	rep(i,1,m)ans+=a[i];
	printf("%lld\n",ans);
}