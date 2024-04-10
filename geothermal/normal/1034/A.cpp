#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <tuple>
#include <vector>
#include <bitset>
#include <stack>
#include <iomanip>
#include <set>
#include <queue>
#include <map>
#include <cctype>

typedef long long ll;
typedef unsigned long long ull;
#define mk make_pair
#define mkt make_tuple
#define fi first
#define se second


using namespace std;
int const N = 20000000;
int const INF = 1e9;
ll const MOD = 998244353;
double EPS = 1;
int cnt[N], a[300020];
bool isNonPrime[N];

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	

	int n; scanf("%d", &n);
	int g = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		if (g == -1) g = a[i];
		else g = gcd(g, a[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		a[i] /= g;
		cnt[a[i]]++;
	}

	isNonPrime[1] = true;
	for (ll i = 2; i < N; i++)
		if (!isNonPrime[i]) {
			int t = 0;
			for (ll j = i; j < N; j += i) {
				isNonPrime[j] = true;
				t += cnt[j];
			}
			ans = max(ans, t);
		}

	if(ans == 0) printf("%d", -1);
	else printf("%d", n - ans);
}