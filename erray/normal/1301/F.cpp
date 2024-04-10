#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first 
#define nd second 
#define ln "\n"
#define MAX 1000000009
#define MOD 1000000007
#define N 1001
using namespace std;
typedef long long ll;
typedef pair<int ,int > pp;
typedef vector<ll> vi;
int n, m, qu, k, x, y, nx, ny, tx, ty, mat[N][N], best[N][N][41],moveX[4] = {1, -1, 0, 0}, moveY[4] = {0, 0, 1, -1};
vector <pp>  cells[40];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	memset(best, -1, sizeof best);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> mat[i][j];
			cells[mat[i][j]].pb(mp(i, j));
		}
	}
	
	queue <	pp> q; 
	for(int i = 1; i <= k; i++){
		umap <int, bool> vis; 
		for(auto a : cells[i]){
			q.push(a);
			//cout << a.st << " " << a.nd << ln;
			best[a.st][a.nd][i] = 0;
		} 
		while(!q.empty()){
			int mx = q.front().st, my = q.front().nd;
			//cout << mx << " " << my << ln;
			q.pop();
			if(!vis[mat[mx][my]]){
				vis[mat[mx][my]] = 1;
				for(auto a : cells[mat[mx][my]]){	
					if(best[a.st][a.nd][i] == -1){
						q.push(a);
						best[a.st][a.nd][i] = best[mx][my][i] + 1;
					}
				}
			}
			
			for(int  ii = 0; ii < 4; ii++){
				int newX = mx + moveX[ii], newY = my + moveY[ii];
				if(newX <= n && newX >= 1 && newY >= 1 && newY <= m && best[newX][newY][i] == -1){
					q.push(mp(newX, newY));
					best[newX][newY][i] = best[mx][my][i] + 1;
				}
			}
			
			
		}
		/*
		for(int ai = 1; ai <= n; ai++){
			for(int aj = 1; aj <= m; aj++){
				cout << best[ai][aj][i] << " ";
			}
			cout << ln;
		}
		cout << ln;
		//cout << "bum" << ln;
		*/
	}
	cin >> qu;
	while(qu--){
		cin >> nx >> ny >> tx >> ty;
		int ans = abs(nx - tx) + abs(ny - ty);
		for(int i = 1; i <= k; i++){
			//cout << best[nx][ny][i] << " " << best[tx][ty][i] << ln;
			ans = min(ans, best[nx][ny][i] + best[tx][ty][i] + 1);
		}
		cout << ans << ln;
	}

	return 0;	 
}