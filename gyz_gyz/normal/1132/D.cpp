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
#define N 300010
#define M 10000010
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<ll,int>pli;
int n;ll k,a[N],t[N],b[N];
bool ck(ll m){
	priority_queue<pli,vector<pli>,greater<pli>>q;
	rep(i,1,n){
		t[i]=0;q.push({a[i]/b[i],i});
	}
	rep(i,0,k-1){
		int x=q.top().sc;q.pop();
		if(b[x]*i>a[x]+t[x])return 0;
		t[x]+=m;q.push({(a[x]+t[x])/b[x],x});
	}return 1;
}
int main(){
	scanf("%d%lld",&n,&k);
	rep(i,1,n)scanf("%lld",&a[i]);
	rep(i,1,n)scanf("%lld",&b[i]);
	ll l=0,r=2e12+1,m=(l+r)/2;
	for(;l<r;m=(l+r)/2)
		if(ck(m))r=m;else l=m+1;
	printf("%lld\n",m>2e12?-1:m);
}