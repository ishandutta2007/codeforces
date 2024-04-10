#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 505;
const int MOD = 1E6;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int maxRow[SIZE];
int qnt[SIZE][SIZE];
int bestTotal = 0;

int n, m, q;

void updateMax(int row) {
	int best = 0;
	int cur = 0;
	for(int i = 1; i <= m; i++) {
		if(qnt[row][i] == 0) cur = 0;
		else best = max(best, ++cur);
	}
	maxRow[row] = best;
}

void updateAll() {
	bestTotal = 0;
	for(int i = 1; i <= n; i++) {
		bestTotal = max(bestTotal, maxRow[i]);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &qnt[i][j]);
		}
		updateMax(i);
	}
	updateAll();
	for(int que = 0; que < q; que++) {
		int i, j;
		scanf("%d %d", &i, &j);
		qnt[i][j] = 1 - qnt[i][j];
		updateMax(i);
		updateAll();
		printf("%d\n", bestTotal);
	}
	return 0;
}