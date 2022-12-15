#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 1005;
const int MOD = 1E9+9;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 1e-3;
const int INF = 0x3f3f3f3f;
const double INFF = 1e100;

int main() {
	int x, y;
	cin >> x >> y;
	if(y == 1 && x == 0) {
		cout << "Yes\n";
		return 0;
	}
	y--;
	x -= y;
	if(y > 0 && x >= 0 && x % 2 == 0) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	return 0;
}