#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 4;
multiset<int> adj[N];
list<int> ans; // Usage: ans.clear(), euler(st, ans.insert(ans.begin(), st));
void euler(int u, list<int>::iterator it) {
  for (auto it2 = adj[u].begin(); it2 != adj[u].end(); ) {
    int v=*it2; adj[u].erase(it2); /*undirected: adj[v].erase(adj[v].find(u));*/
    euler(v, ans.insert(it, v)); it2 = adj[u].begin(); }
}

bool solve(int a, int b, int c, int d, char s, char t) {
	int adown = 0;
	int aup = a - ('a'==t);
	if(aup < 0) return false;
	int bdown = a - ('a'==s);
	if(bdown < 0) return false;
	int bup = b - ('b'==t) - bdown;
	if(bup < 0) return false;
	int cdown = b - ('b'==s) - aup;
	if(cdown < 0) return false;
	int cup = c - ('c'==t) - cdown;
	if(cup < 0) return false;
	int ddown = c - ('c'==s) - bup;
	if(ddown < 0) return false;
	int dup = d - ('d'==t) - ddown;
	if(dup != 0) return false;
	//cerr<<"good @ "<<s<<" "<<t<<nl;

	vector<int> down = {adown,bdown,cdown,ddown};
	vector<int> up = {aup,bup,cup,dup};
	for(int i=0; i<4; i++) {
		//cerr<<i<<": "<<down[i]<<" "<<up[i]<<nl;
		while(down[i]--) {
			adj[i].insert(i-1);
		}
		while(up[i]--) {
			adj[i].insert(i+1);
		}
	}
	euler(s-'a', ans.insert(ans.begin(), s-'a'));
	//cerr<<"ans.size: "<<ans.size()<<nl;
	if(ans.size() != a+b+c+d) {
		for(int i=0; i<4; i++) {
			adj[i].clear();
		}
		ans.clear();
		return false;
	}
	cout << "YES" << nl;
	for(int it:ans) {
		cout << it << " ";
	}
	cout << nl;
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int a,b,c,d;
	cin >> a >> b >> c >> d;
	for(char i='a'; i<='d'; i++) {
		for(char j='a'; j<='d'; j++) {
			if(solve(a,b,c,d,i,j)) {
				return 0;
			}
		}
	}
	cout << "NO" << nl;

	return 0;
}