#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 50 * 1000 + 10;
int t, n;
int inv[5][nax];

bool win(int a, int b) {
	int cnt = 0;
	for(int i = 0; i < 5; ++i) {
		if(inv[i][a] < inv[i][b]) cnt++;
	}
	return cnt >= 3;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < 5; ++j) {
				cin >> inv[j][i];
			}
		}
		int a = 1;
		for(int i = 2; i <= n; ++i) {
			if(win(i, a)) a = i;
		}
		bool ok = true;
		for(int i = 1; i <= n; ++i) {
			if(i == a) continue;
			if(!win(a, i)) ok = false;
		}
		if(!ok) cout << "-1\n";
		else cout << a << "\n";
	}
}