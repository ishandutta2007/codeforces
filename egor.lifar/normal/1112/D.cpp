#include <bits/stdc++.h>

using namespace std;
template<class T1, class T2> inline void chkmin(T1 &x, T2 const &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, T2 const &y) {if (x < y) x = y;}
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define left left228
#define right right228
const int MAXN  = 5028;
const int P = 424243;
const int Mod = 1000000009;

int n, a, b;
int dp[MAXN];
int g[13000000];
int root = 0;
int cur[MAXN]; 
int uk = 0;
int uk1 = 0;
int nxt[13000000];
int kek[13000000];
char cc[13000000];
int lst[13000000];

int find(int i, char c) {
	if (g[i] == 0) {
		return -1;
	}
	int cur = g[i];
	while (cur != -1) {
		if (cc[cur] == c) {
			return kek[cur];
		}
		cur = nxt[cur];
	}
	return -1;
}

int go(int i, char c) {
	int pos = find(i, c);
	if (pos != -1) {
		return pos;
	}
	uk++;
	uk1++;
	nxt[uk1] = -1;
	if (g[i] == 0) {
		g[i] = uk1;

	}  else {
		nxt[lst[i]] = uk1; 
	}
			lst[i] = uk1;
	cc[uk1] = c;
	kek[uk1] = uk;
	return uk;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	cin >> n >> a >> b;
	string s;
	cin >> s;

	for (int i = 0; i <= n; i++) {
		dp[i] = 1e9;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		chkmin(dp[i + 1], dp[i] + a);
		int curs = 0;
		for (int j = i; j < n; j++) {
			curs = find(curs,s[j] - 'a');
			if (curs == -1) {
				break;
			}
			chkmin(dp[j + 1 ], dp[i] + b);
		}
		for (int j = i - 1; j >= 0; j--) {
			cur[j] = go(cur[j], s[i] - 'a');
		}
		cur[i] = go(root, s[i] - 'a');
	}
	cout << dp[n] << '\n';
	return 0;
}