#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,int>pli;
const int N=1e6+10;
const int mo=998244353;
const ll inf=1e18;
int a[N],nw[N];
ll cal(int x,int y){
	ll p=x/y;int t=x%y;
	return p*p*(y-t)+(p+1)*(p+1)*t;
}
int main(){int n,k;ll ans=0;
	scanf("%d%d",&n,&k);
	multiset<pli>s;k-=n;
	rep(i,1,n){
		scanf("%d",&a[i]);
		ans+=1ll*a[i]*a[i];nw[i]=1;
		if(a[i]>1)s.insert({cal(a[i],1)-cal(a[i],2),i});
	}
	rep(i,1,k){
		auto j=--s.end();ans-=j->fr;
		int x=j->sc;s.erase(j);++nw[x];
		if(nw[x]<a[x])s.insert({cal(a[x],nw[x])-cal(a[x],nw[x]+1),x});
	}
	printf("%lld\n",ans);
}