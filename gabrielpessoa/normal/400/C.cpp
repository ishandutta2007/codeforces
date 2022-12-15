#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int SIZE = 100005;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main() {
	int n, m, x, y, z, p;
	scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &z, &p);
	x %= 4;
	y %= 2;
	z %= 4;
	for(int c = 0; c < p; c++) {
		int i, j;
		int n1 = n;
		int m1 = m;
		scanf("%d %d", &i, &j);
		for(int x1 = 0; x1 < x; x1++) {
			swap(i, j);
			swap(n1, m1);
			j = m1 + 1 - j;
			//printf("%d %d\n", i, j);
		}
		if(y) {
			j = m1 + 1 - j;
			//printf("%d %d\n", i, j);
		}
		for(int z1 = 0; z1 < z; z1++) {
			swap(i, j);
			swap(n1, m1);
			i = n1 + 1 - i;
			//printf("%d %d\n", i, j);
		}
		printf("%d %d\n", i, j);
	}
	return 0;
}