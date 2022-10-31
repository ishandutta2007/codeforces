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

using namespace std;

#ifdef ONLINE_JUDGE
const int maxn=111111;
#else
const int maxn=111;
#endif

int n, m, a1[111111], a2[111111];
long long sum1, sum2, ans=1000000000000000000;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	scanf("%d%d", &m, &n);
	for (int i=0; i<m; i++) scanf("%d", &a1[i]), sum1+=a1[i];
	for (int i=0; i<n; i++) scanf("%d", &a2[i]), sum2+=a2[i];
	sort(a1, a1+m);
	sort(a2, a2+n);
	long long sum=0;
	for (int i=0; i<n; i++) {
		if ((2*100000ll*1000000000ll)/(n-i)>=sum1) ans=min(ans, sum1*(n-i)+sum);
		sum+=a2[i];
	}
	sum=0;
	for (int i=0; i<m; i++) {
		if ((2*100000ll*1000000000ll)/(m-i)>=sum2) ans=min(ans, sum2*(m-i)+sum);
		sum+=a1[i];
	}
	cout << ans;
	return 0;
}