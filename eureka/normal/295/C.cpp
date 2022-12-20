#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <complex>
using namespace std;
typedef long long lld;
//typedef __int64 lld;
typedef unsigned long long llu;
const int intmax=0x3f3f3f3f;//NOTES:intmax
const lld lldmax=0x3f3f3f3f3f3f3f3fll;//NOTES:lldmax
double eps=1e-8;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclid(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclid(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclid(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline int dblcmp(T a,const T b){a-=b; return a>eps?1:(a<-eps?-1:0);}//NOTES:doublecmp
template<class T> inline int sgn(T a){return a>eps?1:(a<-eps?-1:0);}
#define mem(a, val) memset(a, val, sizeof(a))//memset(
#define shl(i)      ((lld)1 << (i))
#define MP make_pair
#define PB push_back
#define ff(i, n) for(int i=0; i<n; ++i)

const int N = 52;
lld dp[N][N][N][N][2];
bool vis[N][N][N][N] = {0};
lld comb[N][N];
int m;
const lld P = 1000000007;
void dfs(int l1, int l2, int r1, int r2){
	if (vis[l1][l2][r1][r2]) return;
	vis[l1][l2][r1][r2] = true;
	lld *p, *q, tmp;
	p = dp[l1][l2][r1][r2];
	p[0] = intmax;
	p[1] = 0;
	if (l1 + l2 * 2 <= m){
		p[0] = 1;
		p[1] = 1;
		return;
	}
	for (int i=0; i<=l1; ++i){
		if (i > m) break;
		for (int j=0; j<=l2; ++j){
			if (i + j == 0) continue;
			if (i + 2*j > m) break;
			for (int ii=0; ii<=r1+i; ++ii){
				if (ii >= i + 2*j) break;
				for (int jj=0; jj<=r2+j; ++jj){
					if (ii + 2*jj >= i + 2*j) break;
					if (ii + jj == 0) continue;
					dfs(l1-i+ii, l2-j+jj, r1+i-ii, r2+j-jj);
					q = dp[l1-i+ii][l2-j+jj][r1+i-ii][r2+j-jj];
					tmp = comb[l1][i] * comb[l2][j] % P * comb[r1+i][ii] % P * comb[r2+j][jj] % P * q[1] % P;
				if (q[0] < p[0]){
					p[0] = q[0];
					p[1] = tmp;
				}else if (q[0] == p[0]){
					p[1] = (p[1] + tmp) % P;
				}
				}
			}
		}
	}
	p[0] += 2;
	//printf("%d %d %d %d %I64d %I64d\n", l1, l2, r1, r2, p[0], p[1]);
}

int main(){
	for (int i=0; i<N; ++i){
		comb[i][0] = comb[i][i] = 1;
		for (int j=1; j<i; ++j){
			comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % P;
		}
	}
	int n, k;
	int c1=0, c2=0;
	cin >> n >> k;
	m = k / 50;
	for (int i=0; i<n; ++i){
		cin >> k;
		if (k == 50) c1 ++;
		else c2 ++;
	}
	dfs(c1, c2, 0, 0);
	lld *p = dp[c1][c2][0][0];
	if (p[1] == 0 || p[0] >= intmax ){
		puts("-1");
		puts("0");
	}else {
		cout << p[0] << endl;
		cout << p[1] << endl;
	}
	return 0;
}