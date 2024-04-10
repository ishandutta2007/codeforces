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

int n,a[1000005];
array<int,2> mx[(1<<21)];
void ch(int pos,int num){
	if(mx[pos][0] < num){
		mx[pos][1] = mx[pos][0];
		mx[pos][0] = num;
	}
	else if(mx[pos][1] < num && mx[pos][0] != num){
		mx[pos][1] = num;
	}
}
int main(){
	ios::sync_with_stdio(false);
	g(n);
	rep(i,(1<<21)) mx[i][0] = mx[i][1] = -INF;
	repn(i,n){
		g(a[i]);
		ch(a[i], i);
	}
	for(int i=(1<<21)-1;i>0;i--){
		for(int j=0;j<21;j++){
			if(!((i>>j)&1)) continue;
			//mx[i] -> mx[i^(1<<j)]
			ch(i^(1<<j), mx[i][0]);
			ch(i^(1<<j), mx[i][1]);
		}
	}
	int ans = 0;
	for(int i=20;i>=0;i--){
		//check if ans ^ (1<<i)
		int cur = ans ^ (1<<i), ok = 0;
		for(int j=1;j<=n;j++){
			int need = cur ^ (cur & a[j]);
			if(mx[need][1] > j){
				ok = 1;
				break;
			}
		}
		if(ok) ans ^= (1<<i);
	}
	o(ans);
}