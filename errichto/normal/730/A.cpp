#include <bits/stdc++.h>
using namespace std;
const int nax = 105;
int t[nax];
bool ta[nax];
bool all_eq(int n) {
	for(int i = 0; i < n; ++i) if(t[0] != t[i]) return false;
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &t[i]);
	vector<vector<int>> w;
	while(!all_eq(n)) {
		//puts("a");
		int big = 0;
		for(int i = 0; i < n; ++i) big = max(big, t[i]);
		int cnt = 0;
		for(int i = 0; i < n; ++i) cnt += (big == t[i]);
		if(cnt == 3) {
			vector<int> row;
			for(int i = 0; i < n; ++i) if(big == t[i]) row.push_back(i);
			w.push_back(row);
		}
		else {
			vector<int> row;
			for(int i = 0; i < n; ++i) if(big == t[i]) {
				row.push_back(i);
				break;
			}
			big = 0;
			for(int i = 0; i < n; ++i) if(i != row[0])
				big = max(big, t[i]);
			for(int i = 0; i < n; ++i) if(i != row[0] && t[i] == big) {
				row.push_back(i);
				break;
			}
			w.push_back(row);
		}
		for(int i : w.back()) t[i] = max(0, t[i] - 1);
	}
	printf("%d\n", t[0]);
	printf("%d\n", (int) w.size());
	for(vector<int> row : w) {
		for(int i : row) ta[i] = true;
		for(int i = 0; i < n; ++i) printf("%d", (int) ta[i]);
		puts("");
		for(int i : row) ta[i] = false;
	}
}