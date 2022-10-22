//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10;
int n;
string s;
bool good[nax];
int cnt[nax];

void consider(int x) {
	for(int i = 0; i < x; ++i) cnt[i] = 0;
	for(int i = 0; i < n; ++i) {
		cnt[i % x] += s[i] - '0';
	}
	bool ok = true;
	for(int i = 0; i < x; ++i) {
		if(cnt[i] & 1) {
			ok = false;
		}
	}
	good[x] = ok;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for(int g = 1; g * g <= n; ++g) {
		if(n % g == 0) {
			consider(g);
			if(g * g != n) {
				consider(n / g);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int g = gcd(i, n);
		if(good[g]) ans++;
	}
	cout << ans;
}