#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define fr first
#define sc second
using pi2 = pair<int, int>;

int mp[4][4];

void Main(){
	string s; cin >> s;
	vector<pi2> ans;
	for (char c : s){
		pi2 pos = {0, 0}; int pr = 0;
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				if (c == '0' && i%2 == 1){ continue; }
				if (c == '1' && j%2 == 1){ continue; }
				int p = 0;
				if (c == '0'){
					if (mp[i][j] == 0 && mp[i+1][j] == 0){
						if (mp[i][j^1] == 1 && mp[i+1][j^1] == 1){ p = 2; }
						else{ p = 1; }
					}
				}
				if (c == '1'){
					if (mp[i][j] == 0 && mp[i][j+1] == 0){
						if (mp[i^1][j] == 1 && mp[i^1][j+1] == 1){ p = 2; }
						else{ p = 1; }
					}
				}
				if (pr < p){ pr = p; pos = {i, j}; }
			}
		}
		ans.push_back({ pos.fr+1, pos.sc+1 });
		mp[pos.fr][pos.sc] = 1;
		if (c == '0'){ mp[pos.fr+1][pos.sc] = 1; }
		if (c == '1'){ mp[pos.fr][pos.sc+1] = 1; }
		for (int i = 0; i < 4; i++){
			bool flg = 1;
			for (int j = 0; j < 4; j++){
				if (mp[i][j] == 0){ flg = 0; }
			}
			if (flg){
				for (int j = 0; j < 4; j++){ mp[i][j] = 2; }
			}
		}
		for (int j = 0; j < 4; j++){
			bool flg = 1;
			for (int i = 0; i < 4; i++){
				if (mp[i][j] == 0){ flg = 0; }
			}
			if (flg){
				for (int i = 0; i < 4; i++){ mp[i][j] = 2; }
			}
		}
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				if (mp[i][j] == 2){ mp[i][j] = 0; }
			}
		}
	}
	for (pi2 p : ans){ cout << p.fr << ' ' << p.sc << endl; }
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