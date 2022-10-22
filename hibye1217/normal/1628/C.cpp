#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

ll arr[1020][1020];
bool chk[1020][1020], res[1020][1020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				cin >> arr[i][j];
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if ( (i+j)%2 == 0 ){ continue; }
				bool flg = 1;
				for (int k = 0; k < 4; k++){
					int y = i+dy[k], x = j+dx[k];
					if (chk[y][x]){ flg = 0; }
				}
				if (flg){
					res[i][j] = 1;
					for (int k = 0; k < 4; k++){
						int y = i+dy[k], x = j+dx[k];
						chk[y][x] = 1;
					}
				}
			}
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (res[i][j] || res[i][n+1-j]){ ans ^= arr[i][j]; }
				//if (res[i][j]){ cout << '#'; }
				//else{ cout << '.'; }
			}
			//cout << endl;
		}
		cout << ans << endl;
		for (int i = 0; i <= n+1; i++){
			for (int j = 0; j <= n+1; j++){
				chk[i][j] = res[i][j] = 0;
			}
		}
	}
}

//#define DEBUG
int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}