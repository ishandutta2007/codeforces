#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

vector<int> v = { 4, 8, 15, 16, 23, 42 };

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int m12, m34, m15, m36;

	cout << "? " << 1 << " " << 2 << endl;
	cin >> m12;
	cout << "? " << 3 << " " << 4 << endl;
	cin >> m34;
	cout << "? " << 1 << " " << 5 << endl;
	cin >> m15;
	cout << "? " << 3 << " " << 6 << endl;
	cin >> m36;

	const int n = 6;
	int ans[n+1];
	for (int i=0; i<n; i++) {
		int two, five;
		two = five = 0;
		for (int j=0; j<n; j++) {
			if (i==j) continue;
			if (v[i]*v[j] == m12) two = v[j];
			if (v[i]*v[j] == m15) five = v[j];
		}
		if (two && five) {
			ans[1] = v[i];
			ans[2] = two;
			ans[5] = five;
		}
	}

	for (int i=0; i<n; i++) {
		int four, six;
		four = six = 0;
		for (int j=0; j<n; j++) {
			if (i==j) continue;
			if (v[i]*v[j] == m34) four = v[j];
			if (v[i]*v[j] == m36) six = v[j];
		}
		if (four && six) {
			ans[3] = v[i];
			ans[4] = four;
			ans[6] = six;
		}
	}

	cout << "!";
	for (int i=1; i<=n; i++) {
		cout << " " << ans[i];
	}
	cout << endl;

	return 0;
}