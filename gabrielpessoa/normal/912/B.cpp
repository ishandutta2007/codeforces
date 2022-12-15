#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;

const int SIZE  = 1 << 8;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int main() {
    ll n, k;
	cin >> n >> k;
	if(k == 1) {
		cout << n << endl;
	} else {
		ll melhor = 2;
		while(melhor <= n) {
			melhor *= 2;
		}
		cout << melhor - 1 << endl;
	}
	return 0;
}