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
#define bnt(x) __builtin_popcount(x)

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
typedef pair<pi2, int> pi3;

// #define DEBUG

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		vector< vector<int> > arr;
		arr.resize(n);
		for (vector<int>& v : arr){ v.resize(m); }
		queue<pi3> q;
		q.push({ {0, 0}, 1 }); arr[0][0] = 1;
		q.push({ {0, m-1}, 1 }); arr[0][m-1] = 1;
		q.push({ {n-1, 0}, 1 }); arr[n-1][0] = 1;
		q.push({ {n-1, m-1}, 1 }); arr[n-1][m-1] = 1;
		while (!q.empty()){
			int y = q.front().fr.fr, x = q.front().fr.sc;
			int d = q.front().sc; q.pop();
			for (int k = 0; k < 4; k++){
				int yy = y+dy[k], xx = x+dx[k];
				if (0 > yy || yy >= n){ continue; }
				if (0 > xx || xx >= m){ continue; }
				if (arr[yy][xx] != 0){ continue; }
				arr[yy][xx] = d+1; q.push({ {yy, xx}, d+1 });
			}
		}
		vector<int> res;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				res.push_back(arr[i][j]);
			}
		}
		sort(all(res), [](int a, int b){ return a > b; });
		int dst = n-1 + m-1;
		for (int x : res){ cout << dst+1 - x << ' '; }
		cout << endl;
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