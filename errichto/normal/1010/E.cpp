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

struct P {
	int t[3];
	int id;
	int & operator [](int i) { return t[i]; }
	const int operator [](int i) const { return t[i]; }
	void read() {
		scanf("%d%d%d", &t[0], &t[1], &t[2]);
	}
	pair<int,int> other_two(int i) const {
		if(i == 0) return {t[1], t[2]};
		if(i == 1) return {t[0], t[2]};
		if(i == 2) return {t[0], t[1]};
		assert(false);
	}
};

const int QUERY = 0, OPEN = 1, CLOSED = 2;

struct S {
	int where, type, id;
	pair<int,int> p;
	bool operator <(const S & he) const {
		if(where != he.where) return where < he.where;
		return type < he.type;
	};
	string string_type() const {
		if(type == QUERY) return "QUERY";
		if(type == OPEN) return "OPEN";
		if(type == CLOSED) return "CLOSED";
		assert(false);
	}
};

void read(vector<P> & w, int n) {
	w.resize(n);
	for(P & p : w) p.read();
}

bool order(const P & small, const P & a, const P & big) {
	for(int i = 0; i < 3; ++i)
		if(!(small[i] <= a[i] && a[i] <= big[i]))
			return false;
	return true;
}
bool order(int a, int b, int c) { return a <= b && b <= c; }

const int nax = 1e5 + 5;
bool sure_closed[nax];
//~ const int pot = 128 * 1024;

int when[nax];

