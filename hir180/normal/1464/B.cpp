//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
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


int main(){
	ios::sync_with_stdio(false);
	string s; 
	ll x, y;
	cin >> s >> x >> y;
	if(x > y){
		reverse(all(s));
		swap(x, y);
	}
	
	int n = s.size();
	vector<int>rui(n+1, 0);
	vector<int>rui2(n+1, 0);
	ll cur = 0;
	vector<int>pos;
	rep(i, n){
		if(s[i] != '1'){
			cur += rui[i];
		}
		rui[i+1] = rui[i] + (s[i] == '1'?1:0);
		if(s[i] == '?') pos.pb(i);
	}
	for(int i=n-1;i>=0;i--){
	    rui2[i] = rui2[i+1] + (s[i] == '0'?1:0);
	}
	reverse(all(pos));
	ll ans = 1LL*cur*y + (1LL*(n-rui[n])*(rui[n]) - cur)*x;
	int zan = rui[n];
	rep(i, pos.size()){
		cur -= rui[pos[i]];
		cur += rui2[pos[i]+1];
		zan++;
		chmin(ans, 1LL*cur*y + (1LL*(n-zan)*(zan) - cur)*x);
	}
	cout << ans << endl;
}