#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return {i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (c it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(x...) " [" #x ": " << (x) << "] "

typedef long long ll;

const int mod = 1e9 + 7;

int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return (a + mod - b) % mod; }
int mul(int a, int b) { return (ll) a * b % mod; }
int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) r = mul(r, a);
		a = mul(a, a);
		b /= 2;
	}
	return r;
}
int my_inv(int a) { return my_pow(a, mod - 2); }
void add_self(int & a, int b) { a = add(a, b); }
void mul_self(int & a, int b) { a = mul(a, b); }

const int nax = 1005;
vector<pair<int,int>> w2[nax];

vector<int> solve_half(int cnt_left, int cnt_right) {
	cerr << "HALF " << cnt_left << " " << cnt_right << "\n";
	//~ printf("> %d %d\n", cnt_left, cnt_right);
	debug() << imie(cnt_left) imie(cnt_right);
	if(cnt_left > cnt_right) {
		static vector<pair<int,int>> lol[1005];
		for(int i = 0; i < cnt_left; ++i) {
			for(pair<int,int> & p : w2[i])
				p.first -= cnt_left;
			lol[cnt_right+i] = w2[i];
		}
		for(int i = 0; i < cnt_right; ++i) {
			lol[i] = w2[cnt_left+i];
			for(pair<int,int> & p : lol[i])
				p.first += cnt_right;
		}
		for(int i = 0; i < cnt_left + cnt_right; ++i)
			w2[i] = lol[i];
		swap(cnt_left, cnt_right);
	}
	assert(cnt_left <= cnt_right);
	vector<int> dp(1 << cnt_left);
	dp[0] = 1;
	for(int b = cnt_left; b < cnt_left + cnt_right; ++b)
		for(int mask = (1 << cnt_left) - 1; mask >= 0; --mask)
			for(const pair<int,int> & e : w2[b]) {
				int a = e.first;
				if(!(mask & (1 << a))) continue;
				add_self(dp[mask], mul(dp[mask ^ (1 << a)], e.second));
			}
	
	vector<int> r(cnt_left + 1);
	for(int mask = 0; mask < (1 << cnt_left); ++mask)
		add_self(r[__builtin_popcount(mask)], dp[mask]);
	debug() << imie(dp) imie(r);
	return r;
}

pair<int,int> parent[nax];
vector<int> children[nax];
bool vis_tree[nax], allowed[nax];
int depth[nax];
void dfs_tree(int a, vector<array<int,3>> & extra) {
	assert(!vis_tree[a]);
	vis_tree[a] = true;
	for(pair<int,int> e : w2[a]) {
		int b = e.first;
		if(b == parent[a].first) continue;
		if(vis_tree[b]) {
			if(depth[b] < depth[a])
				extra.push_back({a, b, e.second});
		}
		else {
			depth[b] = depth[a] + 1;
			parent[b] = {a, e.second};
			children[a].push_back(b);
			dfs_tree(b, extra);
		}
	}
}

vector<vector<int>> rec_dp(int a) {
	vector<vector<int>> dp(2);
	dp[0] = {1};
	dp[1] = {0};
	for(int b : children[a]) {
		vector<vector<int>> he = rec_dp(b);
		vector<vector<int>> merge(2, vector<int>(dp[0].size()+he[0].size()-1));
		for(int t1 : {0, 1}) for(int t2 : {0, 1}) if(!t1 || !t2) {
			for(int i = 0; i < (int) he[0].size(); ++i)
				for(int j = 0; j < (int) dp[0].size(); ++j)
					add_self(merge[max(t1,t2)][i+j], mul(he[t1][i], dp[t2][j]));
		}
		dp = merge;
	}
	
	// consider root
	vector<vector<int>> nowy(2, vector<int>(dp[0].size() + 1));
	for(int i = 0; i < (int) dp[0].size(); ++i) {
		nowy[0][i] = dp[0][i];
		if(allowed[a]) nowy[1][i] = mul(dp[0][i], parent[a].second);
	}
	if(allowed[a])
		for(int i = 0; i < (int) dp[1].size(); ++i)
			add_self(nowy[0][i+1], dp[1][i]);
	
	
	assert(nowy[0].size() == nowy[1].size());
	return nowy;
}

