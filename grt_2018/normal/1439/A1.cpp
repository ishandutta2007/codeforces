#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

struct Triple {
	pi a,b,c;
};

int t,n,m;
const int nax = 110;
string s[nax];
bool w[nax][nax];
vector<Triple>ans;

void zrob(vector<pi>a) {
	vector<pi>tmp = {};
	vector<pi>tmp2 = {};
	for(auto x : a) {
		if(w[x.ST][x.ND]) tmp.PB(x);
		else tmp2.PB(x);
	}
	//cout << a[0].ST << " " << a[0].ND << ": " << (int)tmp.size() << "\n";
	if((int)tmp.size() == 0) return;
	if((int)tmp.size() == 1) {
		Triple r = {tmp[0], tmp2[1], tmp2[2]};
		ans.PB(r);
		for(int i = 1; i < 3; ++i) {
			w[tmp2[i].ST][tmp2[i].ND] ^= 1;
		}
		w[tmp[0].ST][tmp[0].ND] ^= 1;
		return;
	}
	if((int)tmp.size() == 4) {
		Triple r = {tmp[0], tmp[1], tmp[2]};
		ans.PB(r);
		for(int i = 0; i < 3; ++i) {
			w[tmp[i].ST][tmp[i].ND] ^= 1;
		}
		return;
	}
	if((int)tmp.size() == 2) {
		Triple r = {tmp2[0], tmp2[1], tmp[0]};
		ans.PB(r);
		w[tmp2[0].ST][tmp2[0].ND] ^= 1;
		w[tmp2[1].ST][tmp2[1].ND] ^= 1;
		w[tmp[0].ST][tmp[0].ND] ^= 1;
		return;
	}
	if((int)tmp.size() == 3) {
		Triple r = {tmp[0], tmp[1], tmp[2]};
		ans.PB(r);
		for(int i = 0; i < 3; ++i) {
			w[tmp[i].ST][tmp[i].ND] ^= 1;
		}
	}
}

void solve() {
	cin >> n >> m;
	ans = {};
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		for(int j = 0; j < m; ++j) w[i][j] = s[i][j] - '0';
	}
	//for(int i =0; i < n; ++i) {
		//for(int j = 0; j < m; ++j) {
			//cout << w[i][j];
		//}
		//cout << "\n";
	//}
	for(int i = 0; i < n - 2; ++i) {
		for(int j = 0; j < m - 1; ++j) {
			if(w[i][j]) {
				if(w[i][j + 1]) {
					ans.PB({{i,j}, {i+1, j}, {i, j + 1}});
					w[i][j] ^= 1;
					w[i+1][j] ^= 1;
					w[i][j+1] ^= 1;
				} else {
					ans.PB({{i,j},{i+1,j},{i+1,j+1}});
					w[i][j] ^= 1;
					w[i+1][j] ^= 1;
					w[i +1][j+1] ^= 1;
				}
			} else {
				if(w[i][j + 1]) {
					ans.PB({{i+1,j+1}, {i+1, j}, {i, j + 1}});
					w[i+1][j+1] ^= 1;
					w[i+1][j] ^= 1;
					w[i][j+1] ^= 1;
				}
			}
		}
	}
	for(int i = 0; i < m - 1; i += 2) {
		for(int j = 0; j <= 3; ++j) zrob({{n-1,i},{n-2,i},{n-1,i+1},{n-2,i+1}});
	}
	for(int i = 0; i <= 3; ++i) zrob({{n - 1, m-2},{n-2,m-1},{n-1,m-1},{n-2,m-2}});
	cout << (int)ans.size() << "\n";
	for(auto x : ans) {
		cout << x.a.ST+1 << " " << x.a.ND+1 << " " << x.b.ST+1 << " " << x.b.ND +1<< " " << x.c.ST+1 << " " << x.c.ND +1<< "\n";
	}
	//for(int i =0; i < n; ++i) {
		//for(int j = 0; j < m; ++j) {
			//cout << w[i][j];
		//}
		//cout << "\n";
	//}
}
	

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		solve();
	}
	
}