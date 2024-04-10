#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

long long n, m, k, ans;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> m >> k;
	if (n<m) swap(n, m);
	ans=max(n/(k+1)*m, m/(k+1)*n);
	if (n<k+1) ans=max(ans, m/(k+2-n));
	if (m<k+1) ans=max(ans, n/(k+2-m));
	if (ans==0) ans=-1;
	cout << ans;
    return 0;
}