#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

const int nax = 200 * 1000 + 10;
int n, m;
ll a[nax], b[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	ll g = 0;
	for(int i = 2; i <= n; ++i) {
		g = __gcd(g, a[i - 1] - a[i]);
	}
	if(g < 0) g = -g;
	for(int i = 1; i <= m; ++i) {
		cout << __gcd(g, a[n] + b[i]) << " ";
	}
	
}