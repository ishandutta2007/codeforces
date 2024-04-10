#include <bits/stdc++.h>
using namespace std;

const int maxN = 105;

int s[maxN][maxN];
vector<array<int, 6> > ans;

inline void apply(int x1, int y1, int x2, int y2, int x3, int y3){
	s[x1][y1] ^= 1;
	s[x2][y2] ^= 1;
	s[x3][y3] ^= 1;
	ans.push_back({x1, y1, x2, y2, x3, y3});
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char ch; cin >> ch; s[i][j] = ch - '0';
		}
	}
	ans.clear();
	for(int i = 0; i < n - 2; i++){
		for(int j = 0; j < m; j += 2){
			if(j + 1 < m){
				if(s[i][j] && s[i][j + 1]){
					apply(i, j, i, j + 1, i + 1, j);
				}else if(s[i][j] && !s[i][j + 1]){
					apply(i, j, i + 1, j, i + 1, j + 1);
				}else if(!s[i][j] && s[i][j + 1]){
					apply(i, j + 1, i + 1, j, i + 1, j + 1);
				}
			}else{
				if(s[i][j]){
					apply(i, j, i + 1, j, i + 1, j - 1);
				}
			}
		}
	}
	for(int j = 0; j + 2 < m; j++){
		if(s[n - 2][j] && s[n - 1][j]){
			apply(n - 2, j, n - 1, j, n - 1, j + 1);
		}else if(s[n - 2][j] && !s[n - 1][j]){
			apply(n - 2, j, n - 1, j + 1, n - 2, j + 1);
		}else if(!s[n - 2][j] && s[n - 1][j]){
			apply(n - 1, j, n - 1, j + 1, n - 2, j + 1);
		}
	}
	int x1 = n - 2, x2 = n - 1;
	int y1 = m - 2, y2 = m - 1;
	if(s[x1][y1] + s[x1][y2] + s[x2][y1] + s[x2][y2] == 4){
		apply(x1, y1, x1, y2, x2, y1);
	}
	if(s[x1][y1] + s[x1][y2] + s[x2][y1] + s[x2][y2] == 1){
		if(s[x1][y1] + s[x1][y2] + s[x2][y2] == 1)apply(x1, y1, x1, y2, x2, y2);
		else apply(x2, y1, x1, y2, x2, y2);
	}
	if(s[x1][y1] + s[x1][y2] + s[x2][y1] + s[x2][y2] == 2){
		vector<int> v;
		for(int x : {x1, x2}){
			for(int y : {y1, y2}){
				if(!s[x][y])v.emplace_back(x);
				if(!s[x][y])v.emplace_back(y);
			}
		}
		for(int x : {x1, x2}){
			for(int y : {y1, y2}){
				if(s[x][y] && v.size() < 6)v.emplace_back(x);
				if(s[x][y] && v.size() < 6)v.emplace_back(y);
			}
		}
		apply(v[0], v[1], v[2], v[3], v[4], v[5]);
	}
	if(s[x1][y1] + s[x1][y2] + s[x2][y1] + s[x2][y2] == 3){
		vector<int> v;
		for(int x : {x1, x2}){
			for(int y : {y1, y2}){
				if(s[x][y])v.emplace_back(x);
				if(s[x][y])v.emplace_back(y);
			}
		}
		apply(v[0], v[1], v[2], v[3], v[4], v[5]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			assert(s[i][j] == 0);
		}
	}
	cout << (int)ans.size() << '\n';
	for(auto x : ans){
		for(int i = 0; i < 6; i++){
			cout << x[i] + 1 << " ";
		}
		cout << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}