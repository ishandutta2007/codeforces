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

/*
set<string> expo(int n) {
	if(n == 1) {
		return {"+"};
	}
	set<string> all;
	for(int left = 1; left < n; ++left) {
		set<string> a = expo(left);
		set<string> b = expo(n - left);
		for(string s1 : a) {
			for(string s2 : b) {
				string total = s1 + s2;
				for(char& ch : total) {
					if(ch == '-') ch = '+';
					else ch = '-';
				}
				all.insert(total);
			}
		}
	}
	return all;
}*/

const int nax = 200123;
const long long INF = 1e18L + 5;
long long dp[nax][3][2];

void max_self(long long& a, long long b) {
	a = max(a, b);
}

int main() {
	/*for(int n = 3; n <= 10; ++n) {
		set<string> all = expo(n);
		map<int,int> freq;
		set<int> cnts;
		for(string s : all) {
			int cnt = 0;
			for(char ch : s) {
				if(ch == '+') {
					++cnt;
				}
			}
			++freq[cnt];
			cnts.insert(cnt);
		}
		debug() << imie(n) imie(cnts) imie(all.size());
	}*/
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i <= n; ++i) {
		for(int rem = 0; rem < 3; ++rem) {
			for(int pat = 0; pat < 2; ++pat) {
				dp[i][rem][pat] = -INF;
			}
		}
	}
	dp[0][0][n >= 3 && n % 2 == 1] = 0;
	for(int i = 0; i < n; ++i) {
		for(int rem = 0; rem < 3; ++rem) {
			for(int pat = 0; pat < 2; ++pat) {
				max_self(dp[i+1][(rem+1)%3][pat && i % 2 == 0], dp[i][rem][pat] + a[i]); // plus
				max_self(dp[i+1][rem][pat && i % 2 == 1], dp[i][rem][pat] - a[i]); // minus
			}
		}
	}
	printf("%lld\n", dp[n][(5-n%3)%3][0]);
}

// +-+-+-+-+

// +-+

// Conditions for a sequence of +- to be possible:
// 1) (N + cnt_pluses + 1) % 3 == 0
// 2) The string is not +-+-+-+

// dp[pos][rem_pluses][forbidden_pattern]