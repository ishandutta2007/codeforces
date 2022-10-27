#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;
char a[maxN][maxN], b[maxN][maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			b[i][j] = '.';
		}
	}
	for(int i = 1; i + 1 < n; i++){
		for(int j = 1; j + 1 < m; j++){
			bool flg = true;
			for(int dx : {-1, 0, +1}){
				for(int dy : {-1, 0, +1}){
					if(dx == 0 && dy == 0)continue;
					if(a[i + dx][j + dy] == '.'){
						flg = false;
					}
				}
			}
			if(!flg)continue;
			for(int dx : {-1, 0, +1}){
				for(int dy : {-1, 0, +1}){
					if(dx == 0 && dy == 0)continue;
					b[i + dx][j + dy] = '#';
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != b[i][j]){
				cout << "NO" << '\n';
				exit(0);
			}
		}
	}
	cout << "YES" << '\n';

	return 0;
}