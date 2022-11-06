#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 2000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
struct pr{int x,y;ll z;}e[N];
bool cmp(pr x,pr y){return x.z<y.z;}
int n,m,f[N];ll ans,s[N];set<pli>q;
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
void lk(int x,int y){
	if(s[x]>s[y])swap(x,y);
	q.erase({s[y],y});f[y]=x;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%lld",&s[i]);
		q.insert({s[i],i});f[i]=i;
	}
	rep(i,1,m){
		scanf("%d%d%lld",&e[i].x,&e[i].y,&e[i].z);
	}
	sort(e+1,e+m+1,cmp);
	rep(i,1,m){
		if(q.size()==1)break;
		while(q.size()>1){
			auto x=q.begin(),y=++q.begin();
			if(x->fr+y->fr>e[i].z)break;
			ans+=x->fr+y->fr;lk(x->sc,y->sc);
		}
		if(gf(e[i].x)!=gf(e[i].y)){
			ans+=e[i].z;lk(f[e[i].x],f[e[i].y]);
		}
	}
	while(q.size()>1){
		auto x=q.begin(),y=++q.begin();
		ans+=x->fr+y->fr;lk(x->sc,y->sc);
	}
	printf("%lld\n",ans);
}