#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
//#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
int n,q;
ll magic;
ll mod;
vector<int>prm,lim;
int a[100005];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll MM[10][2000005];
struct seg{
	vector<int>seg[(1<<18)];
	ll val[(1<<18)];
	vector<int>lazy[(1<<18)];
	ll lazy2[(1<<18)];
	void push(int k){
		rep(i,seg[k].size()){
			if(lazy[k][i] != 0) goto nxt;
		}
		if(lazy2[k] != 1) goto nxt;
		return;
		nxt:;
		for(int w=2*k+1;w<=2*k+2;w++){
			rep(i,seg[k].size()){
				seg[w][i] += lazy[k][i];
				lazy[w][i] += lazy[k][i];
			}
			lazy2[w] = lazy2[w]*lazy2[k]%mod;
			val[w] = val[w]*lazy2[k]%mod;
		}
	    rep(i,seg[k].size()) lazy[k][i] = 0;
	    lazy2[k] = 1;
		return;
	}
	void upd(int k){
		ll Z1 = val[k*2+1], Z2 = val[k*2+2];
		rep(i,seg[k].size()){
			seg[k][i] = min(seg[k*2+1][i],seg[k*2+2][i]);
			int L = seg[k*2+1][i]-min(seg[k*2+1][i],seg[k*2+2][i]);
			int R = seg[k*2+2][i]-min(seg[k*2+1][i],seg[k*2+2][i]);
			if(L) Z1 = Z1*MM[i][L]%mod;
			if(R) Z2 = Z2*MM[i][R]%mod;
		}
		val[k] = (Z1+Z2)%mod;
	}
	void mul(int a,int b,int k,int l,int r,vector<int>vi,ll zan){
		if(r<a || b<l) return;
		if(a<=l&&r<=b){
			rep(i,vi.size()){
				seg[k][i] += vi[i];
				lazy[k][i] += vi[i];
			}
			val[k] = val[k]*zan%mod;
			lazy2[k] = lazy2[k]*zan%mod;
			return ;
		}
		push(k);
		mul(a,b,k*2+1,l,(l+r)/2,vi,zan);
		mul(a,b,k*2+2,1+(l+r)/2,r,vi,zan);
		upd(k);
	}
	ll query(int a,int b,int k,int l,int r){
		if(r<a || b<l) return 0LL;
		if(a<=l && r<=b){
			ll x = 1LL;
			rep(i,seg[k].size()){
				x = x*MM[i][seg[k][i]]%mod;
			}
			x = x*val[k]%mod;
			return x;
		}
		push(k);
		ll x = (query(a,b,k*2+1,l,(l+r)/2)+query(a,b,k*2+2,(l+r)/2+1,r));
		if(x<0) x += mod;
		if(x>=mod) x -= mod;
		return x;
	}
	void make(){
		rep(i,(1<<18)){
			val[i] = lazy2[i] = 1LL;
			seg[i].resize(prm.size(),0);
			lazy[i].resize(prm.size(),0);
		}
	}
	void init(int k,vector<int>vi,ll x){
		k += (1<<17)-1;
		seg[k] = vi;
		val[k] = x;
	}
	void upper(){
		for(int i=(1<<17)-2;i>=0;i--){
			upd(i);
		}
	}
}kaede;
int main(){
	scanf("%d%lld",&n,&mod);
	ll M = mod; magic = mod;
	for(ll i=2;i*i<=M;i++){
		if(M%i == 0){
			int c = 0;
			while(M%i==0){
				c++; M/=i;
			}
			prm.pb(i);
			lim.pb(c);
			magic = magic/i*(i-1);
		}
	}
	if(M != 1){
		prm.pb(M); lim.pb(1);
		magic = magic/M*(M-1);
	}
	for(int i=0;i<prm.size();i++){
		ll w = 1; MM[i][0] = w;
		for(int j=1;j<2000000;j++){
			w = w*1LL*prm[i]%mod;
			MM[i][j] = w;
		}
	}
	kaede.make();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		vector<int>vi; vi.resize(prm.size(),0);
		rep(j,prm.size()){
			int c = 0;
			while(a[i]%prm[j] == 0){
				a[i] /= prm[j];
				c++;
			}
			vi[j] = c;
		}
		kaede.init(i,vi,a[i]);
	}
	kaede.upper();
	scanf("%d",&q);
	rep(i,q){
		int id; scanf("%d",&id);
		if(id == 3){
			int L,R; scanf("%d%d",&L,&R);
			ll ans = kaede.query(L,R,0,0,(1<<17)-1);
			ans = (ans%mod+mod)%mod;
			printf("%lld\n",ans);
		}
		else if(id == 1){
			int L,R; ll X; scanf("%d%d%lld",&L,&R,&X);
			vector<int>vi; vi.resize(prm.size(),0);
			rep(j,prm.size()){
				int c = 0;
				while(X%prm[j] == 0){
					X /= prm[j];
					c++;
				}
				vi[j] = c;
			}
			kaede.mul(L,R,0,0,(1<<17)-1,vi,X);
		}
		else if(id == 2){
			int L; ll X; scanf("%d%lld",&L,&X);
			int R = L;
			vector<int>vi; vi.resize(prm.size(),0);
			rep(j,prm.size()){
				int c = 0;
				while(X%prm[j] == 0){
					X /= prm[j];
					c++;
				}
				vi[j] = -c;
			}
			X = modpow(X,magic-1);
			kaede.mul(L,R,0,0,(1<<17)-1,vi,X);
		}
	}
}