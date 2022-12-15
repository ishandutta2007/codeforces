#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 1E5+5;
const int MOD = 1E9+9;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 1e-3;
const int INF = 0x3f3f3f3f;
const double INFF = 1e100;

char s[SIZE];
int main() {
	bool up;
	int n;
	scanf("%d", &n);
	int total = 0;
	scanf("%s", s);
	up = s[0] == 'U';
	int x = 0, y = 0;
	for(int i = 0; i < n; i++) {
		if(x == y && ((s[i] == 'U') != up)) {
			total++;
			up = !up;
		}
		if(s[i] == 'U') {
			y++;
		} else {
			x++;
		}
	}
	printf("%d\n", total);
	return 0;
}