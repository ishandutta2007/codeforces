#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
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
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

vector<pair<int,int>> output;
const int nax = 30123;
vector<int> w_ans[nax];
void add_edge(int a, int b) {
	debug() << imie(a) imie(b);
	w_ans[a].push_back(b);
	w_ans[b].push_back(a);
	output.push_back({a+1, b+1});
}

void NO() {
	puts("-1");
	exit(0);
}

int n, k;

vector<vector<int>> input;
vector<int> where_zero;

void rec(const vector<vector<int>> & tree, int which_line) {
	
	debug() << "rec" imie(tree) imie(which_line);
	
	assert(!tree.empty());
	assert((int) tree[0].size() == 1);
	for(const vector<int> & row : tree)
		if(row.empty())
			NO();
	
	if(which_line == k) {
		for(int i = 1; i < (int) tree.size(); ++i)
			for(int x : tree[i])
				add_edge(tree[i-1][0], x);
		return;
	}
	
	const int spec = where_zero[which_line];
	int depth = -1;
	
	for(int d = 0; d < (int) tree.size(); ++d)
		for(int x : tree[d])
			if(x == spec)
				depth = d;
	
	if(depth == -1) {
		rec(tree, which_line + 1);
		return;
	}
	
	vector<  vector<vector<int>> > new_trees;
	
	for(int h = 0; h < (int) tree.size(); ++h)
		for(int x : tree[h]) {
			int dist = input[which_line][x];
			int lca = h + depth - dist;
			if(lca % 2) NO();
			lca /= 2;
			debug() << imie(lca);
			if(!(0 <= lca && lca < n)) NO();
			
			if((int) new_trees.size() <= lca)
				new_trees.push_back({});
			if((int) new_trees.size() <= lca)
				NO();
			
			vector<vector<int>> & that_tree = new_trees[lca];
			int how = h - lca;
			if((int) that_tree.size() <= how)
				that_tree.push_back({});
			if((int) that_tree.size() <= how)
				NO();
			that_tree[how].push_back(x);
		}
	
	for(const vector<vector<int>> & tr : new_trees)
		if(tr.empty() || tr[0].empty())
			NO();
	
	for(int i = 1; i < (int) new_trees.size(); ++i) {
		add_edge(new_trees[i][0][0], new_trees[i-1][0][0]);
	}
	
	for(const auto & xx : new_trees)
		rec(xx, which_line + 1);
}

void dfs(int a, int par, int so_far, const vector<int> & should) {
	debug() << "dfs" imie(a) imie(par) imie(so_far) imie(should);
	if(so_far != should[a])
		NO();
	for(int b : w_ans[a]) if(b != par)
		dfs(b, a, so_far + 1, should);
}

int main() {
	scanf("%d%d", &n, &k);
	
	input.resize(k, vector<int>(n));
	where_zero.resize(k);
	
	for(int which = 0; which < k; ++which) {
		vector<int> & line = input[which];
		int zeros = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &line[i]);
			if(line[i] == 0) {
				++zeros;
				where_zero[which] = i;
			}
		}
		if(zeros != 1) NO();
	}
	
	vector<vector<int>> tree;
	for(int i = 0; i < n; ++i) {
		int v = input[0][i];
		while((int) tree.size() <= v)
			tree.push_back({});
		tree[v].push_back(i);
	}
	debug() << imie(tree);
	rec(tree, 1);
	
	for(int i = 0; i < k; ++i)
		dfs(where_zero[i], -1, 0, input[i]);
	
	for(pair<int,int> p : output)
		printf("%d %d\n", p.first, p.second);
}