#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 105;
const int MOD = 1E6;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 8e-5;
const int INF = 0x3f3f3f3f;

vii g[SIZE];
int pd[SIZE][SIZE][30];

int get_pd(int i, int j, int let) {
	if(~pd[i][j][let]) return pd[i][j][let];
	for(ii a : g[i]) {
		if(a.second >= let && !get_pd(j, a.first, a.second)) {
			return pd[i][j][let] = 1;
		}
	}
	return pd[i][j][let] = 0;
}

int main() {
	int n, m;
	cin >> n >> m;
	while(m--) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		g[a-1].push_back(ii(b-1, c - 'a'));
	}

	memset(pd, -1, sizeof(pd));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(get_pd(i, j, 0)) {
				cout << 'A';
			} else {
				cout << 'B';
			}
		}
		cout << '\n';
	}	
	return 0;
}