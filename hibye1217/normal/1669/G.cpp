#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;

string mp[60];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++){ cin >> mp[i]; }
		for (int y = n-1; y >= 0; y--){
			for (int x = 0; x < m; x++){
				for (int i = y; i+1 < n; i++){
					if (mp[i][x] == '*' && mp[i+1][x] == '.'){
						swap(mp[i][x], mp[i+1][x]);
					}
					else{ break; }
				}
			}
		}
		for (int i = 0; i < n; i++){ cout << mp[i] << endl; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}