int main() {
	P N;
	N.read();
	int pot = 1;
	while(pot <= max({N[0], N[1], N[2]}) + 1) pot *= 2;
	//~ pot *= 2;
	int cnt_open, cnt_closed, q;
	scanf("%d%d%d", &cnt_open, &cnt_closed, &q);
	vector<P> open, closed, queries;
	read(open, cnt_open);
	read(closed, cnt_closed);
	read(queries, q);
	for(int i = 0; i < q; ++i) queries[i].id = i;
	P small = open[0], big = open[0];
	for(const P & p : open) {
		for(int i = 0; i < 3; ++i) {
			small[i] = min(small[i], p[i]);
			big[i] = max(big[i], p[i]);
		}
	}
	for(const P & p : closed)
		if(order(small, p, big)) {
			puts("INCORRECT");
			return 0;
		}
	puts("CORRECT");
	
	for(int i = 0; i < max({q, cnt_open, cnt_closed}); ++i)
		when[i] = -1;
	
	for(int turn = 0; turn < 3; ++turn) {
		debug();
		debug() << "-----------------------";
		debug();
		const int who_not = turn;// / 2;
		//~ const int mul = turn % 2 ? 1 : -1;
		pair<int,int> sm = small.other_two(who_not);
		pair<int,int> bi = big.other_two(who_not);
		vector<S> they;
		for(int type = 0; type < 3; ++type)
			for(const P & p : (type == OPEN ? open : (type == CLOSED ? closed : queries)))
				they.push_back(S{p[who_not], type, p.id, p.other_two(who_not)});
		sort(they.begin(), they.end());
		for(int rep = 0; rep < 2; ++rep) {
			if(rep == 1) {
				reverse(they.begin(), they.end());
				for(int i = 0; i < (int) they.size(); ++i) {
					int j = i;
					while(j + 1 < (int) they.size() && they[i].where == they[j+1].where)
						++j;
					reverse(they.begin() + i, they.begin() + j + 1);
					i = j;
				}
			}
			vector<set<pair<int,int>>> tr(2*pot);
			set<pair<int, int>> poziomo, pionowo;
			debug() << imie(sm) imie(bi);
			set<int> so_far;
			for(const S & s : they) {
				if(s.type == OPEN) break;
				int x = s.p.first, y = s.p.second;
				debug() << imie(x) imie(y) imie(s.string_type());
				if(s.type == QUERY) {
					if((x < sm.first || x > bi.first) && (y < sm.second || y > bi.second)) {
						if(when[s.id] == -1 || when[s.id] == turn) {
							when[s.id] = turn;
							for(int i = pot + x; i >= 1; i /= 2)
								tr[i].insert({y, s.id});
						}
					}
					poziomo.insert({x, s.id});
					pionowo.insert({y, s.id});
					so_far.insert(s.id);
				}
				else {
					assert(s.type == CLOSED);
					int ile = 0;
					// lewo
					if(x < sm.first && order(sm.second, y, bi.second)) {
						++ile;
						debug() << "lewo";
						while(!poziomo.empty()) {
							auto it = poziomo.begin();
							if(it -> first <= x) {
								sure_closed[it -> second] = true;
								poziomo.erase(it);
							}
							else break;
						}
					}
					// prawo
					if(x > bi.first && order(sm.second, y, bi.second)) {
						debug() << "prawo";++ile;
						while(!poziomo.empty()) {
							auto it = poziomo.end();
							--it;
							if(it -> first >= x) {
								sure_closed[it -> second] = true;
								poziomo.erase(it);
							}
							else break;
						}
					}
					// dol
					if(y < sm.second && order(sm.first, x, bi.first)) {
						debug() << "dol";++ile;
						while(!pionowo.empty()) {
							auto it = pionowo.begin();
							if(it -> first <= y) {
								sure_closed[it -> second] = true;
								pionowo.erase(it);
							}
							else break;
						}
					}
					// gora
					if(y > bi.second && order(sm.first, x, bi.first)) {
						debug() << "gora";++ile;
						while(!pionowo.empty()) {
							auto it = pionowo.end();
							--it;
							if(it -> first >= y) {
								sure_closed[it -> second] = true;
								pionowo.erase(it);
							}
							else break;
						}
					}
					
					// lewy dolny
					if(x < sm.first && y < sm.second) {
						debug() << "lewy dolny";++ile;
						for(int i = pot + x + 1; i >= 2; i /= 2)
							if(i % 2 == 1) {
								set<pair<int,int>> & secik = tr[i-1];
								while(!secik.empty()) {
									auto it = secik.begin();
									if(it -> first <= y) {
										sure_closed[it -> second] = true;
										secik.erase(it);
									}
									else break;
								}
							}
					}
					// lewy gorny
					if(x < sm.first && y > bi.second) {
						debug() << "lewy gorny";++ile;
						for(int i = pot + x + 1; i >= 2; i /= 2)
							if(i % 2 == 1) {
								set<pair<int,int>> & secik = tr[i-1];
								while(!secik.empty()) {
									auto it = secik.end();
									--it;
									if(it -> first >= y) {
										sure_closed[it -> second] = true;
										secik.erase(it);
									}
									else break;
								}
							}
					}
					// prawy dolny
					if(x > bi.first && y < sm.second) {
						debug() << "prawy dolny";++ile;
						for(int i = pot + x - 1; i >= 2; i /= 2)
							if(i % 2 == 0) {
								set<pair<int,int>> & secik = tr[i+1];
								while(!secik.empty()) {
									auto it = secik.begin();
									if(it -> first <= y) {
										sure_closed[it -> second] = true;
										secik.erase(it);
									}
									else break;
								}
							}
					}
					// prawy gorny
					if(x > bi.first && y > bi.second) {
						debug() << "prawy gorny";++ile;
						for(int i = pot + x - 1; i >= 2; i /= 2)
							if(i % 2 == 0) {
								set<pair<int,int>> & secik = tr[i+1];
								while(!secik.empty()) {
									auto it = secik.end();
									--it;
									if(it -> first >= y) {
										sure_closed[it -> second] = true;
										secik.erase(it);
									}
									else break;
								}
							}
					}
					debug() << imie(ile);
					//~ assert(ile == 1);
					if(ile == 0) {
						assert(order(sm.first, x, bi.first));
						assert(order(sm.second, y, bi.second));
						for(int id : so_far) sure_closed[id] = true;
						so_far.clear();
					}
				}
			}
		}
	}
	
	for(int i = 0; i < q; ++i) {
		if(order(small, queries[i], big)) {
			puts("OPEN");
			assert(!sure_closed[i]);
		}
		else if(sure_closed[i]) puts("CLOSED");
		else puts("UNKNOWN");
	}
}