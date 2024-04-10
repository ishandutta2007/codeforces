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
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

int n;

#define czassert(x) if(!(x))while(true);

vector<int> make_move(vector<int> v) {
	cout << v.size() << endl;
	for(int i = 0; i < (int) v.size(); ++i) {
		cout << v[i];
		if(i != (int) v.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;
	fflush(stdout);
	int start;
	cin >> start;
	czassert(start != -1);
	vector<int> retu;
	for(int i = 0; i < (int) v.size(); ++i) {
		retu.push_back(start);
		start++;
		if(start == n + 1) {
			start = 1;
		}
	}
	return retu;
}

int main(int argc, char* argv[]) {
	cin >> n;
	if(n <= 3) {
		cout << 0 << endl;
		return 0;
	}
	pair<int,int> best{-1, -1};
	for(int k = 2; k < n; ++k) {
		int zeros = (n + k - 1) / k;
		int ones = n - (zeros + k) + 1;
		best = max(best, make_pair(ones, k));
	}
	int k = best.second;
	vector<bool> on(n + 1);
	set<int> spec;
	for(int i = 1; i <= n; i += k) {
		spec.insert(i);
	}
	czassert((int) spec.size() == (n + k - 1) / k);
	int ones = 0;
	int turn = 0;
	while(true) {
		++turn;
		czassert(turn <= best.first + 2 && turn <= 10 * 1000 - 2);
		vector<int> gather;
		for(int i = 1; i <= n && (int) gather.size() < k; ++i) {
			if(!on[i] && !spec.count(i)) {
				gather.push_back(i);
			}
		}
		czassert((int) gather.size() == k);
		for(int x : gather) {
			on[x] = true;
		}
		vector<int> his = make_move(gather);
		for(int x : his) {
			on[x] = false;
		}
		int new_ones = 0;
		for(int x : on) {
			new_ones += x;
		}
		czassert(ones < new_ones);
		if(new_ones >= best.first) {
			cout << 0 << endl;
			return 0;
		}
		ones = new_ones;
	}
	assert(false);
}