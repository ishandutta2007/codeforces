#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair

long long n, a[222222], y[222222][2];

long long dfs(int v, bool p) {
	if (y[v][p]!=0) return y[v][p];
	else {
		y[v][p]=-1;
		int vv=v+(p?a[v]:-a[v]);
		if (vv>=0&&vv<n-1) {
			long long k=dfs(vv, p^1);
			if (k>=0) return y[v][p]=k+a[v];
			else return -1;
		} else if (vv==-1) return y[v][p]=-1;
		else return y[v][p]=a[v];
	}
}

int main() {
	cin >> n;
	for (int i=0; i<n-1; i++) cin >> a[i];
	for (int i=0; i<n-1; i++) {
		long long k=dfs(i, 0);
		if (k>=0) cout << k+i+1 << endl;
		else cout << -1 << endl;
	}
}