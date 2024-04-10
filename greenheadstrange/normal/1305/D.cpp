#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int d[maxn];
vi eg[maxn];
int fl[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		eg[x].pb(y), eg[y].pb(x);
		d[x]++, d[y]++; 
	}
	for (int i = 1; i <= n / 2; i++) {
		vi cur;
		for (int j = 1; j <= n; j++) 			
			if (d[j] == 1) cur.pb(j);
		if (cur.size() < 2) break;
		int u = cur[0], v = cur[1];
		cout << "? " << u << ' ' << v << endl;
		fflush(stdout);
		int w;
		cin >> w;
		if (w == u) {
			cout << "! " << u << endl;
			fflush(stdout);
			return 0;
		}
		if (w == v) {
			cout << "! " << v << endl;
			fflush(stdout);
			return 0;
		}
		fl[u] = fl[v] = 0;
		d[u] = d[v] = -1;
		for (auto s : eg[u]) d[s]--;
		for (auto s : eg[v]) d[s]--;
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] >= 0) {
			cout << "! " << i << endl;
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}