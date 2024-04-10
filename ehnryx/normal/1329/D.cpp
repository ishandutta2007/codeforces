//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
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
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int M = 26;
const int N = 2e5 + 7;
int bit[N];

void init(int n) {
	fill(bit, bit+n+1, 0);
}

int query(int x) {
	int res = 0;
	for(++x; x>0; x-=x&-x) {
		res += bit[x];
	}
	return res;
}

void insert(int x, int v) {
	for(++x; x<N; x+=x&-x) {
		bit[x] += v;
	}
}

void insert_range(int l, int r, int v) {
	insert(l, v);
	insert(r+1, -v);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		int n = s.size();
		init(n+1);
		for(int i=0; i<n; i++) {
			insert_range(i, i, i+1);
		}

		set<int> adj, all;
		vector<int> cnt(M);
		for(int i=0; i<n; i++) {
			all.insert(i);
			if(i > 0 && s[i] == s[i-1]) {
				adj.insert(i);
				cnt[s[i]-'a']++;
			}
		}

		vector<vector<pair<int,int>>> ready(M);
		for(auto it=adj.begin(); it!=adj.end(); it++) {
			if(it != adj.begin() && s[*prev(it)] != s[*it]) {
				int l = *prev(it);
				int r = *it;
				ready[s[l]-'a'].push_back(make_pair(l, r));
				ready[s[r]-'a'].push_back(make_pair(r, l));
			}
		}

		vector<pair<int,int>> ans;
		while(!adj.empty()) {
			int c = 0;
			for(int i=1; i<M; i++) {
				if(cnt[i] > cnt[c]) {
					c = i;
				}
			}
			//cerr<<"removing letter "<<(char)(c+'a')<<nl;
			assert(cnt[c] > 0);

			int a, b;
			set<int>::iterator it;
gulag:
			if(ready[c].empty()) break;
			tie(a, b) = ready[c].back();
			ready[c].pop_back();
			it = adj.find(a);
			if(it == adj.end()) goto gulag;
			if(b < a && (it == adj.begin() || *prev(it) != b)) goto gulag;
			if(b > a && (next(it) == adj.end() || *next(it) != b)) goto gulag;

			//cerr<<"got ready: "<<a<<" "<<b<<nl;
			adj.erase(a);
			adj.erase(b);
			cnt[s[a]-'a']--;
			cnt[s[b]-'a']--;
			if(a > b) swap(a, b);
			for(auto jt = all.find(a); *jt != b; ) {
				jt = all.erase(jt);
			}
			int L = query(a);
			int R = query(b-1);
			ans.push_back(make_pair(L, R));
			insert_range(a, n-1, -(R-L+1));

			it = adj.lower_bound(a);
			if(it == adj.end() || it == adj.begin()) continue;
			if(s[*it] != s[*prev(it)]) {
				int l = *prev(it);
				int r = *it;
				ready[s[l]-'a'].push_back(make_pair(l, r));
				ready[s[r]-'a'].push_back(make_pair(r, l));
			}
		}

		while(!adj.empty()) {
			int l = *all.begin();
			int r = *adj.begin();
			adj.erase(adj.begin());
			for(auto it = all.begin(); *it != r; ) {
				it = all.erase(it);
			}
			int L = query(l);
			int R = query(r-1);
			ans.push_back(make_pair(L, R));
			insert_range(l, n-1, -(R-L+1));
		}

		assert(!all.empty());
		//cerr<<"all: "; for(int it : all) //cerr<<it<<" ";
		//cerr<<nl;
		ans.push_back(make_pair(query(*all.begin()), query(*all.rbegin())));

		cout << ans.size() << nl;
		for(auto [a, b] : ans) {
			cout << a << " " << b << nl;
		}
		//cerr<<nl;
	}

	return 0;
}