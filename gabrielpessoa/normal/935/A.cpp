#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 55;
const int MOD = 1E9+9;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 1e-3;
const int INF = 0x3f3f3f3f;
const double INFF = 1e100;


int main() {
	int n;
	cin >> n;
	int t = 0;
	for(int i = 1; i < n; i++) {
		if((n - i) % i == 0) t++;
	}
	cout << t << '\n';
	return 0;
}