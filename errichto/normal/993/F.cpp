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
//~ eni(!=) cerr << boolalpha << i; ris; }
eni(!=) cerr << i; ris; }
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

const int AND = 0, OR = 1, NAND = 2, NOR = 3;
const int nax = 1005;

struct S {
	int type;
	S zmien() {
		S he;
		he.type = type ^ 1;
		return he;
	}
	void read() {
		static char sl[10];
		scanf("%s", sl);
		string s = string(sl);
		if(s == "and") type = AND;
		else if(s == "or") type = OR;
		else if(s == "nand") type = NAND;
		else if(s == "nor") type = NOR;
		else {
			cout << "unknown type: " << s << endl;
			assert(false);
		}
	}
	bool operator () (bool a, bool b) {
		if(type == AND) return a & b;
		if(type == OR) return a | b;
		if(type == NAND) return !(a & b);
		if(type == NOR) return !(a | b);
		assert(false);
	}
};

void read(pair<S, pair<int,int>> & p) {
	p.first.read();
	static char sl[105];
	scanf("%s", sl);
	int n = strlen(sl);
	vector<int> w;
	for(int i = 0; i < n; ++i)
		if(sl[i] == 'x')
			w.push_back(i);
	assert((int) w.size() == 2);
	p.second = {w[0], w[1]};
}

vector<int> w[nax];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<pair<S, pair<int,int>>> one(m), two(k);
	for(int i = 0; i < m; ++i)
		read(one[i]);
	for(int i = 0; i < k; ++i)
		read(two[i]);
	
	const int M = 40 * 1000;
	vector<pair<vector<bool>, vector<bool>>> pre(M);
	for(auto & p : pre) {
		vector<bool> a(n), b(m), c(k), d(k);
		for(int i = 0; i < n; ++i) a[i] = rand() % 2;
		for(int i = 0; i < m; ++i) b[i] = one[i].first(a[one[i].second.first], a[one[i].second.second]);
		for(int i = 0; i < k; ++i) c[i] = two[i].first(b[two[i].second.first], b[two[i].second.second]);
		for(int i = 0; i < k; ++i) d[i] = two[i].first.zmien()(b[two[i].second.first], b[two[i].second.second]);
		p = {c, d};
	}
	vector<bool> maybe(k, true);
	for(auto & p : pre) {
		auto & c = p.first;
		auto & d = p.second;
		debug() << imie(c);
		for(int i = 0; i < k; ++i) if(c[i] & d[i]) maybe[i] = false;
		bool any = false;
		for(int i = 0; i < k; ++i) if(maybe[i]) if(c[i] | d[i]) any = true;
		if(!any) {
			puts("-1");
			return 0;
		}
	}
	
	vector<vector<bool>> e(k, vector<bool>(k));
	
	for(auto & p : pre) {
		auto & c = p.first;
		auto & d = p.second;
		debug() << imie(c);
		debug() << imie(d);
		debug();
		for(int i = 0; i < k; ++i) if(maybe[i])
			for(int j = i + 1; j < k; ++j) if(maybe[j])
				if((c[i] & d[j]) | (c[j] & d[i])) e[i][j] = e[j][i] = true;
	}
	
	for(int i = 0; i < k; ++i)
		for(int j = i + 1; j < k; ++j) if(e[i][j]) {
			w[i].push_back(j);
			w[j].push_back(i);
			//~ printf("%d %d\n", i, j);
		}
	
	int answer = 0;
	for(int i = 0; i < k; ++i) if(!maybe[i]) ++answer;
	vector<bool> vis(k);
	vector<pair<vector<int>, vector<int>>> they;
	vector<bool> taken(k);
	for(int i = 0; i < k; ++i) if(maybe[i] && !vis[i]) {
		vector<int> A, B;
		vector<int> kol{i};
		vector<int> dist(k);
		vis[i] = true;
		for(int j = 0; j < (int) kol.size(); ++j) {
			int a = kol[j];
			if(dist[a] % 2) A.push_back(a);
			else B.push_back(a);
			for(int b : w[a]) if(!vis[b]) {
				vis[b] = true;
				dist[b] = dist[a] + 1;
				kol.push_back(b);
			}
		}
		if(A.size() < B.size()) swap(A, B);
		// bierzemy pierwsza
		they.push_back({A, B});
		for(int x : A) taken[x] = true;
		
		//~ printf("%d %d\n", A, B);
		answer += (int) B.size();
	}
	bool yeah = true;
	for(auto & p : pre) {
		auto & c = p.first;
		auto & d = p.second;
		bool any = false;
		for(int i = 0; i < k; ++i) if(taken[i]) if(c[i] | d[i]) any = true;
		if(!any) {
			yeah = false;
			break;
		}
	}
	
	if(!yeah) for(pair<vector<int>, vector<int>> p : they) {
		int by = 1000000;
		auto memo = taken;
		for(int x : p.first) {
			assert(taken[x]);
			taken[x] = false;
		}
		for(int x : p.second) {
			assert(!taken[x]);
			taken[x] = true;
		}
		
		bool tu = true;
		for(auto & p : pre) {
			auto & c = p.first;
			auto & d = p.second;
			bool any = false;
			for(int i = 0; i < k; ++i) if(taken[i]) if(c[i] | d[i]) any = true;
			if(!any) {
				tu = false;
				break;
			}
		}
		if(tu) by = min(by, (int) abs(int(p.first.size()) - int(p.second.size())));
		
		taken = memo;
		answer += by;
	}
	if(answer > k) answer = -1;
	
	
	printf("%d\n", answer);
	return 0;
	
	//~ int answer = -1;
	for(int mask = 0; mask < (1 << k); ++mask) {
		bool ok = true;
		for(int i = 0; i < k; ++i) if(mask & (1 << i)) if(!maybe[i]) ok = false;
		if(!ok) continue;
		for(int rep = 0; rep < 200; ++rep) {
			vector<bool> a(n), b(m), c(k), d(k);
			for(int i = 0; i < n; ++i) a[i] = rand() % 2;
			for(int i = 0; i < m; ++i) b[i] = one[i].first(a[one[i].second.first], a[one[i].second.second]);
			for(int i = 0; i < k; ++i) c[i] = two[i].first(b[two[i].second.first], b[two[i].second.second]);
			for(int i = 0; i < k; ++i) d[i] = two[i].first.zmien()(b[two[i].second.first], b[two[i].second.second]);
			//~ debug() << imie(c);
			//~ debug() << imie(d);
			//~ debug();
			bool raz = false, dwa = false;
			for(int i = 0; i < k; ++i) if(mask & (1 << i)) {
				if(c[i]) raz = true;
				if(d[i]) dwa = true;
			}
			if(raz && dwa) ok = false;
			if(!raz && !dwa) ok = false;
			if(!ok) break;
			//~ for(int i = 0; i < k; ++i)
				//~ if(c[i] && d[i])
					//~ maybe[i] = false;
		}
		if(ok) answer = max(answer, __builtin_popcount(mask));
		//~ debug() << imie(maybe);
	}
	assert(answer != -1);
	
	//~ if(answer == -1) printf("%d\n", answer);
	//~ else printf("%d\n", k - answer);
	
	printf("%d\n", k - answer);
}