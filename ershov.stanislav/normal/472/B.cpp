#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

vector<int> f;
int n, k;
long long ans;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		f.push_back(a);
	}
	sort(f.begin(), f.end());
	reverse(f.begin(), f.end());
	for (int i=0; i<n; i+=k) ans+=2*(f[i]-1);
	cout << ans;
	return 0;
}