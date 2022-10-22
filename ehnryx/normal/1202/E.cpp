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

const int N = 2e5+1;
int lcnt[N], rcnt[N];

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
	int cnt[N];
	AhoCorasick(): root(new Node), wcnt(0) {
		memset(cnt,0,sizeof cnt);
	}

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

	void match(const string& s) {
		Node* u = root;
		for (int i=0; i<s.size(); i++) {
			while (u!=root && !u->ch.count(s[i])) u = u->p;
			if (u->ch.count(s[i])) u = u->ch[s[i]];
			for (Node* v=u; v->end!=root; v=v->p) {
				v = v->end; // get matches
				lcnt[i-v->d+1] += cnt[v->id];
				rcnt[i] += cnt[v->id];
			}
		}
	}
};
//*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	string s;
	cin >> s;
	int n = s.size();

	int m;
	cin >> m;
	AhoCorasick ac;
	unordered_map<string,int> id;
	for (int i=0; i<m; i++) {
		string v;
		cin >> v;
		if (!id.count(v)) {
			id[v] = ac.wcnt;
			ac.insert(v);
		}
		ac.cnt[id[v]]++;
	}
	ac.build();
	ac.match(s);

	ll ans = 0;
	for (int i=1; i<n; i++) {
		ans += (ll)lcnt[i] * rcnt[i-1];
	}
	cout << ans << nl;

	return 0;
}