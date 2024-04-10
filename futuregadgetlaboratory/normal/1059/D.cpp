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
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int x[N], y[N];
typedef double D;
int main() {
	int n;
	scanf("%d", &n);
	bool a =false, b = false;
	for(int i(1); i <= n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		if(y[i] > 0) a = true;
		else b = true;
		assert(y[i] != 0);
	}
	if(a && b){
		printf("-1\n");
		exit(0);
	}
	D le = 0, ri = 1e16;
	for(int i(0); i < 100; i++) {
		D mid = (le + ri) / 2;
		D l = -1e16, r = 1e16;
		bool flag =true;
		for(int j(1); j <= n; j++) {
			int x = ::x[j], y = abs(::y[j]);
			if(y > mid * 2) {
				flag = false;
				break;
			}else {
				D delta = sqrt(max(0., 2 * mid * y - (LL)y * y));
				l = max(l, x - delta);
				r = min(r, x + delta);
			}
		}
		if(!flag || l > r) {
			le = mid;
		}else {
			ri = mid;
		}
	}
	printf("%.12f\n", (le + ri) / 2);
}