#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string mp[60];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++){ cin >> mp[i]; }
		char c1 = '.', c2 = '.';
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				bool flg = ( (i+j) % 2 == 1 );
				char& c = flg ? c1 : c2;
				if (mp[i][j] == 'W'){
					if (c == 'R' || c == 'X'){ c = 'X'; }
					else{ c = 'W'; }
				}
				if (mp[i][j] == 'R'){
					if (c == 'W' || c == 'X'){ c = 'X'; }
					else{ c = 'R'; }
				}
			}
		}
		if (c1 == 'X' || c2 == 'X'){ cout << "NO" << endl; continue; }
		if (c1 == '.' && c2 == '.'){ c1 = 'R'; c2 = 'W'; }
		if (c1 == '.'){ c1 = (int)'R'+'W'-c2; }
		if (c2 == '.'){ c2 = (int)'R'+'W'-c1; }
		if (c1 == c2){ cout << "NO" << endl; continue; }
		cout << "YES" << endl;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if ((i+j) % 2 == 1){ cout << c1; }
				else{ cout << c2; }
			}
			cout << endl;
		}
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}