#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int ,int> pii;

int n;
vi v[111111];
double ans;

void dfs(int node, int d, int p) {
	ans+=1.0/d;
	for (int i=0; i<(int)v[node].size(); i++) if (v[node][i]!=p) dfs(v[node][i], d+1, node);
}

int main() {
	cin >> n;
	for (int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b), v[b].pb(a);
	}
	dfs(1, 1, 0);
	cout << fixed << setprecision(10) << ans;
}