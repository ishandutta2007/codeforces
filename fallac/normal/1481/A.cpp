#include <bits/stdc++.h>
using namespace std;
#define MAX 1010101
#define all(v) v.begin(), v.end()
#define ln '\n'
#define MOD 1000000007
#define INF 210000000000
#define pb push_back
#define abs(x) (((x)>0)?(x):(-(x)))
#define len(x) ((x).second-(x).first)
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T-- > 0) {
		int x, y;
		cin >> x >> y;
		string str;
		cin >> str;
		int i;
		int r, l, u, d;
		r = l = u = d = 0;
		for (i = 0; str[i]; i++) {
			if (str[i] == 'R') r++;
			if (str[i] == 'L') l++;
			if (str[i] == 'U') u++;
			if (str[i] == 'D') d++;
		}
		bool c = true;
		if (!(-l <= x && x <= r)) c = false;
		if (!(-d <= y && y <= u)) c = false;
		if (c) cout << "YES" << ln;
		else cout << "NO" << ln;
	}
	return 0;
}