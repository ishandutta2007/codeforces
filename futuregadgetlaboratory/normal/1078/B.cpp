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
int a[111];
bool dp[103][10011][103];
bool pd[103][10011][103];

int main() {
	int n;
	scanf("%d", &n);
	set<int> st;
	for(int i(1); i <= n; i++) {
		scanf("%d", &a[i]);
		st.insert(a[i]);
	}
	sort(a + 1, a + 1 + n);
	int ans = (st.size() <= 2 ? n : 0);
	dp[0][0][0] = 1;
	int mx = 0;
	for(int i(1); i <= n; i++) {
		for(int j(mx); j >= 0; j--) {
			for(int k(0); k <= i - 1; k++) {
				dp[i][j + a[i]][k + 1] |= dp[i - 1][j][k];
				dp[i][j][k] |= dp[i - 1][j][k];
			}
		}
		mx += a[i];
	}
	
	pd[n + 1][0][0] = 1;
	mx = 0;
	for(int i(n); i >= 1; i--) {
		for(int j(mx); j >= 0; j--) {
			for(int k(0); k <= n - i; k++) {
				pd[i][j + a[i]][k + 1] |= pd[i + 1][j][k];
				pd[i][j][k] |= pd[i + 1][j][k];
			}
		}
		mx += a[i];
	}
	
	for(int i(1), j; i <= n; i = j) {
		for(j = i; j <= n && a[j] == a[i]; j++);
		for(int k(i); k < j; k++) {
			bool flag = false;
			for(int l(0); l <= (k - i + 1) && !flag; l++) {
				for(int m(0); m <= a[i] * (k - i + 1) && !flag; m++) {
					flag |= dp[k - 1][m][l] && pd[j][a[i] * (k - i + 1) - m][k - i + 1 - l];
				}
			}
			if(!flag) ans = max(ans, k - i + 1);
		}
	}
	cout << ans << endl;
}