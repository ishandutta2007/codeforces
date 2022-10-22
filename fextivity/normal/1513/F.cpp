#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define fileopen(a, b) freopen(((std::string)a + ".inp").c_str(), "r", stdin); freopen(((std::string)b + ".out").c_str(), "w", stdout);
#define fileopen1(a) freopen(((std::string)a + ".inp").c_str(), "r", stdin); freopen(((std::string)a + ".out").c_str(), "w", stdout);

#ifdef PICHU_LOCAL_DEF
	#include <chrono>
#endif


using namespace std;

#ifdef PICHU_LOCAL_DEF
	#define _getchar_nolock getchar_unlocked
#endif

inline void readInt(int &x) {
    char c;
    while (c = _getchar_nolock(), c <= ' ');
    
    bool sign(c == '-');
    if (sign) c = _getchar_nolock();
    
    x = (c - '0');
    while (c = _getchar_nolock(), !(c<'0'|c>'9')) x = 10 * x + c - '0';
    if (sign) x = -x;
}

#define ll long long

#define min sdfghjewjrehnuvobcdlreyiwrqagfvlcskhafkjhdsajk5huvkjsaklfhdlsafh
#define max hfdkoqwje4ehlfdjsalfhlsdjfkalsdjflsakdghaslkhjgasjgsadjhgasdhgkjashdgasdhghsdghsdghsghishgshgsdhgk
__attribute__((always_inline)) int min(int a, int b) {
	return (a < b) ? a : b;
}__attribute__((always_inline)) int max(int a, int b) {
	return (a > b) ? a : b;
}__attribute__((always_inline)) void smin(int &a, int b) {
	a = (a < b ? a : b);
}

const int MAXN = 2e5 + 5;
int a[MAXN], b[MAXN];
int pa[MAXN], pb[MAXN], qa[MAXN], qb[MAXN];
int p = 0, q = 0;

// p: a[i] < b[i]
// q: a[i] > b[i]

// Makes no sense to swap from same group

signed main() {
	#ifdef PICHU_LOCAL_DEF
		chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	#endif

	#ifndef PICHU_LOCAL_DEF
		// fileopen1("LAH");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; readInt(n);
	for (int i = 1; i <= n; i++) readInt(a[i]);
	for (int i = 1; i <= n; i++) readInt(b[i]);

	ll s = 0;

	for (int i = 1; i <= n; i++) {
		if (a[i] < b[i]) pa[p] = a[i], pb[p++] = b[i], s += b[i] - a[i];
		else if (a[i] > b[i]) qa[q] = a[i], qb[q++] = b[i], s += a[i] - b[i];
	}

	int res = 0, a, b;

	for (int i = 0; i < q; ++i) {
		a = qa[i]; b = qb[i];
		for (int j = 0; j < p; ++j) 
			smin(res, ((pa[j] > b) ? pa[j] : b) - (pb[j] < a ? pb[j] : a));	
	}
	
	cout << (ll)s + (ll)2 * res << '\n';

	#ifdef PICHU_LOCAL_DEF
		chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		std::cout << std::endl;
		std::cout << "Time difference = " << chrono::duration_cast<chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
	#endif
}