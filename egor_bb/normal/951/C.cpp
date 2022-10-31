#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define fst first
#define sc second
#define snd second
#define sz(X) (int)(X).size()
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornr(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for(int i = int(a); i < int(b); i++)
#define all(X) X.begin(), X.end()

typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef vector<int> vi;

const int N = 505;

int n;
	
bool ask(int r1, int c1, int r2, int c2) {
	cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
	string s;
	cin >> s;
	return s == "YES";
}

bool ask1(int r, int c) {
	return ask(1, 1, r, c);
}

bool ask2(int r, int c) {
	return ask(r, c, n, n);
}

bool ok[N][N];

vector<char> ans;

bool in(int r, int c) {
	return 1 <= r && r <= n && 1 <= c && c <= n;
}

void dfs(int r, int c) {
	if (r == n && c == n) return;
	if (in(r + 1, c) && ok[r + 1][c]) {
		ans.pb('D');
		dfs(r + 1, c);
	} else {
		ans.pb('R');
		dfs(r, c + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	ok[1][1] = 1;
	ok[n][n] = 1;
	int r = n, c = n;
	while((r - 1) + (c - 1) >= n) {
		bool can = ask1(r, c - 1);
		if (can) {
			ok[r][c - 1] = 1;
			c--;
		} else {
			ok[r - 1][c] = 1;
			r--;
		}
	}
	r = 1, c = 1;
	while((n - r) + (n - c) >= n) {
		bool can = ask2(r + 1, c);
		if (can) {
			ok[r + 1][c] = 1;
			r++;
		} else {
			ok[r][c + 1] = 1;
			c++;
		}
	}
	dfs(1, 1);
	cout << "! ";
	for (char x : ans) cout << x;
	cout << endl;
	return 0;
}