#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i,a,b) for(int i = a; i >= b;--i)
#define REP(i, n) FOR(i, 0, n)
#define pii pair<int,int>
#define vi vector < int >
#define sz(a) (int)a.size()
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define y1 jaksflkajsf
#define pii pair<int,int>
#define pli pair<ll,int>
#define ld long double
#define pb push_back
#define mp make_pair

const int INF = 1e9+5;
const int inf = 1e9;
const int N = 4e5;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int MOD = 1e9 + 7;
string s[N];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	REP(i, n) {
		cin >> s[i];
	}
	int ans = 6;
	REP(i, n) {
		REP(j, n) {
			if (i == j)
				continue;
			int cnt = 0;
			REP(k, 6)
				cnt += s[i][k] == s[j][k];
			cnt = (7 - cnt) / 2 - 1;
			if (cnt < 0)
				cnt = 0;
			ans = min(ans, cnt);
		}
	}
	cout << ans << endl;
	return 0;
}