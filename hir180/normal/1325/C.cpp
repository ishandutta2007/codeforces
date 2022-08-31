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
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

int n;
vector<int>edge[100005];
vector<P>vec;
map<P,int>ans;
int main(){
	g(n);
	rep(i,n-1){
		int a,b; g(a); g(b);
		edge[a].pb(b);
		edge[b].pb(a);
		if(a > b) swap(a,b);
		vec.pb(mp(a,b));
	}
	repn(i,n){
		if(edge[i].size() > 2){
			rep(j,3){
				int a = i, b = edge[i][j];
				if(a > b) swap(a,b);
				ans[mp(a,b)] = j;
			}
			goto nxt;
		}
	}
	rep(i,n-1) o(i);
	return 0;
	nxt:;
	int id = 3;
	rep(i,n-1){
		//cout<<vec[i].fi<<" "<<vec[i].sc<<endl;
		if(ans.find(vec[i]) != ans.end()) {
			o(ans[vec[i]]);
		}
		else o(id++);
	}
}