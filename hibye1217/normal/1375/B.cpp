#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define fr first
#define sc second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int mp[320][320];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		int n, m;
		bool ans = true;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> mp[i][j];
		bool chk = true;
		while (chk){
			chk = false;
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= m; j++){
					if (mp[i][j] == 0) continue;
					int c = 0;
					for (int k = 0; k < 4; k++){
						int X = j + dx[k], Y = i + dy[k];
						if (1 > X || X > m || 1 > Y || Y > n) continue;
						if (mp[Y][X] != 0) c += 1;
					}
					if (mp[i][j] == c) continue;
					chk = true;
					if (mp[i][j] < c){ mp[i][j] = c; }
					else{
						for (int k = 0; k < 4; k++){
							if (mp[i][j] == c) break;
							int X = j + dx[k], Y = i + dy[k];
							if (1 > X || X > m || 1 > Y || Y > n) continue;
							if (mp[Y][X] == 0){
								mp[Y][X] += 1;
								c += 1;
							}
						}
					}
					if (mp[i][j] != c){
						cout << "NO" << endl;
						goto done;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (mp[i][j] == 0) continue;
				int c = 0;
				for (int k = 0; k < 4; k++){
					int X = j + dx[k], Y = i + dy[k];
					if (1 > X || X > m || 1 > Y || Y > n) continue;
					if (mp[Y][X] != 0) c += 1;
				}
				ans = ans && mp[i][j] == c;
			}
		}
		cout << (ans ? "YES" : "NO") << endl;
		if (ans){
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= m; j++) cout << mp[i][j] << ' ';
				cout << endl;
			}
		}
		done: ;
	}
}