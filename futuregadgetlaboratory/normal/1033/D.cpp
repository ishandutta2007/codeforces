#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
const int N = 2000033;
const int LOG = 20;
const int mod = 998244353;
const int inf = 1e9 + 7;
int n, m;
LL cub[N];
inline LL Sq(LL x) {
	LL res = sqrt(x);
	while(res * res > x) res--;
	while(res * res < x) res++;
	return res;
}
int dx[4] = {1, 0, -1, 0};
LL gcd(LL x, LL y) {
	return y ? gcd(y, x % y) : x;
}
int dy[4] = {0, 1, 0, -1};
int main() {
	for(int i(1); i <= 2000000; i++) {
		cub[i] = (LL)i * i * i;
	}
	int n;
	scanf("%d", &n);
	map<LL, int> mp;
	vector<LL> pq;
	for(int i(1); i <= n; i++) {
		LL x;
		cin >> x;
		LL y = Sq(x);
		if(y * y == x) {
			LL z = Sq(y);
			if(z * z == y) {
				mp[z] += 4;
			}else {
				mp[y] += 2;
			}
		}else {
			auto itr = lower_bound(cub + 1, cub + 1 + 2000000, x);
			if(itr == cub + 1 + 2000000 || *itr != x) {
				pq.push_back(x);
			}else {
				mp[itr - cub] += 3;
			}
		}
	}
	vector<LL> primes;
	for(auto tmp : mp) {
		primes.push_back(tmp.first);
	}
	for(LL i : pq) {
		for(LL j : pq) {
			if(i != j) {
				LL g = gcd(i, j);
				if(g != 1) {
					primes.push_back(g);
					primes.push_back(i / g);
					primes.push_back(j / g);
				}
			}
		}
	}
	sort(primes.begin(), primes.end());
	primes.resize(unique(primes.begin(), primes.end()) - primes.begin());
	for(int op(0); op < (int)primes.size(); op++) {
		int p = primes[op];
		for(auto &t : pq) {
			if(t % p == 0) {
				primes.push_back(t / p);
				mp[t / p]++;
				mp[p]++;
				t = 1;
			}
		}
	}
	int ans = 1;
	for(auto tmp : mp) {
		ans = (LL)ans * (1 + tmp.second) % mod;
	}
	map<LL, int> mpq;
	for(auto t : pq) {
		if(t > 1) mpq[t]++;
	}
	for(auto tmp : mpq) {
		ans = (LL)ans * (1ll + tmp.second) % mod * (1ll + tmp.second) % mod;
	}
	cout << ans << endl;
}