//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {return x < y ? x = y, true : false;}
template <typename T> bool chkmin(T &x, T y) {return x > y ? x = y, true : false;}

using namespace std;

int n, b[maxn][maxn];
ll ksm(ll a, ll b) {
	if (!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if (b & 1) ns = ns * a % mod;
	return ns;
}

void solve(int x) {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			if (b[i][j]) continue;
			if ((i + j) % 2 == 0) {
				if (x != 1) {
					printf("1 %d %d\n", i + 1, j + 1);
					b[i][j] = 1;
					fflush(stdout);
					return;
				}
			} else {
				if (x != 2) {
					printf("2 %d %d\n", i + 1, j + 1);
					b[i][j] = 2;
					fflush(stdout);
					return;
				}
			}
		}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			if (b[i][j]) continue;
			printf("3 %d %d\n", i + 1, j + 1);
			b[i][j] = 3;
			fflush(stdout);
			return;
		}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n * n; i++) {
		int x;
		scanf("%d", &x);
		solve(x);
	}
}