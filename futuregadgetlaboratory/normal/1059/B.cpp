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
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
char a[1111][1111], b[1111][1111];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(1); i <= n; i++) {
		scanf("%s", a[i] + 1);
	}
	memset(b, '.', sizeof(b));
	for(int i(2); i < n; i++) {
		for(int j(2); j < m; j++) {
			bool flag = true;
			for(int d(0); d < 8; d++) {
				if(a[i + dx[d]][j + dy[d]] != '#') {
					flag = false;
				}
			}
			if(flag) {
				for(int d(0); d < 8; d++) {
					b[i + dx[d]][j + dy[d]] = '#';
				}	
			}
		}
	}
	bool flag = true;
	for(int i(1); i <= n; i++) {
		for(int j(1); j <= m; j++) {
			if(a[i][j] != b[i][j]) flag = false;
		}
	}
	printf("%s\n", flag ? "YES" : "NO");
}