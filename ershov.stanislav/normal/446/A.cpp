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

int n, a[111111], ans=1;

int main() {
	//freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=1, prev1=0, prev2=0; i<n; i++) {
		if (a[i]<=a[i-1]) {
			prev2=prev1+1;
			if (a[prev2]>a[prev2-1]) prev2--;
			prev1=i-1;
		}
		ans=max(ans, i-prev1+1);
		if (prev1==i-1||a[prev1+2]>=a[prev1]+2||(prev1>=1&&a[prev1-1]<=a[prev1+1]-2)) ans=max(ans, i-prev2+1);
	}
	cout << ans;
    return 0;
}