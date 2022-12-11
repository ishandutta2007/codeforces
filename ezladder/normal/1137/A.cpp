#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define x first
#define y second

using namespace std;

int n, m;
int a[1002][1002];
int f1[1002][1002];
int f2[1002][1002];
int g1[1002];
int g2[1002];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	for (int i = 0; i < n; i++){
		vector<pair<int, int> > w;
		for (int j = 0; j < m; j++) w.pb(mp(a[i][j], j));
		sort(all(w));
		int dd = 0;
		for (int j = 0; j < w.size(); j++){
			if (j && w[j].x != w[j - 1].x) dd++;
			f1[i][w[j].y] = dd;
		}
		g1[i] = dd;
	}
	for (int j = 0; j < m; j++){
		vector<pair<int, int> > w;
		for (int i = 0; i < n; i++) w.pb(mp(a[i][j], i));
		sort(all(w));
		int dd = 0;
		for (int i = 0; i < w.size(); i++){
			if (i && w[i].x != w[i - 1].x) dd++;
			f2[w[i].y][j] = dd;
		}
		g2[j] = dd;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int t1 = f1[i][j];
			int t2 = f2[i][j];
			int s1 = g1[i] - t1;
			int s2 = g2[j] - t2;
			//cout << t1 << ' ' << t2 << ' ' << s1 << ' ' << s2;
			//exit(0);
			cout << max(t1, t2) + 1 + max(s1, s2) << ' ';
		}
		cout << "\n";
	}
}