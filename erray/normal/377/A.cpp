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
#define N 505
using namespace std;	
typedef long long ll;
typedef pair<int ,int > pp;
typedef vector<ll> vi;
int n ,m ,k, mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};
char mat[N][N], c;
pp start;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m >> k;
	int count = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> c;
			mat[i][j] = (c == '.' ? 'X' : '#');
			if(c == '.') {start = mp(i, j); count++;}
		}
	}	
	queue<pp> q;
	map <pp, bool> vis; 
	q.push(start);
	k = count - k;
	while(k-- && !q.empty()){
		int x = q.front().st, y = q.front().nd;
		vis[mp(x ,y )] = 1;
		mat[x][y] = '.';
		//cout << x << " " << y << ln;
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + mx[i], ny = y + my[i];
			if(nx == 2 && ny == 1){
				//cout << "asd" << ln;
				//cout << vis[mp(nx, ny)] << " " << mat[nx][ny] << ln;
			}
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[mp(nx, ny)] && mat[nx][ny] == 'X'){
				q.push(mp(nx, ny));
				vis[mp(nx, ny)] = 1;
			}
		}	
	} 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << mat[i][j];
		}
		cout << ln;
	}
	return 0;	 
}