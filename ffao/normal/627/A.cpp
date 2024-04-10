#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, m, b;
long long s,x;
int sb[100];
int xb[100];

long long dp[110][2];
int tam;

long long rec(int idx, int c) {
	if (idx == tam && c == 0) return 1;

	long long &ret = dp[idx][c];

	if (ret == -1) {
		ret = 0;
		if (xb[idx] == 0) {
			if (sb[idx] == c) {
				ret += rec(idx+1, 1);
				ret += rec(idx+1, 0);
			}
		}
		else {
			if (sb[idx] != c) {
				ret += 2 * rec(idx+1, c);
			}
		}
	}

	return ret;
}

int main() {
	memset(dp,-1,sizeof(dp));

	scanf("%lld %lld", &s, &x);
	long long dec = 0;
	if (s == x) dec+=2;

	int xt = 0, st = 0;
	while (x) {
		xb[xt++] = (x&1);
		x >>= 1;
	}
	while (s) {
		sb[st++] = (s&1);
		s >>= 1;
	}

	tam = max(xt, st)+4;

	printf("%lld\n", rec(0, 0) - dec);
}