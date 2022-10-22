#include <bits/stdc++.h>
using namespace std;

string suit = "CDHS";
string ranks = "23456789TJQKA";

set <string> all;
string a[20][20];
int px1, px2, py1, py2;
int can[20][20];
int n, m;

bool check(string s, string t){
	if (s != "") a[px1][py1] = s;
	if (t != "") a[px2][py2] = t;
	memset(can, 0, sizeof(can));
	for (int x = 0; x <= n - 3; x++){
		for (int y = 0; y <= m - 3; y++){
			int flag = 1;
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					flag &= a[x + i][y + j][1] == a[x][y][1];
				}
			}
			if (flag) can[x][y] = 1;
			set <char> s;
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					s.insert(a[x + i][y + j][0]);
				}
			}
			if (s.size() == 9) can[x][y] = 1;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k < n; k++){
				for (int l = 0; l < m; l++){
					if (!can[i][j] || !can[k][l]) continue;
					if (k - i >= 3 || l - j >= 3){
						printf("Solution exists.\n");
						if (px1 == -1 && px2 == -1) printf("There are no jokers.\n");
						else if (px1 == -1) printf("Replace J2 with %s.\n", t.c_str());
						else if (px2 == -1) printf("Replace J1 with %s.\n", s.c_str());
						else printf("Replace J1 with %s and J2 with %s.\n", s.c_str(), t.c_str());
						printf("Put the first square to (%d, %d).\n", i + 1, j + 1);
						printf("Put the second square to (%d, %d).\n", k + 1, l + 1);
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int main(){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 13; j++){
			string tmp; tmp += ranks[j], tmp += suit[i];
			all.insert(tmp);
		}
	}
	cin >> n >> m;
	px1 = px2 = py1 = py2 = -1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			if (a[i][j] == "J1") px1 = i, py1 = j;
			else if (a[i][j] == "J2") px2 = i, py2 = j;
			else all.erase(a[i][j]);
		}
	}
	if (px1 == -1 && px2 == -1){
		if (!check("", "")) printf("No solution.\n");
		return 0;
	}
	if (px1 == -1){
		for (set <string> :: iterator it = all.begin(); it != all.end(); it++){
			if (check("", *it)) return 0;
		}
		printf("No solution.\n");
		return 0;
	}
	if (px2 == -1){
		for (auto it = all.begin(); it != all.end(); it++){
			if (check(*it, "")) return 0;
		}
		printf("No solution.\n");
		return 0;
	}
	for (auto it1 = all.begin(); it1 != all.end(); it1++){
		for (auto it2 = all.begin(); it2 != all.end(); it2++){
			if (it1 == it2) continue;
			if (check(*it1, *it2)) return 0;
		}
	}
	printf("No solution.\n");
	return 0;
}