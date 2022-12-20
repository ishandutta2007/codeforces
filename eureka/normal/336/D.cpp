#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<iostream>
#include<cmath>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back

const int N = 10;
const int L = 210000;
typedef long long lld;
int dp[N][N][2];

template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclid(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclid(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclid(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(

template<class T> T modDivide(T a, T b, T p){
	T x, y, g;
	g = euclid(b, p, x, y);
	if(a%g) return -1;
	return a/g*checkmod(x, p)%p;
}
lld fac[L], inv[L];
lld P = 1000000007;
lld comb(lld n, lld m){
	return fac[n+m] * inv[n] % P * inv[m] % P;
}
lld cal[L];
int main(){
	for (int i=0; i<L; ++i){
		if (i == 0){
			fac[i] = 1;
		}else {
			fac[i] = fac[i-1] * i % P;
		}
		inv[i] = modDivide(1LL, fac[i], P);
	}

	lld n, m, k;
	cin >> n >> m >> k;
	if (m == 0){
		int ans = 1 - n % 2;
		if (ans == k) puts("1");
		else puts("0");
		return 0;
	}
	if (m == 1) cal[0] = 1;
	else cal[0] = 0;
	for (int i=1; i<=n; ++i){
		cal[i] = checkmod(comb(i-1, m) - cal[i-1], P);
	}
	if (k == 1){
		cout << cal[n] << endl;
	}else {
		cout << checkmod(comb(n,m) - cal[n], P) << endl;
	}

	//cout << dp[n][m][k] << endl;
	return 0;
}