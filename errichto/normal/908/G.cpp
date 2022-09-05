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

const int mod = 1e9 + 7;
const int nax = 705;
int n;
int in[nax];
int dp[10][nax][nax][2]; // last bit means: already_smaller
int ten[nax];

void read() {
	string s;
	cin >> s;
	n = s.length();
	for(int i = 0; i < n; ++i)
		in[i] = s[i] - '0';
}
	

int main() {
	ten[0] = 1;
	for(int i = 1; i < nax; ++i)
		ten[i] = 10LL * ten[i-1] % mod;
	read();
	int answer = 0;
	for(int at_most = 0; at_most <= 9; ++at_most) {
		dp[at_most][0][0][0] = 1;
		for(int i = 0; i < n; ++i)
			for(int cnt = 0; cnt <= i; ++cnt)
				for(int already_smaller = 0; already_smaller <= 1; ++already_smaller) {
					int me = dp[at_most][i][cnt][already_smaller];
					if(!me) continue;
					for(int new_digit = 0; new_digit <= 9; ++new_digit)
						if(already_smaller || (new_digit <= in[i])) {
							int & x = dp[at_most][i+1][cnt+(new_digit<=at_most)][already_smaller || (new_digit<in[i])];
							x += me;
							if(x >= mod) x -= mod;
						}
				}
		for(int cnt = 0; cnt <= n; ++cnt) {
			int x = dp[at_most][n][cnt][0] + dp[at_most][n][cnt][1];
			if(x >= mod) x -= mod;
			if(!x) continue;
			debug() << imie(at_most) imie(cnt) imie(x);
			for(int i = cnt; i < n; ++i) {
				int mul = ten[n-1-i];
				answer = (answer + (long long) mul * x) % mod;
			}
		}
	}
	printf("%d\n", answer);
}