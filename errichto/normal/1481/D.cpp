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

void test_case() {
	int n, len;
	cin >> n >> len;
	vector<string> edge(n);
	for(int row = 0; row < n; ++row) {
		cin >> edge[row];
	}
	for(int a = 0; a < n; ++a) {
		for(int b = a + 1; b < n; ++b) {
			if(edge[a][b] == edge[b][a]) {
				// keep moving between them
				cout << "YES\n";
				for(int i = 0; i < len + 1; ++i) {
					cout << (i % 2 ? a : b) + 1 << " ";
				}
				cout << "\n";
				return;
			}
		}
	}
	// every direction is opposite
	if(len % 2 == 1) {
		// go back and forth, abababa
		cout << "YES\n";
		for(int i = 0; i <= len; ++i) {
			cout << (i % 2 ? 1 : 2) << " ";
		}
		cout << "\n";
		return;
	}
	if(len % 2 == 0) {
		for(int a = 0; a < n; ++a) {
			int b = (a + 1) % n;
			for(int c = 0; c < n; ++c) {
				if(c != a && c != b && edge[a][b] != edge[a][c]) {
					vector<int> order;
					if(len % 4 == 2) {
						order.push_back(b);
					}
					for(int i = 0; i < len / 4; ++i) {
						order.push_back(a);
						order.push_back(b);
					}
					for(int i = 0; i < len / 4; ++i) {
						order.push_back(a);
						order.push_back(c);
					}
					order.push_back(a);
					if(len % 4 == 2) {
						order.push_back(c);
					}
					cout << "YES\n";
					for(int x : order) {
						cout << x + 1 << " ";
					}
					cout << "\n";
					return;
				}
			}
		}
		assert(n == 2);
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		test_case();
	}
}