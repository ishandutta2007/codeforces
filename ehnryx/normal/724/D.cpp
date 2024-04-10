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

const int M = 26;
int tot[M];

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int m;
	cin >> m;
	string s;
	cin >> s;
	int n = s.size();

	for (char c : s) {
		tot[c-'a']++;
	}

	int last = -1;
	For(c,M) {
		int cur = -1;
		For(i,n) {
			if (s[i]-'a' <= c) {
				if (i-cur > m) {
					break;
				} else {
					cur = i;
				}
			}
		}
		if (n-cur > m) {
			continue;
		} else {
			last = c;
			break;
		}
	}
	assert(last != -1);

	vector<int> idc, idx;
	For(i,n) {
		if (s[i]-'a' == last) {
			idc.push_back(i);
		} else if (s[i]-'a' < last) {
			idx.push_back(i);
		}
	}
	idx.push_back(n);

	function<int(int,int)> solve = [&] (int l, int r) {
		int res = 0;
		int rb = r;
		while (rb-l > m) {
			rb = *lower_bound(idc.begin(), idc.end(), rb-m);
			res++;
		}
		return res;
	};

	int pre = -1;
	int cnt = 0;
	for (int i : idx) {
		cnt += solve(pre, i);
		pre = i;
	}

	for (int i=0; i<last; i++) {
		while (tot[i]--) {
			cout << (char)(i+'a');
		}
	}
	while (cnt--) {
		cout << (char)(last+'a');
	}
	cout << nl;

	return 0;
}