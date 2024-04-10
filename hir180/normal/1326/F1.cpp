//Let's join Kaede Takagaki Fun Club !!
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
int n;
string f[20];
vector<int>part[(1<<17)];
map<vector<int>, ll> ans;
ll tmp[18][(1<<18)];
ll dp[(1<<18)];
ll way[(1<<17)];
vector<int>M[18];
vector<int>b[(1<<18)];
vector<int>sub[18][18];
int rev[(1<<18)];

void prepare(){
	rep(mask,(1<<(n-1))){
		int a[20];
		rep(i,n-1) a[i] = ((mask>>i)&1);
		int cur = 1;
		rep(i,n-1){
			if(a[i] == 1) cur++;
			else{
				part[mask].pb(cur);
				cur = 1;
			}
		}
		part[mask].pb(cur);
		SORT(part[mask]);
	}
	
	rep(i,n) tmp[i][(1<<i)] = 1;
	rep(mask,(1<<n)){
		rep(i,n){
			if( !((mask>>i)&1) ) continue;
			if(tmp[i][mask] == 0) continue;
			rep(j,n){
				if( ((mask>>j)&1) ) continue;
				if(f[i][j] == '0') continue;
				tmp[j][mask^(1<<j)] += tmp[i][mask];
			}
		}
		M[__builtin_popcount(mask)].pb(mask);
	}
	repn(i,n-1) rep(j,(1<<n)) tmp[0][j] += tmp[i][j];
	rep(i,n+1){
		rep(mask,(1<<i)){
			sub[__builtin_popcount(mask)][i].pb(mask);
		}
	}
	rep(mask,(1<<n)){
		rep(i,n){
			if(((mask>>i)&1)) b[mask].pb(i);
		}
	}
	rep(i,n) rev[(1<<i)] = i;
}
void rec(vector<int>vec, int sum){
	if(sum == n){
		ans[vec] = dp[(1<<n)-1];
		return;
	}
	int a = (vec.empty()?1:vec.back());
	
	for(int a=1;a+sum<=n;a++){
		if(sum == 0){
			for(auto at:M[a]) dp[at] = tmp[0][at];
		}
		else{
			for(auto at:M[a+sum]){
				int pre = -1, m;
				for(auto at2:sub[a][a+sum]) {
					//b[at]
					if(pre == -1){
						int look = 0;
						rep(i,a+sum) if(((at2>>i)&1)) look ^= (1<<b[at][i]);
						dp[at] += tmp[0][look] * dp[at ^ look];
						pre = at2; m = look;
					}
					else{
						int dup = (at2 & pre);
						int rem = pre ^ dup;
						int add = at2 ^ dup;
						while(rem){
							m ^= (1<<b[at][rev[rem&-rem]]);
							rem ^= (rem&-rem);
						}
						while(add){
							m ^= (1<<b[at][rev[add&-add]]);
							add ^= (add&-add);
						}
						dp[at] += tmp[0][m] * dp[at ^ m];
						pre = at2;
					}
				}
			}
		}
		vec.pb(a);
		rec(vec, sum+a);
		vec.pop_back();
		if(sum == 0){
			for(auto at:M[a]) dp[at] = 0;
		}
		else{
			for(auto at:M[a+sum]){
				int pre = -1, m;
				for(auto at2:sub[a][a+sum]) {
					//b[at]
					if(pre == -1){
						int look = 0;
						rep(i,a+sum) if(((at2>>i)&1)) look ^= (1<<b[at][i]);
						dp[at] -= tmp[0][look] * dp[at ^ look];
						pre = at2; m = look;
					}
					else{
						int dup = (at2 & pre);
						int rem = pre ^ dup;
						int add = at2 ^ dup;
						while(rem){
							m ^= (1<<b[at][rev[rem&-rem]]);
							rem ^= (rem&-rem);
						}
						while(add){
							m ^= (1<<b[at][rev[add&-add]]);
							add ^= (add&-add);
						}
						dp[at] -= tmp[0][m] * dp[at ^ m];
						pre = at2;
					}
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	g(n); rep(i,n) g(f[i]);
	prepare();
	rec(vector<int>(), 0);
	rep(i,(1<<(n-1))) way[i] = ans[part[i]];
	rep(j,n-1){
		rep(i,(1<<(n-1))) {
			if(((i>>j)&1)) continue;
			way[i] -= way[i^(1<<j)];
		}
	}
	rep(i,(1<<(n-1))) o(way[i]);
}