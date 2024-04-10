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

const int nax = 1e5 + 5;
const int pot = 128 * 1024;
const int mod = 1e9 + 7;
int skill[nax];
int cnt_with[nax];

int init[2*pot];
int toLeft[nax][2];
vector<pair<int,int>> items[nax];

long long mul(int a, int b) {
	return (long long) a * b % mod;
}
void mul_self(int & a, int b) {
	a = mul(a, b);
}
long long add(int a, int b) {
	return (a + b) % mod;
}
void add_self(int & a, int b) {
	a = add(a, b);
}

struct Node {
	int cnt = 0, left[2] = {0, 0}, right[2] = {0, 0}, answer = 0;
	Node operator * (const Node & b) const {
		Node ret;
		ret.answer = add(answer, b.answer);
		add_self(ret.answer, add(  mul(left[0], b.right[1]), mul(left[1], b.right[0]) ));
		ret.left[0] = add(left[0], b.left[0]);
		ret.right[0] = add(right[0], b.right[0]);
		ret.cnt = add(cnt, b.cnt);
		ret.left[1] = add(left[1], add(b.left[1], mul(left[0], b.cnt)));
		ret.right[1] = add(right[1], add(b.right[1], mul(b.right[0], cnt)));
		return ret;
	}
	void write() {
		debug() << imie(cnt) << imie(left[0]) << imie(left[1]) << imie(right[0]) << imie(right[1]) << imie(answer);
	}
};

struct T {
	vector<pair<int,int>> memo_w;
	vector<Node> tr;
	int pot;
	void make(int i) {
		assert(i < pot);
		tr[pot+i].cnt = 1;
		tr[pot+i].left[0] = memo_w[i].first;
		tr[pot+i].right[0] = memo_w[i].second;
	}
	void init(vector<pair<int,int>> w) {
		memo_w = w;
		pot = 1;
		while(pot <= (int) w.size()) pot *= 2;
		tr.resize(2 * pot, Node());
		for(int i = 0; i < (int) w.size(); ++i)
			make(i);
		for(int i = pot - 1; i >= 1; --i)
			tr[i] = tr[2*i] * tr[2*i+1];
	}
	void update(int which) {
		assert(which < pot);
		for(int i = (pot + which) / 2; i >= 1; i /= 2)
			tr[i] = tr[2*i] * tr[2*i+1];
	}
	void remove(int which) {
		tr[which+pot] = Node();
		update(which);
	}
	void insert(int which) {
		make(which);
		update(which);
	}
} trees[nax];

int which[nax];
int answer[2*pot];

int main() {
	int n;
	scanf("%d", &n);
	vector<int> sorted;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &skill[i]);
		sorted.push_back(skill[i]);
	}
	sort(sorted.begin(), sorted.end());
	sorted.resize( unique(sorted.begin(), sorted.end()) - sorted.begin());
	map<int,int> mapka;
	for(int i = 0; i < (int) sorted.size(); ++i)
		mapka[sorted[i]] = i + 1;
	for(int i = 1; i <= n; ++i)
		skill[i] = mapka[skill[i]];
	
	debug() << range(skill + 1, skill + n + 1);
	
	for(int i = 1; i <= n; ++i) {
		int x = skill[i];
		++cnt_with[x];
		which[i] = cnt_with[x];
	}
	
	for(int repeat = 0; repeat < 2; ++repeat) {
		vector<int> order;
		for(int i = 1; i <= n; ++i)
			order.push_back(i);
		if(repeat) reverse(order.begin(), order.end());
		for(int i : order) {
			int x = skill[i];
			int low = pot, high = pot + x;
			int cnt = init[low];
			if(low != high) cnt += init[high];
			while(low < high - 1) {
				if(low % 2 == 0) cnt += init[low + 1];
				if(high % 2 == 1) cnt += init[high - 1];
				low /= 2;
				high /= 2;
			}
			toLeft[i][repeat] = cnt;
			for(int j = pot + x; j >= 1; j /= 2)
				init[j]++;
		}
		for(int i = 0; i < 2 * pot; ++i) init[i] = 0;
	}
	
	for(int i = 1; i <= n; ++i) {
		int x = skill[i];
		items[x].push_back(make_pair(toLeft[i][0], toLeft[i][1]));
	}
	for(int x = 0; x <= 20; ++x)
		if(!items[x].empty())
			debug() << imie(x) << imie(items[x]);
	
	for(int i = 0; i < nax; ++i)
		if(!items[i].empty()) {
			trees[i].init(items[i]);
			answer[pot+i] = trees[i].tr[1].answer;
			//trees[i].tr[1].write();
			//printf("%d\n", trees[i].tr[1].answer);
		}
	
	for(int i = pot - 1; i >= 1; --i)
		answer[i] = add(answer[2*i], answer[2*i+1]);
	
	int q;
	scanf("%d", &q);
	while(q--) {
		int type, who;
		scanf("%d%d", &type, &who);
		int x = skill[who];
		int where = which[who] - 1;
		if(type == 1) trees[x].remove(where);
		else trees[x].insert(where);
		answer[pot+x] = trees[x].tr[1].answer;
		for(int i = (pot + x) / 2; i >= 1; i /= 2)
			answer[i] = add(answer[2*i], answer[2*i+1]);
		printf("%d\n", answer[1]);
	}
}