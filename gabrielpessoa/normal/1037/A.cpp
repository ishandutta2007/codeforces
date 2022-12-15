#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

const int ms = 2e5+5;
const ll mod = 1e9+7;

set<int> g[ms];
int n;
queue<int> q;
int vis[ms];
int a[ms];

int main() {
    int n;
	cin >> n;
	int ans = 0;
	while(n > 0) {
		ans++;
		n = n >> 1;
	}
	cout << ans << '\n';
}