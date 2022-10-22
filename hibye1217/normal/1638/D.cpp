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

typedef pair<pi2, int> pi3;
int arr[1020][1020];
stack<pi3> ans;

int f(int i, int j){
	int val = 0; bool flg = 1;
	for (int di = 0; di <= 1; di++){
		for (int dj = 0; dj <= 1; dj++){
			val = max(val, arr[i+di][j+dj]);
		}
	}
	if (val == 0){ return 0; }
	for (int di = 0; di <= 1; di++){
		for (int dj = 0; dj <= 1; dj++){
			if (arr[i+di][j+dj] == 0 || arr[i+di][j+dj] == val){}
			else{ flg = 0; }
		}
	}
	if (flg){
		for (int di = 0; di <= 1; di++){
			for (int dj = 0; dj <= 1; dj++){
				arr[i+di][j+dj] = 0;
			}
		}
		return val;
	}
	else{ return 0; }
}

void Main(){
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}
	queue<pi2> q;
	for (int i = 1; i < n; i++){
		for (int j = 1; j < m; j++){
			int res = f(i, j);
			if (res != 0){
				q.push({i, j});
				ans.push({ {i, j}, res });
			}
		}
	}
	while (!q.empty()){
		pi2 p = q.front(); q.pop();
		for (int dy = -1; dy <= 1; dy++){
			for (int dx = -1; dx <= 1; dx++){
				int y = p.fr-dy, x = p.sc-dx;
				if (1 > y || y >= n){ continue; }
				if (1 > x || x >= m){ continue; }
				int res = f(y, x);
				if (res != 0){
					q.push({y, x});
					ans.push({ {y, x}, res });
				}
			}
		}
	}
	bool flg = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (arr[i][j] != 0){ flg = 0; }
		}
	}
	if (!flg){ cout << -1; return; }
	cout << ans.size() << endl;
	while (!ans.empty()){
		pi3 p = ans.top(); ans.pop();
		cout << p.fr.fr << ' ' << p.fr.sc << ' ' << p.sc << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}