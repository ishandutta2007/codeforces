#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int SIZE  = 30005;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int main() {
	int n, m;
	cin >> n >> m;
	if(n <= 30) {
		cout << m % (1 << n) << endl;
	} else {
		cout << m << endl;
	}
	return 0;
}