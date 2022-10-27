#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
const int mod = 1000*1000*1000 + 7;

int chk[maxn];
vector<array<int, 2> > pos[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int k; cin >> k;
	memset(chk, 0, sizeof(chk));
	for(int i = 1; i <= k; i++){
		int x; cin >> x;
		int y; cin >> y;
		if(x + y > n + 1){
			x = n + 1 - x;
			y = n + 1 - y;
		}
		if(x < y){
			swap(x, y);
		}
		char ch; cin >> ch;
		if(ch == 'x'){
			pos[x + y].push_back({y, 0});
		}else{
			pos[x + y].push_back({y, 1});
		}
	}
	for(int i = n + 1; i >= 2; i--){
		if(pos[i].empty())continue;
		sort(pos[i].begin(), pos[i].end());
		pos[i].resize(unique(pos[i].begin(), pos[i].end()) - pos[i].begin());

		chk[i] = 1;
		if(pos[i].size() == 1)continue;

		for(int k = 0, j = 1; j < (int)pos[i].size(); k++, j++){
			if(pos[i][j][0] == pos[i][k][0]){
				cout << 0 << '\n';
				exit(0);
			}
			int x1 = i - pos[i][k][0];
			int x2 = i - pos[i][j][0];
			int y1 = i - x1;
			int y2 = i - x2;
			int v1 = pos[i][k][1];
			int v2 = pos[i][j][1];
			int m = min({x1, y1, x2, y2});
			x1 -= m; y1 -= m; x2 -= m; y2 -= m;
			if(y1 == 0){
				pos[x2 + y2].push_back({y2, v1 ^ v2});
			}else{
				pos[x1 + y1].push_back({y1, v1 ^ v2});
			}
		}
	}
	int ans = 1;
	for(int i = n + 1; i >= 2; i--){
		if(!chk[i]){
			ans <<= 1;
			if(ans >= mod)ans -= mod;
		}
	}
	cout << ans << '\n';

	return 0;
}