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
int c[4111], cnt[555555];
char st[99];
bool tabc[555][2];
int tabd[555][2];
int main() {
	tabc['A'][0] = 1; tabc['A'][1] = 1;
	tabc['O'][0] = 1; tabc['O'][1] = 0;
	tabc['X'][0] = 1; tabc['X'][1] = 1;
	tabc['a'][0] = 0; tabc['a'][1] = 1;
	tabc['o'][0] = 1; tabc['o'][1] = 1;
	tabc['x'][0] = 1; tabc['x'][1] = 1;

	tabd['A'][0] = 2; tabd['A'][1] = 0;
	tabd['O'][0] = 0; tabd['O'][1] = 0;
	tabd['X'][0] = 0; tabd['X'][1] = 1;
	tabd['a'][0] = 1; tabd['a'][1] = 1;
	tabd['o'][0] = 1; tabd['o'][1] = 2;
	tabd['x'][0] = 1; tabd['x'][1] = 0;
	int w, n, m;
	w = getInt(); n = getInt(); m = getInt();
//w = 12, n = 30000, m = 50000;
	for(int i(1); i <= n; i++) {
		int x;
		x = getInt();
//x = i & 4095;
		c[x]++;
	}
	for(int i(0); i < (1 << w); i++) {
		for(int j(0); j < (1 << w); j++) {
			int cod = 0;
			for(int k(0); k < w; k++) {
				cod = cod * 3 + (((j >> k) & 1) ? 2 : (i >> k) & 1);
			}
			cnt[cod] += c[i];
		}
	}
	for(int i(0); i < m; i++) {
		scanf("%s", st);
		reverse(st, st + w);
		int ans = 0;
		for(int k(0); k < (1 << w); k++) {
			if(!c[k]) continue;
			int cod = 0, chk = 1;
			for(int j(0); j < w; j++) {
				chk &= tabc[st[j]][(k >> j) & 1];
				if(chk == false) break;
				cod = cod * 3 + tabd[st[j]][(k >> j) & 1];
			}
			if(chk) ans += c[k] * cnt[cod];
		}
		printf("%d\n", ans);
	}
	cerr << clock() << endl;
}