vector<int> solve_tree(int cnt_left, int cnt_right) {
	cerr << "TREE " << cnt_left << " " << cnt_right << "\n";
	
	vector<array<int,3>> extra;
	depth[0] = 0;
	dfs_tree(0, extra);
	
	cerr << "extra.size() == " << extra.size() << "\n";
	debug() << imie(extra);
	
	vector<int> r(cnt_left + 1);
	
	for(int mask = 0; mask < (1 << extra.size()); ++mask) {
		for(int i = 0; i < cnt_left + cnt_right; ++i)
			allowed[i] = true;
		int product = 1;
		for(int i = 0; i < (int) extra.size(); ++i)
			if(mask & (1 << i)) {
				int a = extra[i][0], b = extra[i][1];
				if(!allowed[a] || !allowed[b]) {
					product = 0;
					break;
				}
				allowed[a] = false;
				allowed[b] = false;
				mul_self(product, extra[i][2]);
			}
		if(!product) continue;
		vector<vector<int>> he = rec_dp(0);
		debug() << imie(product) imie(mask) imie(he);
		for(int i = 0; i < (int) he[0].size(); ++i) if(he[0][i])
			add_self(r[i + __builtin_popcount(mask)], mul(product, he[0][i]));
	}
	
	for(int i = 0; i < cnt_left + cnt_right; ++i) {
		vis_tree[i] = false;
		children[i].clear();
		parent[i] = {0, 0};
	}
	return r;
}

vector<int> any_solve(int cnt_left, int cnt_right) {
	if(min(cnt_left, cnt_right) <= 16)
		return solve_half(cnt_left, cnt_right);
	return solve_tree(cnt_left, cnt_right);
}





vector<pair<int,int>> w[nax];
bool done[nax];

void dfs_gather(int a, vector<int> & gather) {
	assert(!done[a]);
	done[a] = true;
	gather.push_back(a);
	for(const pair<int,int> & e : w[a])
		if(!done[e.first])
			dfs_gather(e.first, gather);
}

int main() {
	int size, k;
	cin >> size >> k;
	map<int, int> mapka[2];
	vector<array<int, 3>> edges;
	while(k--) {
		int a, b, spec;
		cin >> a >> b >> spec;
		--a; --b;
		spec = sub(spec, 1);
		if(!mapka[0].count(a)) {
			int tmp = mapka[0].size();
			mapka[0][a] = tmp;
		}
		a = mapka[0][a];
		if(!mapka[1].count(b)) {
			int tmp = mapka[1].size();
			mapka[1][b] = tmp;
		}
		b = mapka[1][b];
		edges.push_back({a, b, spec});
	}
	
	
	for(auto & e : edges)
		e[1] += mapka[0].size();
	
	debug() << imie(edges);
	
	for(auto & e : edges) {
		w[e[0]].push_back({e[1], e[2]});
		w[e[1]].push_back({e[0], e[2]});
	}
	
	const int V = mapka[0].size() + mapka[1].size();
	
	vector<int> total{1};
	
	for(int ii = 0; ii < V; ++ii) if(!done[ii]) {
		vector<int> gather;
		dfs_gather(ii, gather);
		debug() << imie(gather);
		sort(gather.begin(), gather.end());
		int cnt_left = 0, cnt_right = 0;
		for(int x : gather) {
			if(x < (int) mapka[0].size()) ++cnt_left;
			else ++cnt_right;
		}
		map<int,int> m2;
		for(int j = 0; j < (int) gather.size(); ++j)
			m2[gather[j]] = j;
		for(int x : gather)
			for(pair<int,int> e : w[x])
				w2[m2[x]].push_back({m2[e.first], e.second});
		
		vector<int> here = any_solve(cnt_left, cnt_right);
		assert(!here.empty());
		vector<int> product(here.size() + total.size() - 1);
		for(int i = 0; i < (int) here.size(); ++i)	
			for(int j = 0; j < (int) total.size(); ++j)
				add_self(product[i+j], mul(here[i], total[j]));
		total = product;
		
		for(int j = 0; j < (int) gather.size(); ++j)
			w2[j].clear();
	}
	
	debug() << imie(total);
	
	int answer = 0;
	vector<int> factorial(size + 1);
	factorial[0] = 1;
	for(int i = 1; i < (int) factorial.size(); ++i)
		factorial[i] = mul(i, factorial[i-1]);
	for(int taken = 0; taken < (int) total.size(); ++taken) {
		debug() << imie(taken) imie(size-taken) imie(total[taken]);
		add_self(answer, mul(total[taken], factorial[size-taken]));
	}
	
	printf("%d\n", answer);
}