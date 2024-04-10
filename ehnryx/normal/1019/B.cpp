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

const int N = 1e5+1;
int val[N];

void init() {
	memset(val, INF, sizeof val);
}

int query(int n) {
	cout << "? " << n << endl;
	int x;
	cin >> x;
	return x;
}

void answer(int n) {
	cout << "! " << n << endl;
}

bool intersect(int a, int b, int c, int d) {
	if (val[a] < val[b]){ 
		if (val[c] < val[d]) {
			return (val[a] < val[c] && val[c] < val[b] && val[a] < val[d] && val[d] < val[b])
				|| (val[c] < val[a] && val[a] < val[d] && val[c] < val[b] && val[b] < val[d]);
		}
		else {
			return val[a] < val[c] && val[b] > val[d];
		}
	}
	else {
		if (val[c] > val[d]) {
			return (val[a] > val[c] && val[c] > val[b] && val[a] > val[d] && val[d] > val[b])
				|| (val[c] > val[a] && val[a] > val[d] && val[c] > val[b] && val[b] > val[d]);
		}
		else {
			return val[a] > val[c] && val[b] < val[d];
		}
	}
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

	init();

	int n;
	cin >> n;
	int half = n/2;

	val[1] = query(1);
	val[1+half] = query(1+half);
	if (val[1] == val[1+half]) {
		answer(1);
		return 0;
	}

	int left, right, mid;
	left = 2;
	right = half;
	while (left <= right) {
		mid = (left+right)/2;
		val[mid] = query(mid);
		val[mid+half] = query(mid+half);
		if (val[mid] == val[mid+half]) {
			answer(mid);
			return 0;
		}

		if (intersect(left-1, mid, left-1+half, mid+half)) {
			right = mid-1;
		} else {
			left = mid+1;
		}
	}

	answer(-1);

	return 0;
}