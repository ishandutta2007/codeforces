#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1.0);
const ld eps = 1e-14;
const int INF = 1E9;		
const int MAXN = 100500;

int n, ans;
string cur, cur2;
map<string, int> dp;

int main() {

	cin >> n;
	cur = "polycarp";
	dp[cur] = 1;
	
	forn(i, n) {
		cin >> cur;
		forn(j, cur.size())	
			if ('A' <= cur[j] && cur[j] <= 'Z')
				cur[j] += 'a' - 'A';
		cin >> cur2;
		cin >> cur2;
		forn(j, cur2.size())	
			if ('A' <= cur2[j] && cur2[j] <= 'Z')
				cur2[j] += 'a' - 'A';
		
		dp[cur] = dp[cur2] + 1;
		ans = max(ans, dp[cur]);
	}
	
	cout << ans;
	
	return 0;
}