//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//#define int long long
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())

#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.fi<<","<<p.sc<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
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
const ll mod = 1000000007;//998244353
//mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
bool val[2005], ans[4015];
bitset<2015>B[3005];
void solve(){
	int n, k;
	cin >> n >> k;
	int nxt = 1;
	int z[2005][2][2], tmp[2][2], M[3][2][2] = {};
	repn(i, n){
		z[i][0][0] = z[i][1][1] = 1;
		z[i][0][1] = z[i][1][0] = 0;
	}
	M[0][0][1] = M[0][1][0] = 1;
	M[1][0][0] = M[1][0][1] = M[1][1][1] = 1;
	M[2][0][0] = M[2][1][0] = M[2][1][1] = 1;
	
	rep(i, k){
		string str; 
		cin >> str;
		if(str == "RY"){
			int k; cin >> k;
			rep(i, k){
				int a; cin >> a;
				memset(tmp, 0, sizeof(tmp));
				rep(i, 2) rep(j, 2) rep(k, 2) tmp[i][k] += M[0][i][j] * z[a][j][k];
				rep(i, 2) rep(j, 2) z[a][i][j] = tmp[i][j]&1;
			}
		}
		else if(str == "RB"){
			int k; cin >> k;
			rep(i, k){
				int a; cin >> a;
				memset(tmp, 0, sizeof(tmp));
				rep(i, 2) rep(j, 2) rep(k, 2) tmp[i][k] += M[1][i][j] * z[a][j][k];
				rep(i, 2) rep(j, 2) z[a][i][j] = tmp[i][j]&1;
			}
		}
		else if(str == "YB"){
			int k; cin >> k;
			rep(i, k){
				int a; cin >> a;
				memset(tmp, 0, sizeof(tmp));
				rep(i, 2) rep(j, 2) rep(k, 2) tmp[i][k] += M[2][i][j] * z[a][j][k];
				rep(i, 2) rep(j, 2) z[a][i][j] = tmp[i][j]&1;
			}
		}
		else{
			assert(str == "mix");
			int k; cin >> k;
			rep(i, k){
				int a; cin >> a;
				if(z[a][0][0]) B[nxt][a*2]=1;
				if(z[a][0][1]) B[nxt][a*2+1]=1;
				if(z[a][1][0]) B[nxt+1][a*2]=1;
				if(z[a][1][1]) B[nxt+1][a*2+1]=1;
			}
			string S; cin >> S;
			if(S == "W"){
				val[nxt] = 0; val[nxt+1] = 0;
			}
			if(S == "Y"){
				val[nxt] = 1; val[nxt+1] = 0;
			}
			if(S == "R"){
				val[nxt] = 0; val[nxt+1] = 1;
			}
			if(S == "B"){
				val[nxt] = 1; val[nxt+1] = 1;
			}
			nxt += 2;
		}
	}
	int pre = 0;
	rep(i, 2015){
		for(int j=pre+1;j<nxt;j++){
			if(B[j][i] == 1){
				swap(B[pre+1], B[j]);
				swap(val[pre+1], val[j]);
				goto nxt;
			}
		}
		continue;
		nxt:;
		for(int j=1;j<=pre;j++){
			if(B[j][i] == 1){
				B[j] ^= B[pre+1];
				val[j] ^= val[pre+1];
			}
		}
		for(int j=pre+2;j<nxt;j++){
			if(B[j][i] == 1) {
				B[j] ^= B[pre+1];
				val[j] ^= val[pre+1];
			}
		}
		pre++;
	}
	rep(j, pre+1) {
	    rep(i, 2015) if(B[j][i] == 1){
	        ans[i] = val[j];
	        break;
	    }
	}
	for(int j=pre+1;j<nxt;j++) if(val[j]){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	string e = ".YRB";
	repn(i, n){
		int v = (int)(ans[i*2]) + (int)(ans[i*2+1])*2;
		cout << e[v] ;
	}
	cout << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}