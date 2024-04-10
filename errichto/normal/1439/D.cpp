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

const int nax = 505;
int mod;
pair<int,int> dp[nax];
pair<int,int> frog[nax][nax];
int C[nax][nax];
// (cnt, sum)

void add_self(pair<int,int>& a, pair<int,int> b) {
	a.first = (a.first + b.first) % mod;
	a.second = (a.second + b.second) % mod;
}

pair<int,int> mul(pair<int,int> a, pair<int,int> b) {
	int cnt = (long long) a.first * b.first % mod;
	int sum = ((long long) a.first * b.second + (long long) a.second * b.first) % mod;
	return {cnt, sum};
}

int main() {
	int n, m;
	scanf("%d%d%d", &n, &m, &mod);
	for(int i = 0; i <= n; ++i) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}
	}
	dp[0] = {1, 0};
	// dp[1] = {2, 0};
	for(int s = 1; s <= n; ++s) {
		for(int n1 = 0; n1 < s; ++n1) {
			int n2 = s - 1 - n1;
			pair<int,int> p1 = dp[n1];
			pair<int,int> p2 = dp[n2];
			int cnt = 0, sum = 0;
			for(int i = 1; i <= n1; ++i) {
				cnt++;
				sum += i;
			}
			for(int i = 1; i <= n2; ++i) {
				cnt++;
				sum += i;
			}
			cnt += 2;
			sum += 2 * 0;
			cnt = (long long) cnt * C[n1+n2][n1] % mod;
			sum = (long long) sum * C[n1+n2][n1] % mod;
			// int s = n1 + n2 + 1;
			dp[s].first = (dp[s].first + (long long) cnt * p1.first % mod * p2.first) % mod;
			dp[s].second = (dp[s].second + (long long) p1.second * cnt % mod * p2.first + (long long) p2.second * cnt % mod * p1.first
				+ sum * (long long) p1.first % mod * p2.first) % mod;
		}
	}
	for(int s = 0; s <= n; ++s) {
		debug() << imie(s) imie(dp[s]);
	}
	// posi, cnt
	frog[1][0] = {1, 0};
	for(int i = 1; i <= n; ++i) {
		for(int cnt = 0; cnt <= m; ++cnt) {
			if(frog[i][cnt] == make_pair(0, 0)) {
				continue;
			}
			add_self(frog[i+1][cnt], frog[i][cnt]);
			for(int j = i; j <= n; ++j) {
				int used = j - i + 1;
				if(cnt + used > m) {
					break;
				}
				pair<int,int> tmp = dp[j-i+1];
				debug() << imie(i) imie(cnt) imie(j) imie(frog[i][cnt]) imie(tmp);
				int coef = C[used+cnt][cnt];
				tmp.first = (long long) tmp.first * coef % mod;
				tmp.second = (long long) tmp.second * coef % mod;
				add_self(frog[min(j+2,n+1)][cnt+used], mul(frog[i][cnt], tmp));
			}
		}
	}
	debug() << imie(frog[n+1][m]);
	// for(int i = 1; i <= n; ++i) {
	// for(int i = 1; i <= n; ++i) {
		// cerr << dp[i].first << " " << dp[i].second << endl;
	// }
	printf("%d\n", frog[n+1][m].second);
}