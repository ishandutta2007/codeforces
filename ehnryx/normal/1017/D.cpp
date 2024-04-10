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

const int N = 5e5+1;
const int M = 1<<13;
int freq[1200+1];
int w[13];
int cnt[M];
vector<pii> vals[M]; // val, id
int ans[N];

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m, q;
	cin >> n >> m >> q;

	int v;
	bitset<12> in;
	for (int i = n-1; i >= 0; i--) {
		cin >> w[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> in;
		cnt[in.to_ulong()]++;
	}
	for (int i = 0; i < q; i++) {
		cin >> in >> v;
		vals[in.to_ulong()].push_back(pii(v,i));
	}

	for (int i = 0; i < 1<<12; i++) {
		memset(freq, 0, sizeof freq);
		sort(vals[i].begin(), vals[i].end());
		for (int j = 0; j < 1<<12; j++) {
			int c = i^j;
			int cur = 0;
			for (int k = 0; k < n; k++) {
				if (!(c & 1<<k)) {
					cur += w[k];
				}
			}
			freq[cur] += cnt[j];
		}

		int sum = 0;
		int pos = 0;
		for (int j = 0; j <= 1200; j++) {
			sum += freq[j];
			while (pos < vals[i].size() && vals[i][pos].first <= j) {
				ans[vals[i][pos].second] = sum;
				pos++;
			}
		}
	}

	for (int i = 0; i < q; i++) {
		cout << ans[i] << nl;
	}

	return 0;
}