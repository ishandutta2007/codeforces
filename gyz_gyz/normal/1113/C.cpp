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
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int a[N];map<int,int>p0,p1;
int main(){int n;ll ans=0;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)a[i]^=a[i-1];
	rep(i,0,n)if(i&1)++p1[a[i]];else ++p0[a[i]];
	for(auto i:p0)ans+=1ll*i.sc*(i.sc-1)/2;
	for(auto i:p1)ans+=1ll*i.sc*(i.sc-1)/2;
	printf("%lld\n",ans);
}