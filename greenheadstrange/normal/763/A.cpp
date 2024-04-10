#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
vi eg[maxn];
int col[maxn];
int fl = 1;
void dfs(int a, int fa, int nc) {
	if (col[a] != nc) fl = 0;
	for (auto v : eg[a]) {
		if (v == fa) continue;
		else {
			dfs(v, a, nc);
		}
	}	
}
bool check(int a) {
//	cout << "CK"<< a << endl;
	fl = 1;
	for (auto v : eg[a]) {
		dfs(v, a, col[v]);
	}
	return fl;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v), eg[v].pb(u);
	}
	for (int i = 1; i <= n; i++)	
		scanf("%d", &col[i]);
	for (int i = 1; i <= n; i++) {
		for (auto v : eg[i]) {
			if (col[v] != col[i]) {
				if (check(v)) {
					cout << "YES" << endl;
					cout << v << endl;
					return 0;
				}
				if (check(i)) {
					cout << "YES" << endl;
					cout << i << endl;
					return 0;
				}	
				cout << "NO" << endl;
				return 0;
			}
		} 

	}
	cout << "YES" << endl;
	cout << 1 << endl;
	return 0;
}