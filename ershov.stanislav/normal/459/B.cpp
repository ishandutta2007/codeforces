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

int n, b[222222], minb=2000000000, maxb;
long long cntmin, cntmax;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n;
	for (int i=0; i<n; i++) cin >> b[i];
	for (int i=0; i<n; i++) minb=min(minb, b[i]), maxb=max(maxb, b[i]);
	for (int i=0; i<n; i++) if (b[i]==minb) cntmin++;
	for (int i=0; i<n; i++) if (b[i]==maxb) cntmax++;
	if (minb!=maxb) cout << maxb-minb << ' ' << cntmin*cntmax;
	else cout << maxb-minb << ' ' << cntmin*(cntmin-1)/2;
	return 0;
}