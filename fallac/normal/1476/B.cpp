#include <bits/stdc++.h>
using namespace std;
#define MAX 500010
#define all(v) v.begin(), v.end()
#define ln '\n'
#define MOD 10007
#define INF 2100000000
#define abs(x) ((x)>0?(x):-(x))
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll C;
	cin >> C;
	while (C-- > 0) {
		ll N, K;
		cin >> N >> K;
		ll i;
		ll p, sum;
		cin >> p;
		sum = p;
		ll asum = 0;
		for (i = 2; i <= N; i++) {
			cin >> p;
			if (p * 100 > sum*K) {
				ll a = (p * 100 - sum * K);
				if (a%K == 0) a /= K;
				else a = a / K + 1;
				sum += a;
				asum += a;
			}
			sum += p;
		}
		cout << asum << ln;
	}
	return 0;
}