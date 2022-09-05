#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const int nax = 305;

int type[nax][nax];
vector<int> col[nax];
int dp[nax][nax];
vector<pair<int,int>> odw[nax*nax]; // for each type - vector of cells with this type
bool vis[nax];

int main() {
	int h, w, p;
	scanf("%d%d%d", &h, &w, &p);
	for(int y = 0; y < h; ++y)
		for(int x = 0; x < w; ++x) {
			scanf("%d", &type[x][y]);
			if(type[x][y] == 1) dp[x][y] = x + y;
			else dp[x][y] = inf;
			odw[type[x][y]].push_back(make_pair(x,y));
		}
	for(int v = 1; v <= p - 1; ++v) {
		for(int i = 0; i < max(w, h); ++i) {
			col[i].clear();
			vis[i] = false;
		}
		for(pair<int,int> p : odw[v+1]) {
			int x = p.first;
			int y = p.second;
			col[x].push_back(y); // for each column we need cells with type v+1
		}
		for(pair<int,int> p : odw[v]) vis[p.second] = true;
		for(int y = 0; y < h; ++y) if(vis[y]) { // iterate over rows y with at least one cell of type v
			int best = inf;
			// from left to right
			for(int x = 0; x < w; ++x) {
				++best;
				if(type[x][y] == v) // if this cell is of type v
					best = min(best, dp[x][y]);
				for(int he : col[x]) // update cells of type v+1
					dp[x][he] = min(dp[x][he], best + abs(he - y));
			}
			// from right to left, copypaste
			best = inf;
			for(int x = w - 1; x >= 0; --x) {
				++best;
				if(type[x][y] == v)
					best = min(best, dp[x][y]);
				for(int he : col[x])
					dp[x][he] = min(dp[x][he], best + abs(he - y));
			}
		}
	}
	for(int x = 0; x < w; ++x)
		for(int y = 0; y < h; ++y)
			if(type[x][y] == p)
				printf("%d\n", dp[x][y]);
	return 0;
}