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
#define read(x) scanf("%d",&x)
#define get() getchar()
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
	bitset<1000001> isp;
	isp.set();
	isp[0] = isp[1] = false;
	for (int i = 2; i < 1001; i++)
		if (isp[i])
			for (int j = i*i; j < 1000001; j+=i)
				isp[j] = false;
	for (int i = 2; i < 1000001; i++)
		if (isp[i])
			primes.push_back(i);
}

map<int,int> primecount;
void getprimes(int n) {
	int lim = sqrt(n);
	for (int i = 0; primes[i] <= lim; i++) {
		if (n % primes[i] == 0) {
			while (n % primes[i] == 0) {
				n /= primes[i];
			}
			primecount[primes[i]]++;
			lim = sqrt(n);
		}
	}
	if (n > 1) {
		primecount[n]++;
	}
}

struct Prime {
	int p;
	int cnt;
	Prime(int p, int cnt) {
		this->p = p;
		this->cnt = cnt;
	}
	bool operator < (const Prime& other) const {
		return cnt > other.cnt;
	}
};

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	initp();

	primecount[2] = INF;
	ll n, x, y;
	cin >> n >> x >> y;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		getprimes(arr[i]);
	}

	vector<Prime> check;
	for (pair<int,int> it: primecount) {
		check.push_back(Prime(it.first, it.second));
	} sort(check.begin(), check.end());

	ll ans = INFLL;
	ll curr;
	for (Prime p: check) {
		if (clock() > 1.789*CLOCKS_PER_SEC) {
			// VIVE LA REVOLUTION!!!
			break;
		}
		curr = 0;
		for (int i = 0; i < n; i++) {
			curr += min(x, y*((p.p - arr[i]%p.p)%p.p));
		}
		ans = min(ans, curr);
	}
	cout << ans << nl;

	return 0;
}