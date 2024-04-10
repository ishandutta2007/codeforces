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

int n, a[111111];
long long b[111111];
long long c1[111111], c2[111111];

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) b[a[i]]+=a[i];
	for (int i=1; i<111111; i++) c1[i]=b[i]+c2[i-1], c2[i]=max(c1[i-1], c2[i-1]);
	cout << max(c1[100111], c2[100111]);
	return 0;
}