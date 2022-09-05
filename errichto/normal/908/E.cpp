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

const int nax = 1005;
bool ok[nax][nax];
bool vis[nax];
int C[nax][nax], B[nax];

int main() {
	for(int i = 0; i < nax; ++i) {
		C[i][i] = C[i][0] = 1;
		for(int j = 1; j < i; ++j)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
	}
	B[0] = 1;
	B[1] = 1;
	for(int n = 2; n < nax; ++n)
		for(int k = 0; k <= n-1; ++k)
			B[n] = (B[n] + (long long) C[n-1][k] * B[k]) % mod;
	debug() << imie(B[2]) imie(B[3]) imie(B[4]);
	int m, n;
	cin >> m >> n;
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < m; ++j)
			ok[i][j] = true;
	while(n--) {
		string s;
		cin >> s;
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < m; ++j)
				if(s[i] != s[j])
					ok[i][j] = false;
	}
	int answer = 1;
	for(int i = 0; i < m; ++i)
		if(!vis[i]) {
			int cnt = 1;
			for(int j = i + 1; j < m; ++j)
				if(ok[i][j]) {
					vis[j] = true;
					++cnt;
				}
			answer = (answer * (long long) B[cnt]) % mod;
		}
	printf("%d\n", answer);
}