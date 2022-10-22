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

vector<int> idx[26];
int cnt[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	string s;
	cin >> s;

	For(i,26) {
		idx[i].push_back(0);
	}
	For(i,n) {
		idx[s[i]-'a'].push_back(i+1);
	}

	int m;
	cin >> m;
	while (m--) {
		string t;
		cin >> t;
		memset(cnt,0,sizeof cnt);
		for (char c : t) {
			cnt[c-'a']++;
		}
		int ans = 0;
		For(i,26) {
			ans = max(ans, idx[i][cnt[i]]);
		}
		cout << ans << nl;
	}

	return 0;
}