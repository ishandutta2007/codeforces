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

struct P {
	int x, y;
	int operator *(const P& he) const {
		return x * he.y - y * he.x;
	}
	P operator -(const P& he) const {
		return P{x - he.x, y - he.y};
	}
	bool operator <(const P&he) const {
		return *this * he < 0;
	}
};

int binom3(int n) {
	return (long long) n * (n - 1) * (n - 2) / 6;
}
int binom2(int n) {
	return n * (n - 1) / 2;
}

int main() {
	int n;
	cin >> n;
	vector<P> points(n);
	for(P& p : points) {
		cin >> p.x >> p.y;
	}
	int answer = binom3(n);
	debug() << imie(answer);
	for(P p : points) {
		vector<P> right;
		for(P q : points) {
			if(make_pair(q.x, q.y) > make_pair(p.x, p.y)) {
				right.push_back(q - p);
			}
		}
		sort(right.begin(), right.end());
		for(int i = 0; i < (int) right.size(); ++i) {
			int j = i;
			while(j + 1 < (int) right.size() && !(right[i] < right[j+1])) {
				j++;
			}
			debug() << imie(i) imie(j) imie(j - i + 1);
			answer -= binom2(j - i + 1);
			i = j;
		}
	}
	cout << answer << "\n";
}