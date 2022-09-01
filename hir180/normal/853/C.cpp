#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,q;
int p[200005];
struct BIT_on_segtree{
	vector<int>bit[(1<<19)];
	vector<int>num[(1<<19)];
	void update(int a,int x){
		a += (1<<18)-1;
		num[a].pb(x);
	}
	void mergee(){
		for(int i=(1<<18)-2;i>=0;i--){
			num[i].resize(num[i*2+1].size()+num[i*2+2].size());
			merge(num[i*2+1].begin(),num[i*2+1].end(),num[i*2+2].begin(),num[i*2+2].end(),num[i].begin());
		}
	}
	int query(int a,int b,int k,int l,int r,int L,int R){
		if(r<a||b<l||a>b) return 0;
		if(a<=l&&r<=b){
			int a = POSL(num[k],L);
			int b = POSU(num[k],R);
			return b-a;
		}
		return query(a,b,k*2+1,l,(l+r)/2,L,R)+query(a,b,k*2+2,(l+r)/2+1,r,L,R);
	}
}kaede;
int main(){
	scanf("%d%d",&n,&q); //n = 200000; q = 200000; 
	repn(i,n){
		scanf("%d",&p[i]);
		//p[i] = i;
		kaede.update(p[i],i);
	}
	kaede.mergee();
	rep(i,q){
		int a,b,c,d; scanf("%d%d%d%d",&c,&a,&d,&b);
		int x = kaede.query(b+1,(1<<18)-1,0,0,(1<<18)-1,0,INF);
		int y = kaede.query(0,a-1,0,0,(1<<18)-1,0,INF);
		int z = kaede.query(0,(1<<18)-1,0,0,(1<<18)-1,0,c-1);
		int w = kaede.query(0,(1<<18)-1,0,0,(1<<18)-1,d+1,INF);
		
		int xx = kaede.query(b+1,(1<<18)-1,0,0,(1<<18)-1,0,c-1);
		int xy = kaede.query(0,a-1,0,0,(1<<18)-1,0,c-1);
		int xz = kaede.query(0,a-1,0,0,(1<<18)-1,d+1,INF);
		int xw = kaede.query(b+1,(1<<18)-1,0,0,(1<<18)-1,d+1,INF);
		
		ll ans = 1LL*n*(n-1)/2;
		ans -= 1LL*x*(x-1)/2;
		ans -= 1LL*y*(y-1)/2;
		ans -= 1LL*z*(z-1)/2;
		ans -= 1LL*w*(w-1)/2;
		
		ans += 1LL*xx*(xx-1)/2;
		ans += 1LL*xy*(xy-1)/2;
		ans += 1LL*xz*(xz-1)/2;
		ans += 1LL*xw*(xw-1)/2;
		
		printf("%lld\n",ans);
	}
}