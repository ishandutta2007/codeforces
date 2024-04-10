#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define fr first
#define sc second
using pi2 = pair<int, int>;

int grp[10][10] = {
	{ 1,  2,  3,  4,  1,  2,  3,  4},
	{ 5,  6,  7,  8,  5,  6,  7,  8},
	{11, 12,  9, 10, 11, 12,  9, 10},
	{15, 16, 13, 14, 15, 16, 13, 14},
	{ 1,  2,  3,  4,  1,  2,  3,  4},
	{ 5,  6,  7,  8,  5,  6,  7,  8},
	{11, 12,  9, 10, 11, 12,  9, 10},
	{15, 16, 13, 14, 15, 16, 13, 14}
};
string mp[10];

void Main(){
	int t; cin >> t;
	while (t--){
		for (int i = 0; i < 8; i++){ cin >> mp[i]; }
		pi2 p1 = {-1, -1}, p2 = {-1, -1};
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				if (mp[i][j] == 'K'){
					if (p1.fr == -1){ p1 = {i, j}; }
					else{ p2 = {i, j}; }
				}
			}
		}
		int g1 = grp[p1.fr][p1.sc], g2 = grp[p2.fr][p2.sc];
		if (g1 != g2){ cout << "NO" << endl; }
		else{ cout << "YES" << endl; }
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