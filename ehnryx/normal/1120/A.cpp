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



//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int m, k, n, s;
	cin >> m >> k >> n >> s;

	int a[m];
	for (int i=0; i<m; i++) {
		cin >> a[i];
	}
	unordered_map<int,int> need;
	for (int i=0; i<s; i++) {
		int v;
		cin >> v;
		need[v]++;
	}

	int len = m - n*k + k;
	cerr << "EXTRA: " << m-n*k << nl;
	unordered_map<int,int> seen;
	for (int i=0; i<len; i++) {
		seen[a[i]]++;
	}

	int cnt = 0;
	for (const pii& it : need) {
		cnt += max(0, it.second - seen[it.first]);
	}

	int left, right;

	{
		if (cnt == 0) {
			left = 0;
			right = len-1;
			goto gulag;
		}

		for (int i=len; i<m; i++) {
			if (--seen[a[i-len]] < need[a[i-len]]) {
				cnt++;
			}
			if (seen[a[i]]++ < need[a[i]]) {
				cnt--;
			}
			if (cnt == 0 && (i+1-len)%k == 0) {
				left = i-len+1;
				right = i;
				goto gulag;
			}
		}

		cout << -1 << nl;

		return 0;
	}

gulag:
	cerr << "WINDOW: " << left+1 << " " << right+1 << nl;
	cout << len-k << nl;
	for (int i=left; i<=right; i++) {
		if (need[a[i]] > 0) need[a[i]]--;
		else if (len > k) {
			len--;
			cout << i+1 << " ";
		}
	}
	cout << nl;

	return 0;
}