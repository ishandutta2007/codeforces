#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

//#define DEBUG

string mp[60];
bool chk[60][60];
queue<pii> q;

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++){ cin >> mp[i]; }
		bool ans = 1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (mp[i][j] == 'B'){
					for (int k = 0; k < 4; k++){
						int y = i+dy[k], x = j+dx[k];
						if (0 > y || y >= n || 0 > x || x >= m){ continue; }
						if (mp[y][x] == 'B'){ continue; }
						if (mp[y][x] == 'G'){ cout << "No"; goto done; }
						mp[y][x] = '#';
					}
				}
			}
		}
		if (mp[n-1][m-1] == '#'){ goto done2; }
		q.push({n-1, m-1}); chk[n-1][m-1] = 1;
		while (!q.empty()){
			int y = q.front().fr, x = q.front().sc;
			q.pop();
			for (int k = 0; k < 4; k++){
				int yy = y+dy[k], xx = x+dx[k];
				if (0 > yy || yy >= n || 0 > xx || xx >= m){ continue; }
				if (chk[yy][xx]){ continue; }
				if (mp[yy][xx] == '#'){ continue; }
				q.push({yy, xx}); chk[yy][xx] = 1;
			}
		}
		done2:
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (mp[i][j] == 'G'){ ans &= chk[i][j]; }
			}
		}
		if (ans){ cout << "Yes"; }
		else{ cout << "No"; }
		done: cout << endl;
		memset(chk, 0, sizeof(chk));
		while (!q.empty()){ q.pop(); }
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