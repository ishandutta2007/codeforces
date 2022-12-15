#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 1E5+5;
const int MOD = 1E6;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int main() {
	int n, k, best = INF;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if(k % x == 0) {
			best = min(best, k / x);
		}
	}
	printf("%d\n", best);
	return 0;
}