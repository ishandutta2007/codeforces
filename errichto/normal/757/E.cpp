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
struct debug{
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
sim dor(const c &) { ris; }
#endif
};
#define imie(x) " [" << #x ": " << (x) << "] "

const int nax = 1e6 + 105;
const int mod = 1e9 + 7;
#define div div_compile
int div[nax];
vector<int> w[nax];
int c[nax][22];

int ans = 0;

void rec(int i, const vector<int> & vec, int n, int so_far) {
	if(i == (int) vec.size()) {
		//debug() << imie(so_far);
		ans += so_far;
		if(ans >= mod) ans -= mod;
		return;
	}
	for(int x = 0; x <= vec[i]; ++x) {
		int cut = vec[i] - x;
		if(cut == 0)
			rec(i + 1, vec, n, so_far);
		else if(n)
			rec(i + 1, vec, n, (long long) so_far * c[cut+n-1][cut] % mod);
		if(x == 0) {
			so_far *= 2;
			if(so_far >= mod) so_far -= mod;
		}
	}
}

int main() {
	for(int i = 0; i < nax; ++i) {
		c[i][0] = 1;
		for(int j = 1; j <= min(21, i); ++j)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
	}
	for(int i = 2; i * i < nax; ++i) if(!div[i])
		for(int j = i * i; j < nax; j += i)
			div[j] = i;
	for(int i = 2; i < nax; ++i) if(!div[i]) div[i] = i;
	//set<vector<int>> s;
	for(int i = 2; i < nax; ++i) {
		int x = i;
		int cnt = 0;
		while(x % div[i] == 0) {
			x /= div[i];
			++cnt;
		}
		w[i] = w[x];
		w[i].push_back(cnt);
		sort(w[i].begin(), w[i].end());
		//s.insert(w[i]);
		// debug() << imie(i) << imie(w[i]);
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int n, x;
		scanf("%d%d", &n, &x);
		int total = 1;
		for(int he : w[x]) {
			ans = 0;
			rec(0, vector<int>{he}, n, 1);
			total = (long long) total * ans % mod;
		}
		//ans = 0;
		//debug() << imie(w[x]);
		
		//rec(0, w[x], n, 1);
		printf("%d\n", total);
	}
	//printf("%d\n", (int) s.size());
}