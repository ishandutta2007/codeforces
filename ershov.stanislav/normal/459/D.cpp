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

#ifdef ONLINE_JUDGE
const int maxn=111111;
#else
const int maxn=111;
#endif

map<int, int> m1, m2;
int n, a[1111111], res1[1111111], res2[1111111], fenv[1111111];
long long ans;

void add(int i, int d) {
	for (; i<1100000; i|=(i+1)) fenv[i]+=d;
}

int get(int i) {
	int ans=0;
	for (; i>=0; i=(i&(i+1))-1) ans+=fenv[i];
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n;
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=0; i<n; i++) res1[i]=++m1[a[i]];
	for (int i=n-1; i>=0; i--) res2[i]=++m2[a[i]];
	for (int i=n-2; i>=0; i--) {
		add(res2[i+1], 1);
		ans+=get(res1[i]-1);
	}
	cout << ans;
	return 0;
}