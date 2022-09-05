#include <bits/stdc++.h>
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

set<vector<int>> pool;
// vector<int> hidden;
int n;

void gen() {
	n = 6;
	for(int rep = 0; rep < 10000; ++rep) {
		vector<int> v;
		for(int i = 0; i < n; ++i) {
			v.push_back(rand() % 4);
		}
		pool.insert(v);
	}
	// debug() << imie(hidden);
}

pair<int,int> score(vector<int> v) {
	int triples = 0, consecutive = 0;
	for(int x : v) {
		triples += x * (x - 1) * (x - 2) / 6;
	}
	for(int i = 0; i + 2 < n; ++i) {
		consecutive += v[i] * v[i+1] * v[i+2];
	}
	return {triples, consecutive};
}

vector<int> order;
vector<pair<int,int>> scores;



bool ok(vector<int> a) {
	int len = a.size();
	a.resize(n, -105);
	pair<int,int> cur = score(a);
	if(len == n && cur != scores[0]) {
		return false;
	}
	for(int turn = 0; turn < (int) order.size(); ++turn) {
		int i = order[turn];
		a[i]++;
		pair<int,int> new_score = score(a);
		int new_triples = new_score.first - cur.first;
		int new_cons = new_score.second - cur.second;
		int should_new_triples = scores[turn+1].first - scores[turn].first;
		int should_new_cons = scores[turn+1].second - scores[turn].second;
		if(a[i] >= 0 && new_triples != should_new_triples) {
			return false;
		}
		if(a[i] >= 0 && (i + 1 >= n || a[i+1] >= 0) && (i + 2 >= n || a[i+2] >= 0) && new_cons != should_new_cons) {
			return false;
		}
		cur = new_score;
	}
	return true;
}

void rec(vector<int> a) {
	if((int) a.size() == n) {
		cout << "!";
		for(int x : a) {
			cout << " " << x;
		}
		cout << endl;
		// debug() << imie(a);
		return;
		// exit(0);
	}
	for(int x = 0; x <= n; ++x) {
		a.push_back(x);
		if(ok(a)) {
			rec(a);
		}
		a.pop_back();
	}
}

void read() {
	int a, b;
	cin >> a >> b;
	scores.emplace_back(a, b);
}

int main(int argc, char* argv[]) {
	
	
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		order.push_back(i);
	}
	order.push_back(0);
	read();
	for(int i : order) {
		cout << "+ " << i + 1 << endl;
		read();
	}
	/*
	vector<int> hidden(n);
	for(int i = 0; i < n; ++i) {
		hidden[i] = rand() % 2;
		if(i % 17 == 0) {
			hidden[i] = rand() % n;
		}
		// cin >> hidden[i];
	}
	scores.push_back(score(hidden));
	for(int i : order) {
		hidden[i]++;
		scores.push_back(score(hidden));
	}*/
	
	rec({});
	
	// assert(false);
}