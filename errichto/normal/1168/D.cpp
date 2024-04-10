#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
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

typedef long long ll;

#ifdef LOCAL
const int nax = 105;
#else
const int nax = 3e5 + 5;
#endif
int par[nax];
vector<int> children[nax];
char ch[nax];
int in[nax], out[nax];
int depth[nax];
pair<int,int> nxt_par[nax];
int T = 0;
int has[nax][26][2];
int total[nax];

struct Node {
	int big, lazy;
	void add(int x) {
		big += x;
		lazy += x;
	}
};

int B = 1;

struct Tree {
	vector<Node> tree;
	void rec(int id, int low, int high, int q_low, int q_high, int diff) {
		if(high < q_low || q_high < low) {
			return;
		}
		if(q_low <= low && high <= q_high) {
			tree[id].add(diff);
			return;
		}
		for(int b : {2 * id, 2 * id + 1}) {
			tree[b].add(tree[id].lazy);
		}
		tree[id].lazy = 0;
		int last_left = (low + high) / 2;
		rec(2 * id, low, last_left, q_low, q_high, diff);
		rec(2 * id + 1, last_left + 1, high, q_low, q_high, diff);
		tree[id].big = max(tree[2*id].big, tree[2*id+1].big);
	}
} trees[26];

void dfs(int a) {
	in[a] = ++T;
	for(int b : children[a]) {
		depth[b] = depth[a] + 1;
		dfs(b);
	}
	out[a] = T;
}

int bad;
void add(int i, int A, int diff) {
	debug();
	debug() << "add" imie(i) imie(A) imie(diff);
	trees[A].rec(1, 0, B - 1, in[i], out[i], diff);
	for(pair<int,int> x = nxt_par[i]; x.first; x = nxt_par[x.first]) {
		debug() << "> " imie(x);
		if(total[x.first] < 0) {
			--bad;
		}
		int Z = max(has[x.first][A][0], has[x.first][A][1]);
		total[x.first] += Z;
		has[x.first][A][x.second] += diff;
		int Y = max(has[x.first][A][0], has[x.first][A][1]);
		total[x.first] -= Y; //max(has[x.first][A][0], has[x.first][A][1]);
		if(total[x.first] < 0) {
			++bad;
		}
		if(total[x.first] < 0) {
			debug() << ">>> " imie(x) imie(has[x.first][A][0]) imie(has[x.first][A][1]) imie(total[x.first]);
			debug() << ">>>2 " imie(has[x.first][3][0]) imie(has[x.first][3][1]);
		}
		if(Z == Y) {
			break;
		}
	}
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 2; i <= n; ++i) {
		scanf("%d %c", &par[i], &ch[i]);
		children[par[i]].push_back(i);
	}
	for(int i = 2; i <= n; ++i) {
		int p = par[i];
		if((int) children[p].size() >= 2) {
			int which = -1;
			if(children[p][0] == i) {
				which = 0;
			}
			else if(children[p][1] == i) {
				which = 1;
			}
			else {
				assert(false);
			}
			nxt_par[i] = make_pair(p, which);
		}
		else {
			nxt_par[i] = nxt_par[p];
		}
	}
	dfs(1);
	int should = -1;
	for(int i = 2; i <= n; ++i) {
		if(children[i].empty()) {
			if(should == -1) {
				should = depth[i];
				continue;
			}
			if(should != depth[i]) {
				debug() << "spec";
				while(q--) {
					puts("Fou");
				}
				return 0;
			}
		}
	}
	assert(should != -1);
	while(B <= n) {
		B *= 2;
	}
	for(int i = 0; i < 26; ++i) {
		trees[i].tree.resize(2 * B, Node{0, 0});
	}
	for(int i = 1; i <= n; ++i) {
		total[i] = should - depth[i];
	}
	for(int i = 2; i <= n; ++i) {
		if(ch[i] != '?') {
			int A = ch[i] - 'a';
			add(i, A, 1);
		}
	}
	debug();
	debug() << imie(bad);
	while(q--) {
		int i;
		char letter;
		scanf("%d %c", &i, &letter);
		if(ch[i] != '?') {
			int A = ch[i] - 'a';
			add(i, A, -1);
		}
		ch[i] = letter;
		if(ch[i] != '?') {
			int A = ch[i] - 'a';
			add(i, A, 1);
		}
		vector<int> info(26);
		int suma = 0;
		for(int j = 0; j < 26; ++j) {
			info[j] = trees[j].tree[1].big;
			suma += info[j];
		}
		debug() << imie(suma) imie(should) imie(bad);
		if(suma > should || bad > 0) {
			puts("Fou");
		}
		else {
			long long answer = 0;
			for(int j = 0; j < 26; ++j) {
				answer += (long long) (j + 1) * (info[j] + should - suma);
			}
			// #warning print everything
			// puts("Shi");
			printf("Shi %lld\n", answer);
		}
		// debug() << imie(suma);
	}
}