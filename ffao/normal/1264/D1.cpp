#include <string>
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


#include <tuple>

char s[1110000];
int p[2100][2100];
int sf[2100][2100];
const int mod = 998244353;

void solve()
{
    scanf("%s", s);
    int n = strlen(s);

	p[0][0] = 1;
    for (int i = 1; i <= n; i++) {
		for (int t = 0; t <= 2000; t++) {
			if ((s[i-1] == '(' || s[i-1] == '?') && t > 0) p[i][t] = (p[i][t] + p[i-1][t-1]) % mod;
			if (s[i-1] == ')' || s[i-1] == '?') p[i][t] = (p[i][t] + p[i-1][t]) % mod;
		}
    }

	sf[n][0] = 1;
	for (int i = n-1; i >= 0; i--) {
		for (int t = 0; t <= 2000; t++) {
			if ((s[i] == ')' || s[i] == '?') && t > 0) sf[i][t] = (sf[i][t] + sf[i+1][t-1]) % mod;
			if (s[i] == '(' || s[i] == '?') sf[i][t] = (sf[i][t] + sf[i+1][t]) % mod;
		}
	}

	long long ans = 0;
	for (int i = 1; i < n; i++) {
		for (int t = 1; t <= 2000; t++) {
			long long k = (p[i][t] * 1ll * sf[i][t]) % mod;
			//if (k != 0) printf("%d %d %d %d\n", i, t, p[i][t], sf[i][t]);
			k = (k * 1ll * t) % mod;
			ans = (ans + k) % mod;
		}
	}

	printf("%lld\n", ans);
}


int main() {


    solve();
}