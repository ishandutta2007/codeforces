#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

using namespace std;

template <typename T>
T extGcd(T a, T b, T& x, T& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		int g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

template <typename T>
T modInv(T a, T m) {
	T x, y;
	extGcd(a, m, x, y);
	return (x % m + m) % m;
}

const int mod = 1000000007;
int h,w,n;
pair<int, int> points[2100];
long long pat[2100];
long long fac[210000];
long long ifac[210000];

long long C(int n, int k) {
	long long t = fac[n];
	t = (t * ifac[k]) % mod;
	t = (t * ifac[n-k]) % mod;
	return t;
}

int main() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fac[i] = (fac[i-1] * 1ll * i) % mod;
		ifac[i] = (ifac[i-1] * 1ll * modInv(i, mod)) % mod;
	}

	scanf("%d %d %d", &h, &w, &n);
	REP(i,n) scanf("%d %d", &points[i].first, &points[i].second);
	sort(points,points+n);

	long long ans = C(h+w-2,h-1);
	//printf("ans = %lld\n", ans);
	REP(i,n) {
		pat[i] = C(points[i].first + points[i].second - 2, points[i].first - 1);
		
		REP(j,i) {
			if (points[j].first <= points[i].first && points[j].second <= points[i].second) {
				pat[i] = (pat[i] - pat[j] * 1ll * C(points[i].first - points[j].first + points[i].second - points[j].second, points[i].first - points[j].first));
				pat[i] = (pat[i] + mod) % mod;
			}
		}

		//printf("pat %d = %lld\n", i, pat[i]);
		ans = (ans - pat[i] * 1ll *  C(h + w - points[i].first - points[i].second, h - points[i].first)) % mod;
	}

	ans = (ans + mod) % mod;
	printf("%lld\n", ans);
}