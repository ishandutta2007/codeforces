#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
int n,m;ll y,ans,r[N],p[N];set<pli>s;
void et(int x){
	ll z=min(r[x],y);
	r[x]-=z;y-=z;ans+=z*p[x];
	if(!r[x])s.erase({p[x],x});
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%lld",&r[i]);
	rep(i,1,n){
		scanf("%lld",&p[i]);s.insert({p[i],i});
	}
	rep(i,1,m){int x;ans=0;
		scanf("%d%lld",&x,&y);et(x);
		while(y&&!s.empty())et(s.begin()->sc);
		printf("%lld\n",y?0:ans);
	}
}