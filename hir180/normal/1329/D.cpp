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
struct B{
	vector<int>vec;
	void init(int sz){
		vec.clear();
		vec.resize(sz, 0);
	}
	void add(int i, int x){ i++; for(;i<vec.size();i+=i&-i) vec[i] += x; }
	int sum(int i){ i++; int ret = 0; for(;i;i-=i&-i) ret += vec[i]; return ret; }
}bit;

set<P>cut;
set<P1>adj[26];
int zan[26];
set<int>piece;
void solve(){
	string str;
	int n; cin >> str; n = str.size();
	cut.clear();
	rep(i, 26){
		adj[i].clear(); zan[i] = 0;
	}
	P p = mp(-1, -1);
	rep(i, n-1){
		if(str[i] == str[i+1]){
			if(p.fi >= 0 && p.sc != str[i]-'a'){
				adj[p.sc].insert(mp(p.fi, mp(i, str[i]-'a')));
				adj[str[i]-'a'].insert(mp(i, p));
			}
			p = mp(i, str[i]-'a');
			cut.insert(mp(i, str[i]-'a'));
			zan[str[i]-'a']++;
		}
	}
	bit.init(n+4);
	rep(i, n) bit.add(i, 1);
	rep(i, n) piece.insert(i);
	vector<P>ans;
	while(1){
		P mx = mp(-1, -1);
		int sum = 0;
		rep(i, 26){
			chmax(mx, mp(zan[i], i)); sum += zan[i];
		}
		if(mx.fi == sum) break;
		int id = mx.sc;
		assert(adj[id].size());
		auto it3 = adj[id].begin();
		int pos = (*it3).fi;
		int pos2 = (*it3).sc.fi, ty = (*it3).sc.sc;
		if(pos > pos2){
		    swap(pos, pos2); swap(id, ty);
		}
		ans.pb(mp(bit.sum(pos)+1, bit.sum(pos2)));
		//cout << pos << " " << id << " " << pos2 << " " << ty << " "
		//<< ans.back().fi << " " << ans.back().sc << endl;
		auto it2 = piece.lower_bound(pos+1);
		while(it2 != piece.end() && (*it2) <= pos2){
			bit.add((*it2), -1);
			piece.erase(it2++);
		}
		
		auto it = cut.find(mp(pos, id));
		assert(it != cut.end());
		it++;
		assert((*it) == mp(pos2, ty));
		P nxt = mp(-1, -1), pre = mp(-1, -1);
		it++;
		if(it != cut.end()) nxt = (*it);
		it--; it--;
		if(it != cut.begin()){
			it--; pre = (*it); it++;
		}
		if(pre.sc != -1 && pre.sc != id){
			adj[pre.sc].erase(mp(pre.fi, mp(pos, id)));
			adj[id].erase(mp(pos, pre));
		}
		
		if(id != ty){
			adj[id].erase(mp(pos, mp(pos2, ty)));
			adj[ty].erase(mp(pos2, mp(pos, id)));
		}
		else assert(0);
		if(nxt.sc != -1 && nxt.sc != ty){
			adj[ty].erase(mp(pos2, nxt));
			adj[nxt.sc].erase(mp(nxt.fi, mp(pos2, ty)));
		}
		
		if(pre.sc != -1 && nxt.sc != -1 && pre.sc != nxt.sc){
			adj[pre.sc].insert(mp(pre.fi, nxt));
			adj[nxt.sc].insert(mp(nxt.fi, pre));
		}
		cut.erase(mp(pos, id));
		cut.erase(mp(pos2, ty));
		zan[id]--; zan[ty]--;
	}
	auto it = cut.end();
	int pre = n-1;
	while(it != cut.begin()){
		it--;
		int pos = (*it).fi;
		ans.pb(mp(bit.sum(pos)+1, bit.sum(pre)));
		pre = pos;
	}
	ans.pb(mp(1, bit.sum(pre)));
	cout << ans.size() << '\n';
	rep(i, ans.size()){
		cout << ans[i].fi << " " << ans[i].sc << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) solve();
}