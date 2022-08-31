//Let's join Kaede Takagaki Fan Club !!
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
//segtree (x) BIT (y) 
//BITid
struct BIT_on_segtree{
	#define SZBos (1<<17)
	ll seg[SZBos*2];
	vector<ll>num[SZBos*2];
	vector<ll>bit[SZBos*2];
	void init(){
		//
		fill(seg,seg+SZBos*2,0LL);
	}
	//aNy
	void make(int a,ll N){
		a += SZBos-1;
		num[a].pb(N);
	}
	//
	void make2(){
		for(int i=SZBos-1;i<SZBos*2;i++){
			SORT(num[i]);
			ERASE(num[i]);
			bit[i].resize(num[i].size()+5,1LL);
		}
		for(int i=SZBos-2;i>=0;i--){
			num[i].resize(num[i*2+1].size()+num[i*2+2].size());
			merge(num[i*2+1].begin(),num[i*2+1].end(),num[i*2+2].begin(),num[i*2+2].end(),num[i].begin());
			bit[i].resize(num[i].size()+5,1LL);
		}
	}
	void make3(){
		for(int i=0;i<SZBos*2;i++){
			rep(j, bit[i].size()){
				if(j) bit[i][j] = bit[i][j] * bit[i][j-1] % mod;
			}
		}
	}
	int f(int x){
		return x&-x;
	}
	void upd(int wh,int pos,ll a){
		//segtreewh[1,pos]a
		//pos1-indexed
		bit[wh][pos] = bit[wh][pos] * a % mod;
	}
	//segtreekyval+a
	void doo(int k,ll a,ll val){
		//id
		int r = POSL(num[k],val);
		assert(num[k][r] == val);
		//1-indexedrr+1
		upd(k,r+1,a);
	}
	ll qquery(int wh,int pos){
		//segtreewh[1,pos]
		ll ret = bit[wh][pos];
	//	for(int s=pos;s>0;s-=f(s)){
	//		ret = ret * bit[wh][s] % mod;
	//	}
		return ret;
	}
	//xa, yval+nw
	void update(int a,ll nw,ll val){
		a += SZBos-1;
		doo(a,nw,val);
		while(a){
			a = (a-1)/2;
			doo(a,nw,val);
		}
	}
	//yupp
	ll query(int a,int b,int k,int l,int r,ll upp){
		if(r<a || b<l || a>b) return 1LL;
		if(a<=l && r<=b){
			int w = POSU(num[k],upp);
			//num[k][0]~num[k][w-1]1-indexedw
			return qquery(k,w);
		}
		ll L = query(a,b,k*2+1,l,(l+r)/2,upp);
		ll R = query(a,b,k*2+2,1+(l+r)/2,r,upp);
		return (L * R) % mod;
	}
}kaede;

ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}

int n, a[100005], q,  npr[200005];
vector<vector<int>>near_pos[105];
vector<int>ord[105];
ll x, y;
vector<int>pos[200005];


int main(){
	npr[1] = 1;
	for(int i=2;i<200005;i++){
		if(npr[i]) continue;
		for(int j=1;i*j<200005;j++){
			npr[i*j] = i;
		}
	}
	vector<int>spr;
	for(int i=2;i<=500;i++) if(npr[i] == i) spr.pb(i);
	scanf("%d", &n);
	rep(i, spr.size()) ord[i].resize(n+1);
	
	repn(i, n) {
		scanf("%d", &a[i]);
		int cnt[105]={}, bpr = -1;
		int A = a[i];
		while(A != 1){
			if(npr[A] <= 500){
				cnt[POSL(spr, npr[A])]++;
			}
			else bpr = npr[A];
			A /= npr[A];
		}
		rep(j, spr.size()){
			ord[j][i] = cnt[j];
		}
		if(bpr != -1) pos[bpr].pb(i);
	}
	
	ll all = 1;
	for(int i=501;i<200005;i++){
		if(pos[i].empty()) continue;
		all = all * i % mod;
		kaede.make(1, -1 * (pos[i][0]-1));
		kaede.make(pos[i].back()+1, -1 * n);
		rep(j, pos[i].size()-1){
			kaede.make(pos[i][j]+1, -1 * (pos[i][j+1]-1));
		}
	}
	kaede.make2();
	for(int i=501;i<200005;i++){
		if(pos[i].empty()) continue;
		ll rev = modpow(i, mod-2);
		kaede.update(1, rev, -1*(pos[i][0]-1));
		kaede.update(pos[i].back()+1, rev, -1 * n);
		rep(j, pos[i].size()-1){
			kaede.update(pos[i][j]+1, rev, -1 * (pos[i][j+1]-1));
		}
	}
	kaede.make3();
	rep(i, spr.size()){
		int mx = 0;
		repn(j, n) chmax(mx, ord[i][j]);
		near_pos[i].resize(mx+1, vector<int>(n+1, 0));
		for(int j=1;j<=mx;j++){
			for(int k=1;k<=n;k++){
				if(ord[i][k] >= j) near_pos[i][j][k] = k;
				else near_pos[i][j][k] = near_pos[i][j][k-1];
			}
		}
	}
	ll pre = 0;
	scanf("%d", &q);
	rep(i, q){
		scanf("%lld%lld", &x, &y);
		x = (x+pre) % n+1;
		y = (y+pre) % n+1;
		if(x > y) swap(x, y);
		ll cur = all;
		rep(j, spr.size()){
			for(int o=1;;o++){
				if(near_pos[j].size() <= o) break;
				if(near_pos[j][o][y] >= x){
					cur = cur * spr[j] % mod;
				}
				else break;
			}
		}
		cur = cur * kaede.query(1, x, 0, 0, (1<<17)-1, -1 * y) % mod;
		printf("%lld\n", cur);
		pre = cur;
	}
	return 0;
}