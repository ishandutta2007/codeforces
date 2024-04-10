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
const ll mod = 998244353;
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
int pc(ll a){ return __builtin_popcountll(a); }
vector<ll>sol_naive2(vector<ll>a, int m){
	int sz = a.size();
	vector<ll>ans(m+1, 0);
	ll pre = 0, v = 0;
	rep(mask, (1<<sz)){
		if(mask == 0) ans[0]++;
		else{
			ll nw = mask ^ (mask >> 1);
			nw ^= pre;
			v ^= a[__builtin_ctzll(nw)];
			ans[pc(v)] ++;
			pre ^= nw;
		}
	}
	return ans;
}
#define bi unsigned __int128

//cnt[i]... number of ok mask with popcnt = i
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[100],R[100],bin[100];
void make(){
	F[0] = 1;
	bin[0] = 1;
	for(int i=1;i<100;i++) bin[i] = bin[i-1]*2LL%mod;
	for(int i=1;i<100;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<100;i++) R[i] = modpow(F[i],mod-2);
}
ll C(int a,int b){
	if(a < b) return 0LL;
	return F[a]*R[b]%mod*R[a-b]%mod;
}
vector<ll>calc(vector<bi>vec, int m);
vector<ll>calc2(vector<ll>a, int m);
vector<ll>sol_naive(vector<ll>a, int m);
#define B bitset<55>
void gauss(vector<pair<bi, B>> &vec, int m){
	int n = vec.size(), ran = 0;
	rep(j, m){
		int pivot = -1;
		for(int i=ran;i<n;i++){
			if( ((vec[i].fi>>j)&1) ){
				pivot = i; break;
			}
		}
		if(pivot == -1) continue;
		swap(vec[ran], vec[pivot]);
		for(int i=0;i<n;i++){
			if(i != ran && ((vec[i].fi>>j)&1) ){
				vec[i].fi ^= vec[ran].fi;
				vec[i].sc ^= vec[ran].sc;
			}
		}
		ran++;
	}
}
//vecxxor-sum0ret[x]ret
//vec0
vector<ll>calc(vector<bi>vec, int m){
	if(vec.size() == 0) return {1LL};
	else if(vec.size() == 1){
		assert(vec[0] > 0);
		return {1LL, 0LL};
	}
	int sz = vec.size();
	vector<pair<bi, B>>pr;
	rep(i, vec.size()){
		B b; b.reset(); b[i] = 1;
		pr.pb(mp(vec[i], b));
	}
	gauss(pr, m);
	vector<ll>vi, ret(vec.size()+1, 0);
	vector<pair<bi, B>>hg;
	
	rep(i, pr.size()){
		if(pr[i].fi != 0) continue;
		ll enc = 0;
		rep(j, sz) if(pr[i].sc[j]) enc ^= 1LL<<j;
		hg.pb(mp(enc, B()));
	}
	//if rank of this matrix is [0, 20] or [sz-18, sz], it'll be done
	gauss(hg, sz);
	rep(i, hg.size()){
		vi.pb(hg[i].fi);
	}

	int cnt = 0;
	vector<int>pos, num(vi.size(), 0);
	rep(i, sz){
		int id, zan = 0;
		rep(j, vi.size()){
			if(((vi[j]>>i)&1)) id = j, zan++;
		}
		if(zan > 1){
			cnt++;
			pos.pb(i);
		}
		else if(zan == 1) num[id]++;
	}
	int szz = vi.size();
	//bit DP
	if(cnt <= 18){
		vector<vector<ll>>ret = vector<vector<ll>>(sz+1, vector<ll>((1<<cnt), 0));
		ret[0][0] = 1;
		int pre = 0, fr = 0;
		rep(i, vi.size()){
		    int x = 0;
			rep(j, pos.size()) if(((vi[i]>>pos[j])&1)) x ^= (1<<j);
		    if(num[i] == 0){
		        assert(x == 0);
		        fr++; continue;
		    }
			for(int j=pre;j>=0;j--){
				for(int k=0;k<(1<<cnt);k++){
					if(ret[j][k] == 0) continue;
					ret[j+num[i]][k^x] += ret[j][k];
				}
			}
			pre += num[i];
		}
		vector<ll>ans(sz+1, 0);
		rep(x, sz+1) rep(j, (1<<cnt)){
			if(ret[x][j] == 0) continue;
			ans[x+pc(j)] += ret[x][j] * bin[fr] % mod;
		}
		rep(i, vi.size()+1) ans[i] %= mod;
		return ans;
	}
	if(vi.empty()){
		ret[0] = 1;
		return ret;
	}
	else{
		return calc2(vi, sz);
	}
}
//apopcnt(xor-sum) = xret[x]ret
vector<ll>calc2(vector<ll>a, int m){
	int nn = a.size();
	SORT(a); ERASE(a);
	int n = a.size();
	if(n <= 26){
		auto cnt = sol_naive2(a, m);
		ll S = 0;
		rep(k, m+1){
			cnt[k] = (cnt[k]%mod+mod)%mod;
			S = (S+cnt[k])%mod;
		}
		ll ss = modpow(2LL, nn);
		ss = ss*modpow(S,mod-2)%mod;
		rep(k, m+1){
			cnt[k] = (cnt[k]*ss%mod);
		}
		return cnt;
	}
	vector<bi>vs(n), vec;
	mt19937_64 mt(rand());
	rep(i, n) {
		bi A = mt();
		bi AA = mt();
		vs[i] = A*AA;
	}
	int z = 0;
	rep(j, m){
		bi hs = 0;
		rep(i, n){
			if(((a[i]>>j)&1LL)){
				hs ^= vs[i];
			}
		}
		if(hs == 0) z++;
		else vec.pb(hs);
	}
	//vec.size()+1
	auto ret = calc(vec, 128);
	vector<ll>ans(m+1, 0), cnt(m+1, 0);
	rep(i, ret.size()) rep(j, z+1){
		add(ans[i+j], ret[i] % mod * C(z, j) % mod);
	}
	rep(i, m+1){
		rep(k, m+1){
			ll coef = 0;
			for(int j=0;j<=k;j++){
				if(j%2 == 0) coef += C(i, j) * C(m-i, k-j) % mod;
				else coef -= C(i, j) * C(m-i, k-j) % mod;
			}
			coef = (coef%mod+mod)%mod;
			add(cnt[k], ans[i]*coef%mod);
		}
	}
	ll S = 0;
	rep(k, m+1){
		cnt[k] = (cnt[k]%mod+mod)%mod;
		S = (S+cnt[k])%mod;
	}
	ll ss = modpow(2LL, nn);
	ss = ss*modpow(S,mod-2)%mod;
	rep(k, m+1){
		cnt[k] = (cnt[k]*ss%mod);
	}
	return cnt;
}
int n, m;
int main(){
	srand((unsigned)time(NULL));
	ios::sync_with_stdio(false);
	make();
    cin >> n >> m;
	vector<ll>vi;
	mt19937_64 mt(614);
	rep(i, n){
		ll x; cin >> x; 
		vi.pb(x);
	}
	auto ans = calc2(vi, m);
	rep(i, m+1) o(ans[i]);
}