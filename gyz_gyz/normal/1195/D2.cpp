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
const int mo=998244353;
ll a[N],p[20],s[20];
int main(){int n;ll ans=0;
	scanf("%d",&n);p[0]=1;
	rep(i,1,18)p[i]=p[i-1]*10%mo;
	rep(i,1,n){
		scanf("%lld",&a[i]);
		ll x=a[i],y=0;
		for(;x;x/=10)++y;++s[y-1];
	}
	rep(i,1,n){
		ll x=a[i],t=n,nw=0;
		rep(j,0,10){
			if(!x)break;
			(ans+=x%10*(t*p[j*2]*11+nw))%=mo;
			t-=s[j];(nw*=10)%=mo;
			(nw+=s[j]*p[(j+1)*2]*2)%=mo;x/=10;
		}
	}
	printf("%lld\n",ans);		
}