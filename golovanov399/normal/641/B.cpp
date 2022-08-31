#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt(), m = nxt(), q = nxt();
	vector<vector<int>> a(n, vector<int>(m, 0));
	vector<pair<int, vector<int>>> ar(q);
	for (int i = 0; i < q; i++){
		int t = nxt();
		ar[i].first = t;
		if (t < 3){
			ar[i].second.resize(1);
			ar[i].second[0] = nxt();
		} else {
			ar[i].second.resize(3);
			for (int j = 0; j < 3; j++){
				ar[i].second[j] = nxt();
			}
		}
	}

	reverse(all(ar));
	for (const auto& p : ar){
		if (p.first == 1){
			int r = p.second[0] - 1;
			for (int i = m - 1; i > 0; i--){
				swap(a[r][i], a[r][i - 1]);
			}
		} else if (p.first == 2){
			int c = p.second[0] - 1;
			for (int i = n - 1; i > 0; i--){
				swap(a[i][c], a[i - 1][c]);
			}
		} else {
			a[p.second[0] - 1][p.second[1] - 1] = p.second[2];
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("%d ", a[i][j]);
		}
		puts("");
	}

	return 0;
}