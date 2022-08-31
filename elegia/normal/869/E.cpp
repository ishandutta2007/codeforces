#include <ctime>
#include <cstdio>
#include <cstdlib>

#include <map>

using namespace std;

typedef long long ll;

const int N = 2510;

int n, m, q, vc;
ll fw[N][N];

map<pair<pair<int, int>, pair<int, int> >, ll> hsh;

int lowBit(int k);
void change(int x, int y, ll v);
ll query(int x, int y);

int main() {
	srand(time(NULL));
	scanf("%d%d%d", &n, &m, &q);
	while (q--) {
		int opt, x1, y1, x2, y2;
		scanf("%d%d%d%d%d", &opt, &x1, &y1, &x2, &y2);
		if (opt == 1 || opt == 2) {
			ll v = (rand() << 16) | rand() | ((ll)rand() << 32) | ((ll)rand() << 48);
			if (opt == 1)
				hsh[make_pair(make_pair(x1, y1), make_pair(x2, y2))] = v;
			else
				v = hsh[make_pair(make_pair(x1, y1), make_pair(x2, y2))];
			change(x1, y1, v);
			change(x1, y2 + 1, v);
			change(x2 + 1, y1, v);
			change(x2 + 1, y2 + 1, v);
		} else {
			puts(query(x1, y1) == query(x2, y2) ? "Yes" : "No");
		}
	}
	return 0;
}

int lowBit(int k) {
	return k & -k;
}

void change(int x, int y, ll v) {
	for (int i = x; i <= n; i += lowBit(i))
		for (int j = y; j <= m; j += lowBit(j))
			fw[i][j] ^= v;
}

ll query(int x, int y) {
	int ret = 0;
	for (int i = x; i; i -= lowBit(i))
		for (int j = y; j; j -= lowBit(j))
			ret ^= fw[i][j];
	return ret;
}