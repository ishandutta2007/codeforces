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
	int n, pos, l, r;
	scanf("%d %d %d %d", &n, &pos, &l, &r);
	if(l == 1 && r == n) printf("0\n");
	else {
		if(l == 1) {
			if(pos >= r) {
				printf("%d\n", pos - r + 1);
			} else {
				printf("%d\n", r - pos + 1);
			}
		} else if(r == n) {
			if(pos <= l) {
				printf("%d\n", l - pos + 1);
			} else {
				printf("%d\n", pos - l + 1);
			}
		} else {
			if(pos >= r) {
				printf("%d\n", pos - r + 1 + r - l + 1);
			} else if(pos <= l) {
				printf("%d\n", l - pos + 1 + r - l + 1);
			} else {
				printf("%d\n", min(r - l + r - pos + 2, r - l + pos - l + 2));
			}
		}
	}
	return 0;
}