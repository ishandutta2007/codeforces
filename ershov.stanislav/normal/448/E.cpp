#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

long long n, k;

vector<long long> ndiv, ans;

void dfs(long long i, int cnt) {
	if (i==1) {
		ans.push_back(1);
		return;
	}
	if (ans.size()>=100000) return;
	if (cnt==k) ans.push_back(i);
	else for (int j=0; j<ndiv.size()&&ndiv[j]<=i&&ans.size()<100000; j++) if (!(i%ndiv[j])) dfs(ndiv[j], cnt+1);
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> k;
	for (long long i=1; i*i<=n; i++) {
		if (!(n%i)) ndiv.push_back(i);
	}
	for (long long i=ndiv.size()-1; i>=0; i--) {
		if (ndiv[i]*ndiv[i]!=n) ndiv.push_back(n/ndiv[i]);
	}
	if (k>=100000&&n>1) for (int i=0; i<100000; i++) ans.push_back(1);
	if (k>=100000&&n==1) ans.push_back(1);
	else dfs(n, 0);
	for (int i=0; i<ans.size(); i++) cout << ans[i] << ' ';
    return 0;
}