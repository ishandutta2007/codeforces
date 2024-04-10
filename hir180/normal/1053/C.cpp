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
struct seg{
	ll seg[(1<<19)];
	void update(int a,ll v,bool flag){
		a += (1<<18)-1;
		seg[a] += v;
		if(flag) seg[a]%=mod;
		while(a){
			a = (a-1)/2;
			seg[a] = seg[a*2+1]+seg[a*2+2];
			if(flag) seg[a]%=mod;
		}
	}
	ll query(int a,int b,int k,int l,int r,bool flag){
		if(r<a || b<l) return 0LL;
		if(a<=l&&r<=b) return seg[k];
		ll d = query(a,b,k*2+1,l,(l+r)/2,flag)+query(a,b,k*2+2,(l+r)/2+1,r,flag);
		if(flag) d%=mod;
		return d;
	}
	int find(int k,int l,int r,ll S){
		if(l == r) return l;
		if(seg[k*2+1] >= S){
			return find(k*2+1,l,(l+r)/2,S);
		}
		else{
			return find(k*2+2,(l+r)/2+1,r,S-seg[k*2+1]);
		}
	}
}mul,sum;
int n,q;
ll a[200005],w[200005];
vector<ll>pos;
ll W[200005];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);

	for(int i=1;i<=n;i++){
		sum.update(i,w[i],0);
		mul.update(i,w[i]*(a[i]-i),1);
	}
	for(int i=0;i<q;i++){
		ll id,wg;
		scanf("%lld%lld",&id,&wg);
		if(id < 0){
			id = -id;
			sum.update(id,wg-w[id],0);
			mul.update(id,(wg-w[id])*(a[id]-id),1);
			w[id] = wg;
		}
		else{
			ll L = id, R = wg;
			ll S = sum.query(1,L-1,0,0,(1<<18)-1,0);
			ll T = sum.query(L,R,0,0,(1<<18)-1,0);
			S += (T+1)/2;
			int pos = sum.find(0,0,(1<<18)-1,S); //cout<<pos<<endl;
			ll X = mul.query(L,pos,0,0,(1<<18)-1,1);
			ll X2 = sum.query(L,pos,0,0,(1<<18)-1,0);
			ll X3 = mul.query(pos+1,R,0,0,(1<<18)-1,1);
			ll X4 = sum.query(pos+1,R,0,0,(1<<18)-1,0);
			//cout<<X<<" "<<X2<<" "<<X3<<" "<<X4<<endl;
			ll ans = -X+(X2%mod)*(a[pos]-pos)+X3-(X4%mod)*(a[pos]-pos);
			ans = (ans%mod+mod)%mod;
			printf("%lld\n",ans);
		}
	}
}