#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 4e5+1;
vector<int> adj[N];
char pc[N];
vector<pii> ev[N];
int idx[N], ans[N], cnt[N];

////////////////////////////////////////////////////////////////////////
// Aho-Corasick String Matching -- O(n + m + numMatches)
// WARNING: all pattern strings must be different; patterns 0-indexed
//          change `int id` to `vector<int> id` for non-unique patterns
// USAGE:
//  0. AhoCorasick trie;
//  1. trie.insert(pattern) to insert patterns
//  2. trie.build() to build links once all words are inserted
//  3. auto matches = trie.match(string) to find words in string
//*!
struct AhoCorasick {
	struct Node {
		Node *end, *p;
		unordered_map<char,Node*> ch;
		int id, d;
		Node(int d=0): id(-1), d(d) {}
	};

	Node* root;
	int wcnt;
	AhoCorasick(): root(new Node), wcnt(0) {}

	void insert(const string& s) {
		Node* u = root;
		for (char c : s) {
			if (!u->ch.count(c)) u->ch[c] = new Node(u->d+1);
			u = u->ch[c];
		}
		assert(u->id == -1); u->id = wcnt++;
	}

	void build() {
		root->end = root; root->p = 0;
		queue<Node*> bfs; bfs.push(root);
		while (!bfs.empty()) {
			Node* u = bfs.front(); bfs.pop();
			for (const auto& it : u->ch) {
				char c; Node* v; tie(c,v) = it;
				Node* j = u->p;
				while (j && !j->ch.count(c)) j = j->p;
				v->p = (j ? j->ch[c] : root);
				v->end = (v->id == -1 ? v->p->end : v);
				bfs.push(v);
			}
		}
	}

	void match(int s, Node* u) {
		while (u!=root && !u->ch.count(pc[s])) u = u->p;
		if (u->ch.count(pc[s])) u = u->ch[pc[s]];
		for (Node* v=u; v->end!=root; v=v->p) {
			v = v->end;
			cnt[v->id]++;
		}
		for(pii it:ev[s]) {
			ans[it.second] = cnt[it.first];
		}
		for(int t : adj[s]) {
			match(t, u);
		}
		for (Node* v=u; v->end!=root; v=v->p) {
			v = v->end;
			cnt[v->id]--;
		}
	}
};
//*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		int t;
		cin>>t;
		if(t==1) {
			cin>>pc[i];
			adj[0].push_back(i);
		} else {
			int j;
			cin>>j>>pc[i];
			adj[j].push_back(i);
		}
	}

	int m;
	cin>>m;
	unordered_map<string,vector<int>> todo;
	for(int i=0;i<m;i++) {
		string s;
		cin>>idx[i]>>s;
		todo[s].push_back(i);
	}

	AhoCorasick ac;
	int id = 0;
	for(const auto& it:todo) {
		ac.insert(it.first);
		for(int j:it.second) {
			ev[idx[j]].push_back(pii(id,j));
		}
		id++;
	}
	ac.build();
	ac.match(0, ac.root);
	for(int i=0;i<m;i++) {
		cout<<ans[i]<<nl;
	}

	return 0;
}