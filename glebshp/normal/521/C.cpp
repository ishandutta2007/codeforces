#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 200 * 1000 + 100;
const long long mdl = 1000 * 1000 * 1000 + 7;

int n, k;
char buf[size];
int val[size];
long long fact[size];

long long fpwr(long long a, long long b) {
	if (b == 0)
		return 1ll;
	long long d = fpwr(a, b / 2);
	d = (d * d) % mdl;
	if (b & 1)
		d = (d * a) % mdl;

	return d;
}

long long back(long long a) {
	return fpwr(a, mdl - 2);
}

long long cnk(long long n, long long k) {
	return (((fact[n] * back(fact[k])) % mdl) * back(fact[n - k])) % mdl;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < size; i++)
		fact[i] = (fact[i - 1] * i) % mdl;

//    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);
    scanf("%s", buf);
    for (int i = 0; i < n; i++)
    	val[i] = (buf[i] - '0');

    long long cur = 0ll;
    long long ans = 0ll;
    for (int i = n - 1; i >= 0; i--) {
    	if (i >= k) {
    		ans = (ans + ((val[i] * fpwr(10ll, n - i - 1)) % mdl) * cnk(i, k)) % mdl;
    	}
    	
    	if (k > 0 && i >= k - 1 && i + 1 < n) {
    		cur = (cur + fpwr(10ll, n - i - 2) * cnk(i, k - 1)) % mdl;
    	}

    	ans = (ans + cur * 1ll * val[i]) % mdl;
    }

    cout << ans << endl;

    return 0;
}