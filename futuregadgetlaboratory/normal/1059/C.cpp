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
int main() {
	int n;
	scanf("%d", &n);
	int mul = 1;
	vector<int> res;
	for(;;) {
		//cout << n << ' ' << mul << endl;
		if(n % 2 == 0) {
			for(int i(1); i <= n / 2; i++) {
				res.push_back(mul);
			}
			n /= 2;
			mul *= 2;
		}else {
			if(n == 1) {
				res.push_back(mul);
				//cout << "!" << res.size() << endl;
				break;
			}else if(n == 3) {
				res.push_back(mul);
				res.push_back(mul);
				res.push_back(mul * 3);
				break;
			}else {
				for(int i(1); i <= n / 2 + 1; i++) {
					res.push_back(mul);
				}
				n /= 2;
				mul *= 2;
			}
		}
	}
	for(int i(1); i <= res.size(); i++) printf("%d%c", res[i - 1], i == res.size() ? '\n' : ' ');
}