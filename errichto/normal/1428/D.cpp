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

void NO() {
	puts("-1");
	exit(0);
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	vector<int> ones;
	vector<int> others;
	vector<pair<int,int>> answer;
	vector<int> h(n);
	int nxt = n;
	for(int i = n - 1; i >= 0; --i) {
		int pair = -1;
		if(a[i] == 2) {
			if(ones.empty()) {
				NO();
			}
			pair = ones.back();
			ones.pop_back();
		}
		else if(a[i] == 3) {
			if(!others.empty()) {
				pair = others.back();
				others.pop_back();
			}
			else {
				if(ones.empty()) {
					NO();
				}
				pair = ones.back();
				ones.pop_back();
			}
		}
		debug() << imie(i) imie(pair);
		if(a[i] == 1) {
			ones.push_back(i);
		}
		if(a[i] >= 2) {
			others.push_back(i);
		}
		if(a[i] == 1) {
			assert(pair == -1);
			h[i] = nxt--;
			answer.emplace_back(h[i], i + 1);
		}
		else if(a[i] == 2) {
			h[i] = h[pair];
			answer.emplace_back(h[i], i + 1);
		}
		else if(a[i] == 3) {
			h[i] = nxt--;
			answer.emplace_back(h[i], pair + 1);
			answer.emplace_back(h[i], i + 1);
		}
	}
	printf("%d\n", (int) answer.size());
	for(pair<int,int> p : answer) {
		printf("%d %d\n", p.first, p.second);
	}
}