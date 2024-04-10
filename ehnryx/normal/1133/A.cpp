#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int dist(int h1, int m1, int h2, int m2) {
	int res = 0;
	while (h1 != h2 || m1 != m2) {
		res++;
		m1++;
		if (m1 == 60) {
			m1 = 0;
			h1++;
			if (h1 == 24) {
				h1 = 0;
			}
		}
	}
	return res;
}

void get(int h1, int m1, int add) {
	for (int i=0; i<add; i++) {
		m1++;
		if (m1 == 60) {
			m1 = 0;
			h1++;
			if (h1 == 24) {
				h1 = 0;
			}
		}
	}
	printf("%02d:%02d\n", h1, m1);
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int h1,m1,h2,m2;
	scanf("%d:%d",&h1,&m1);
	scanf("%d:%d",&h2,&m2);
	get(h1,m1,dist(h1,m1,h2,m2)/2);

	return 0;
}