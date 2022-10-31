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

int l[10], c[20], b;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	for (int i=0; i<6; i++) cin >> l[i], c[l[i]]++;
	for (int i=1; i<=9; i++) if (c[i]>=4) b=i;
	if (!b) cout << "Alien";
	else {
		c[b]-=4;
		for (int i=1; i<=9; i++) if (c[i]==2) {
			cout << "Elephant";
			return 0;
		}
		cout << "Bear";
	}
	return 0;
}