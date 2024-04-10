#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define x first
#define y second
#define itn int

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 111;
string a[N][N];

void solve(){
	cin.sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	int B[3] = {n - 1, m - 1, k - 1};
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int ij = 0; ij < k; ij++){
				if (a[i][j][ij] == '0')
					continue;
				bool ok = true;
				for (int x = 0; x < 3 && ok; x++){
					for (int y = 0; y < 3 && ok; y++){
						int X[3] = {i, j, ij}, Y[3] = {i, j, ij};
						X[x]--;
						Y[y]++;
						if (X[x] < 0 || Y[y] > B[y])
							continue;
						if (a[X[0]][X[1]][X[2]] == '0' || a[Y[0]][Y[1]][Y[2]] == '0')
							continue;
						if (x == y){
							ok = false;
						} else {
							X[y]++;
							if (a[X[0]][X[1]][X[2]] == '0')
								ok = false;
						}
					}
				}
				if (!ok)
					ans++;
			}
		}
	}

	cout << ans << "\n";
}

int main(){

	solve();

	return 0;
}