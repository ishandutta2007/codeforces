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
void o(T a){
	cout << a << '\n';
}
const ll mod = 1000000007;//998244353
//ios::sync_with_stdio(false);
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

int n,k;
int dv[1000005];
int zan[1000005];
vector<int>pr;
priority_queue<P,vector<P>,greater<P>>que;
ll ans;
int e[1000005];
int main(){
	for(int i=2;i<1000005;i++){
		if(dv[i]) continue;
		pr.pb(i);
		for(int j=2;i*j<1000005;j++){
			dv[i*j] = i;
		}
	}
	g(n); g(k);
	for(int i=3;i<=n;i++){
		vector<int>vec;
		int c = i;
		while(dv[c]){
			vec.pb(dv[c]);
			c /= dv[c];
		}
		vec.pb(c);
		ERASE(vec);
		int eu = i;
		rep(j,vec.size()){
			int x = i / vec[j];
			if(x >= 3) zan[i] ++;
			else if(x == 2 && i > 4){
				zan[i]++;
			}
			eu = eu / vec[j] * (vec[j]-1);
		}
		if(i != 4) e[i] = eu;
		else e[i] = 3;
		
		if(zan[i] == 0) que.push(mp(e[i],i));
	}
	vector<int>vi;
	rep(i,k){
		P q = que.top(); que.pop();
		ans += q.fi;
		int v = q.sc;
		rep(j,pr.size()){
			if(1LL*v*pr[j] > n) break;
			zan[v*pr[j]]--;
			if(zan[v*pr[j]] == 0) que.push(mp(e[v*pr[j]], v*pr[j]));
		}
		if(v == 4){
			v = 2;
			rep(j,pr.size()){
				if(1LL*v*pr[j] > n) break;
				zan[v*pr[j]]--;
				if(zan[v*pr[j]] == 0) que.push(mp(e[v*pr[j]], v*pr[j]));
			}
		}
	}
	//vector<P>vec;
	//for(int i=3;i<53;i++){
	//	for(int j=1;j<i;j++){
	//		int g = __gcd(j, i);
	//		int a = j/g;
	//		int b = i/g;
	//		vec.pb(P(a,b));
	//	}
	//}
	//SORT(vec); ERASE(vec);
	//cout << vec.size() << endl;
	o(ans+1);
}