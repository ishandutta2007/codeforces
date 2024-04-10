#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
#define USE_MAGIC_IO
#ifdef USE_MAGIC_IO
inline char get(void) {
	static char buf[100000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
inline void read(int &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}
#else
#define get() getchar()
#define read(x) scanf("%d",&x)
#endif

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

vector<int> primes;
void initp() {
	bitset<40000> isp;
	isp.set();
	isp[0] = isp[1] = false;
	for (int i = 2; i < 200; i++)
		if (isp[i])
			for (int j = i*i; j < 40000; j+=i)
				isp[j] = false;
	for (int i = 2; i < 40000; i++)
		if (isp[i])
			primes.push_back(i);
}

map<int,set<int>> primeset;
void getprimes(int n) {
	int lim = sqrt(n);
	for (int i = 0; primes[i] <= lim; i++) {
		if (n % primes[i] == 0) {
			int curr = 0;
			while (n % primes[i] == 0) {
				n /= primes[i];
				curr++;
			}
			primeset[primes[i]].insert(curr);
			lim = sqrt(n);
		}
	}
	if (n > 1) {
		primeset[n].insert(1);
	}
}

map<set<int>, int> dp; // true if first person wins
int grundy(set<int> curr) {
	if (curr.empty())
		return 0;
	if (dp.count(curr))
		return dp[curr];
	set<int> mem;
	set<int> next;
	int lim = *curr.rbegin();
	for (int i = 1; i <= lim; i++) {
		next.clear();
		for (int count: curr) {
			if (count > i) next.insert(count-i);
			else if (count < i) next.insert(count);
		}
		mem.insert(grundy(next));
	}
	int ans = 0;
	while (mem.count(ans))
		ans++;
	return dp[curr] = ans;
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	initp();
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		getprimes(a);
	}
	int ans = 0;
	for (pair<int,set<int>> p: primeset) {
		ans ^= grundy(p.second);
	}

	if (ans) cout << "Mojtaba" << nl;
	else cout << "Arpa" << nl;

	return 0;
}