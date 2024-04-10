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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 111;
const int ALPH = 'z' - 'a' + 1;

int n, used[ALPH];
string s[MAXN]; 
vi g[ALPH];
string ans, st;

bool dfs(int v) {
	used[v] = 1;
	for (auto w: g[v])
		if (used[w] == 1) {
			return 0;
		} else if (used[w] != 2 && !dfs(w))
			return 0;
	st += char('a' + v);
	used[v] = 2;
	return 1;
}

int main() {

	cin >> n;
	forn(i, n) {
		cin >> s[i];	
	}
	
	forn(i, n - 1) {
		int j = 0;
		while (j < min(s[i].size(), s[i + 1].size()) && s[i][j] == s[i + 1][j])
			j++;
		if (j < min(s[i].size(), s[i + 1].size())) {
			g[s[i][j] - 'a'].pb(s[i + 1][j] - 'a');
		} else if (s[i].size() > s[i + 1].size()) {
			cout << "Impossible";
			return 0;
		}
	}
	/*
	forn(i, ALPH)
		for (auto v: g[i])
			cout << char('a' + i) << ' ' << char('a' + v) << '\n';
	*/		
	ans = "";
	forn(i, ALPH)
		if (!used[i]) {
			if (!dfs(i)) {
				cout << "Impossible";
				return 0;
			}						
		}
		
	reverse(all(st));
	cout << st;
	
	assert(st.size() == ALPH);
	
	return 0;
}