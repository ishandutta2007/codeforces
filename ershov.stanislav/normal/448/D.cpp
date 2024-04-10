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

#ifdef ONLINE_JUDGE
const int maxn=111111;
#else
const int maxn=100;
#endif

long long n, m, k;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> m >> k;
	if (n<m) swap(n, m);
	long long l=1, r=1000000000000000;
	while (l<r) {
		long long mid=(l+r)/2;
		long long a=0;
		for (long long i=1; i<=m; i++) {
			a+=min(n, mid/i);
		}
		if (a<k) l=mid+1;
		else r=mid;
	}
	cout << l;
    return 0;
}