#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define endl '\n'
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

typedef pair<pair<pii, pii>, pii> piiiiii;
string arr[120];
vector<piiiiii> ans;

inline void flp(int y1, int x1, int y2, int x2, int y3, int x3){
	ans.push_back({ { {y1+1, x1+1}, {y2+1, x2+1} }, {y3+1, x3+1} });
	arr[y1][x1] ^= 1;
	arr[y2][x2] ^= 1;
	arr[y3][x3] ^= 1;
}

void Main(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}
		if ((n&1) && (m&1)){
			if (arr[n-1][m-1] == '1'){
				flp(n-1, m-1, n-2, m-1, n-1, m-2);
			}
		}
		if (n&1){
			for (int i = 0; i < m-1; i += 2){
				bool c1 = arr[n-1][i] == '1', c2 = arr[n-1][i+1] == '1';
				if (c1 && c2) flp(n-1, i, n-1, i+1, n-2, i);
				else if (c1) flp(n-1, i, n-2, i, n-2, i+1);
				else if (c2) flp(n-1, i+1, n-2, i, n-2, i+1);
			}
		}
		if (m&1){
			for (int i = 0; i < n-1; i += 2){
				bool c1 = arr[i][m-1] == '1', c2 = arr[i+1][m-1] == '1';
				if (c1 && c2) flp(i, m-1, i+1, m-1, i, m-2);
				else if (c1) flp(i, m-1, i, m-2, i+1, m-2);
				else if (c2) flp(i+1, m-1, i, m-2, i+1, m-2);
			}
		}
		for (int i = 0; i < n-1; i += 2){
			for (int j = 0; j < m-1; j += 2){
				bool c1 = arr[i][j] == '1', c2 = arr[i][j+1] == '1';
				bool c3 = arr[i+1][j] == '1', c4 = arr[i+1][j+1] == '1';
				if (c2^c3^c4){
					flp(i, j+1, i+1, j, i+1, j+1);
				}
				if (c1^c3^c4){
					flp(i, j, i+1, j, i+1, j+1);
				}
				if (c1^c2^c4){
					flp(i, j, i, j+1, i+1, j+1);
				}
				if (c1^c2^c3){
					flp(i, j, i, j+1, i+1, j);
				}
			}
		}
		cout << ans.size() << endl;
		for (auto p : ans){
			cout << p.fr.fr.fr << ' ' << p.fr.fr.sc << ' ' << p.fr.sc.fr << ' ' << p.fr.sc.sc << ' ' << p.sc.fr << ' ' << p.sc.sc << endl;
		}
		//for (int i = 0; i < n; i++) cout << arr[i] << endl;
		ans.clear();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(15);
	Main();
}