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

vector<int> find_earliest(string a, string b) {
	// for every position in b, find its first possible occurrence in a
	vector<int> ret;
	int nxt = 0;
	for(char ch : b) {
		while(a[nxt] != ch) {
			nxt++;
		}
		ret.push_back(nxt);
		nxt++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a;
	cin >> b;
	vector<int> one = find_earliest(a, b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vector<int> two = find_earliest(a, b);
	int answer = -1;
	for(int i = 0; i < (int) b.length() - 1; ++i) {
		int earliest = one[i];
		int latest = n-1-two[m-1-(i+1)];
		answer = max(answer, latest - earliest);
	}
	cout << answer << "\n";
}