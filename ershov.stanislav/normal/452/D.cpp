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

int k, n1, n2, n3, t1, t2, t3, a[15000000], cur;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
	cur=t1+t2+t3;
	for (int i=0, c1=1, c2=1, c3=1; i<k; i++) {
		while (c1>n1||c2>n2||c3>n3) {
			cur++;
			c1-=a[cur-t1];
			c2-=a[cur-t2];
			c3-=a[cur-t3];
		}
		c1++, c2++, c3++;
		a[cur]++;
	}
	cout << cur;
	return 0;
}