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

const int nax = 105;
int dp[nax][nax*nax]; // dp[taken][sum_ai]
const int INF = 1e9 + 5;

void maxi(int& a, int b) {
	a = max(a, b);
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < nax; ++i) {
		for(int k = 0; k < nax * nax; ++k) {
			dp[i][k] = -INF;
		}
	}
	dp[0][0] = 0;
	dp[0][0] = 0;
	double sum_all = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		sum_all += b[i];
		for(int taken = i; taken >= 0; --taken) {
			for(int sum = 0; sum <= taken * 100; ++sum) {
				int me = dp[taken][sum];
				if(me < 0) {
					continue;
				}
				maxi(dp[taken+1][sum+a[i]], me + b[i]);
			}
		}
	}
	vector<double> answer(n + 1);
	for(int taken = 1; taken <= n; ++taken) {
		for(int sum_a = 0; sum_a <= taken * 100; ++sum_a) {
			int sum_b = dp[taken][sum_a];
			if(sum_b < 0) {
				continue;
			}
			answer[taken] = max(answer[taken], min((double) sum_a, (sum_all + sum_b) / 2.0));
		}
	}
	for(int i = 1; i <= n; ++i) {
		printf("%.10lf ", answer[i]);
	}
	puts("");
}