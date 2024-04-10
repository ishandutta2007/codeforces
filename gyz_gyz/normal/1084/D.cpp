#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 400000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,ll>pil;
int n,f[N];ll ans,w[N];vector<pil>p[N];
void dp(int x){ll t1=0,t2=0;
	for(auto i:p[x])if(i.fr!=f[x]){
		f[i.fr]=x;dp(i.fr);ll pt=w[i.fr]-i.sc;
		if(pt>t1)t2=t1,t1=pt;
		else t2=max(t2,pt);
	}
	w[x]+=t1;ans=max(ans,w[x]+t2);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&w[i]);
	rep(i,1,n-1){int x,y;ll z;
		scanf("%d%d%lld",&x,&y,&z);
		p[x].pb({y,z});p[y].pb({x,z});
	}
	dp(1);printf("%lld\n",ans);
}