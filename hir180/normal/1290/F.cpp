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
const ll mod = 998244353;
template<class T>
void add(T&a,T b){
	a += b;
	if(a >= mod) a-= mod;
}
int n,m;
int x[5],y[5];
int dp[32][21][21][21][21][2][2];
vector<int>v[4];
int sum[4];
int vv[2][5];
int main(){
	cin >> n >> m;
	rep(i,n){
		int a,b; cin >> a >> b;
		if(a > 0) v[0].pb(a);
		else if(a < 0) v[1].pb(-a);
		
		if(b > 0) v[2].pb(b);
		else if(b < 0) v[3].pb(-b);
		vv[0][i] = a;
		vv[1][i] = b;
	}
	rep(w,4){
		for(auto a:v[w]) sum[w] += a;
	}
	dp[0][0][0][0][0][0][0] = 1;
	for(int i=0;i<31;i++){
		int b = ((m>>i)&1);
		rep(p,sum[0]+1)rep(q,sum[1]+1)rep(r,sum[2]+1)rep(s,sum[3]+1){
			rep(c1,2)rep(c2,2){
				if(dp[i][p][q][r][s][c1][c2] == 0) continue;
				rep(mask,(1<<n)){
					int ap = p, aq = q, ar = r, as = s;
					rep(i,n){
						if(((mask>>i)&1) == 0) continue;
						if(vv[0][i] > 0) ap += vv[0][i];
						else aq -= vv[0][i];
						
						if(vv[1][i] > 0) ar += vv[1][i];
						else as -= vv[1][i];
					}
					int bp = ap%2, np = ap/2;
					int bq = aq%2, nq = aq/2;
					int br = ar%2, nr = ar/2;
					int bs = as%2, ns = as/2;
					if(bp != bq || br != bs);
					else{
						int nc1,nc2;
						if(b > bp) nc1 = 0;
						else if(b == bp) nc1 = c1;
						else nc1 = 1;
						if(b > br) nc2 = 0;
						else if(b == br) nc2 = c2;
						else nc2 = 1;
						add(dp[i+1][np][nq][nr][ns][nc1][nc2],dp[i][p][q][r][s][c1][c2]);
					}
				}
			}
		}
	}
	ll ans = dp[31][0][0][0][0][0][0];
	ans += mod-1;
	cout << (ans%mod+mod)%mod << endl;
}