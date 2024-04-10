#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

string mp[120];
pi2 dp[120][120];
bool chk[120][120];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++){ cin >> mp[i]; }
		bool ans = 1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (mp[i][j] == '0'){ continue; }
				if (chk[i][j]){ continue; }
				int y = i, x = j;
				while (y < n){ if (mp[y][j] == '1'){ y += 1; } else{ break; } }
				while (x < m){ if (mp[i][x] == '1'){ x += 1; } else{ break; } }
				//cout << i <<' ' << j << "   " << y << ' ' << x << endl;
				for (int yy = i; yy < y; yy++){
					for (int xx = j; xx < x; xx++){
						chk[yy][xx] = 1;
						if (mp[yy][xx] == '0'){ ans = 0; }
					}
				}
				for (int yy = i; yy < y; yy++){
					if (j != 0){ if (mp[yy][j-1] == '1'){ ans = 0; } }
					if (x != m){ if (mp[yy][x] == '1'){ ans = 0; } }
				}
				for (int xx = j; xx < x; xx++){
					if (i != 0){ if (mp[i-1][xx] == '1'){ ans = 0; } }
					if (y != n){ if (mp[y][xx] == '1'){ ans = 0; } }
				}
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){ chk[i][j] = 0; }
		}
		if (ans){ cout << "Yes" << endl; }
		else{ cout << "No" << endl; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}