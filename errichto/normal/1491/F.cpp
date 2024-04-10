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

// summary:
// 1) I talked about C and D
// 2) I talked about Hash Code
// 3) I'm upsolving F

vector<int> hidden{0, +1, 0, 0, 0, -1, +1, 0, +1, -1};

int helper_sum(vector<int> a) {
	int sum = 0;
	for(int i : a) {
		sum += hidden[i-1];
	}
	return sum;
}

int query(vector<int> a, vector<int> b) {
	cout << "? " << a.size() << " " << b.size() << endl;
	for(int x : a) cout << x << " ";
	cout << endl;
	for(int x : b) cout << x << " ";
	cout << endl;
	int F;
	cin >> F;
	return F;
	// return helper_sum(a) * helper_sum(b);
}

void test_case() {
	int n = hidden.size();
	cin >> n;
	vector<int> prefix;
	for(int i = 2; i <= n; ++i) {
		prefix.push_back(i-1);
		if(query(prefix, {i}) != 0) {
			// found second nonzero
			// cout << i << endl;
			// BS first nonzero
			int low = 1, high = i - 1;
			while(low < high) {
				int mid = (low + high) / 2;
				vector<int> short_prefix;
				for(int j = 1; j <= mid; ++j) {
					short_prefix.push_back(j);
				}
				if(query(short_prefix, {i}) != 0) {
					high = mid;
				}
				else {
					low = mid + 1;
				}
			}
			int first = low;
			int second = i;
			vector<int> answer;
			for(int z = 1; z < i; ++z) {
				if(z != first) {
					answer.push_back(z);
				}
			}
			for(int j = i + 1; j <= n; ++j) {
				if(query({first}, {j}) == 0) {
					answer.push_back(j);
				}
			}
			cout << "! " << answer.size();
			for(int x : answer) {
				cout << " " << x;
			}
			cout << endl;
			// debug() << imie(answer);
			// cout << first << " " << second << endl;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while(T--) {
		test_case();
	}
}