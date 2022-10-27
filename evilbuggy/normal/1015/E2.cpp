#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;

char a[maxN][maxN];
int l[maxN][maxN], r[maxN][maxN];
int u[maxN][maxN], d[maxN][maxN];
int row[maxN][maxN], col[maxN][maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i <= n + 1; i++){
		for(int j = 0; j <= m + 1; j++){
			if(1 <= i && i <= n && 1 <= j && j <= m){
				cin >> a[i][j];
			}else{
				a[i][j] = '.';
			}
		}
	}
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	memset(u, 0, sizeof(u));
	memset(d, 0, sizeof(d));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == '*'){
				l[i][j] = r[i][j] = u[i][j] = d[i][j] = 1;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == '*'){
				l[i][j] += l[i][j - 1];
				u[i][j] += u[i - 1][j];
			}
		}
	}
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			if(a[i][j] == '*'){
				r[i][j] += r[i][j + 1];
				d[i][j] += d[i + 1][j];
			}
		}
	}
	vector<array<int, 3> > vec;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int len = min({l[i][j], r[i][j], u[i][j], d[i][j]});
			if(len > 1){
				vec.push_back({i, j, len - 1});
				row[i][j - len + 1]++; row[i][j + len]--;
				col[i - len + 1][j]++; col[i + len][j]--;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			row[i][j] += row[i][j - 1];
			col[i][j] += col[i - 1][j];
			char ch = '.';
			if(row[i][j] > 0 || col[i][j] > 0){
				ch = '*';
			}
			if(ch != a[i][j]){
				cout << -1 << '\n';
				exit(0);
			}
		}
	}
	cout << vec.size() << '\n';
	for(auto x : vec){
		cout << x[0] << " " << x[1] << " " << x[2] << '\n';
	}

	return 0;
}