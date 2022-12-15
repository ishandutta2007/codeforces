#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 2E5+5;
const int MOD = 1E6;
const int DELTA = 1E5+2;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int arr[SIZE];

int main() {
	int n;
	ll m;
	cin >> n >> m;
	int menorPrimo = 100003;
	int lastEdge = menorPrimo - n + 2;
	printf("%d %d\n", menorPrimo, menorPrimo);
	for(int i = 1; i < n - 1; i++) {
		printf("%d %d %d\n", i, i + 1, 1);
	}
	printf("%d %d %d\n", n - 1, n, lastEdge);
	m -= n - 1;
	for(int i = 1; m; i++) {
		for(int j = i + 2; j <= n && m; j++) {
			printf("%d %d %d\n", i, j, menorPrimo+1);
			m--;
		}
	}
	return 0;
}