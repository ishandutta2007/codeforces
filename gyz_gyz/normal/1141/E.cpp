#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
ll a[N];
int main(){ll m;int n;
	scanf("%lld%d",&m,&n);ll s=m,dt=0;
	rep(i,1,n){
		scanf("%lld",&a[i]);
		m+=a[i];dt+=a[i];
		if(m<=0)return printf("%d\n",i),0;
		s=min(s,m);
	}
	if(dt>=0)return printf("-1\n"),0;
	ll ans=n;s=(s-1)/-dt;
	m+=s*dt;ans+=s*n;
	rep(i,1,n){m+=a[i];
		if(m<=0)return printf("%lld\n",ans+i),0;
	}
}