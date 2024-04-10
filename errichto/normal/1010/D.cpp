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

const int nax = 1e6 + 5;
const int AND = 0, OR = 1, XOR = 2, NOT = 3, IN = 4;

int read_type() {
	static char sl[7];
	scanf("%s", sl);
	if(sl[0] == 'A') return AND;
	if(sl[0] == 'O') return OR;
	if(sl[0] == 'X') return XOR;
	if(sl[0] == 'N') return NOT;
	if(sl[0] == 'I') return IN;
	cout << sl << endl;
	assert(false);
}

int type[nax], init_value[nax];
vector<int> children[nax];
bool mark[nax];

int dfs_one(int a) {
	if(type[a] == IN) return init_value[a];
	if(type[a] == NOT) return init_value[a] = !dfs_one(children[a][0]);
	int L = dfs_one(children[a][0]);
	int R = dfs_one(children[a][1]);
	if(type[a] == AND) return init_value[a] = L && R;
	if(type[a] == XOR) return init_value[a] = L ^ R;
	if(type[a] == OR) return init_value[a] = L || R;
	assert(false);
}

void dfs_two(int a) {
	debug() << imie(a);
	mark[a] = true;
	if(type[a] == IN) return;
	if(type[a] == NOT) {
		dfs_two(children[a][0]);
		return;
	}
	for(int b : {0, 1}) {
		int L = init_value[children[a][0]], R = init_value[children[a][1]];
		if(b == 0) L = !L;
		else R = !R;
		int current = init_value[a];
		int would;
		if(type[a] == AND) would = L && R;
		else if(type[a] == XOR) would = L ^ R;
		else if(type[a] == OR) would = L || R;
		else assert(false);
		if(current != would) dfs_two(children[a][b]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int a = 0; a < n; ++a) {
		type[a] = read_type();
		if(type[a] == IN) {
			scanf("%d", &init_value[a]);
		}
		else {
			int cnt = 2;
			if(type[a] == NOT ) cnt = 1;
			while(cnt--) {
				int x;
				scanf("%d", &x);
				children[a].push_back(x-1);
			}
		}
	}
	dfs_one(0);
	dfs_two(0);
	int def_value = init_value[0];
	for(int a = 0; a < n; ++a)
		debug() << imie(a) imie(init_value[a]);
	for(int a = 0; a < n; ++a) if(type[a] == IN) {
		int answer = def_value;
		if(mark[a]) answer = 1 - answer;
		printf("%d", answer);
	}
	puts("");
}