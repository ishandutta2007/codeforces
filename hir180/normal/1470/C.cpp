//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
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
	return os<<"{"<<p.a<<","<<p.b<<"}";
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
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
int ask(int p){
	cout << "? " << p << endl;
	int v; cin >> v;
	return v;
}
void answer(int p){
	cout << "! " << p << endl;
	return;
}
int n, k;
void brute(){
	repn(i, n){
		int a = ask(i);
		if(a > k){
			int j = i-1;
			while(1){
				if(j == 0) j = n;
				int a = ask(j);
				if(a == k){
					answer(j);
					return;
				}
				j--;
			}
		}
	}
}
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	cin >> n >> k;
	if(n <= 400){
		brute();
		return;
	}
	rep(t, 334) ask(1);
	vc<int>cand;
	for(int i=1;i<=n;i+=334){
		cand.pb(i);
	}
	shuffle(all(cand), mt);
	rep(i, cand.size()){
		int v = ask(cand[i]);
		if(v > k){
			int a = cand[i];
			while(1){
				a -= 100;
				if(a <= 0) a += n;
				v = ask(a);
				if(v < k){
					while(1){
						a++;
						if(a == n+1) a = 1;
						v = ask(a);
						if(v == k){
							answer(a);
							return;
						}
					}
				}
			}
		}
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	solve();
}